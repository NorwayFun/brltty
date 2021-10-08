/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2021 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU Lesser General Public License, as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at your option) any
 * later version. Please see the file LICENSE-LGPL for details.
 *
 * Web Page: http://brltty.app/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include <stdio.h>

#include "program.h"
#include "options.h"
#include "log.h"
#include "io_hid.h"
#include "hid_items.h"

static char *opt_manufacturerName;
static char *opt_productDescription;
static char *opt_serialNumber;
static char *opt_vendorIdentifier;
static char *opt_productIdentifier;
static int opt_listItems;

BEGIN_OPTION_TABLE(programOptions)
  { .word = "manufacturer-name",
    .letter = 'm',
    .argument = strtext("string"),
    .setting.string = &opt_manufacturerName,
    .description = strtext("The name of the device's manufacturer.")
  },

  { .word = "product-description",
    .letter = 'd',
    .argument = strtext("string"),
    .setting.string = &opt_productDescription,
    .description = strtext("The device's product description.")
  },

  { .word = "serial-number",
    .letter = 's',
    .argument = strtext("string"),
    .setting.string = &opt_serialNumber,
    .description = strtext("The device's serial number.")
  },

  { .word = "vendor-identifier",
    .letter = 'v',
    .argument = strtext("hex"),
    .setting.string = &opt_vendorIdentifier,
    .description = strtext("The device's vendor identifier.")
  },

  { .word = "product-identifier",
    .letter = 'p',
    .argument = strtext("hex"),
    .setting.string = &opt_productIdentifier,
    .description = strtext("The device's product identifier.")
  },

  { .word = "list-items",
    .letter = 'l',
    .setting.flag = &opt_listItems,
    .description = strtext("List the report descriptor.")
  },
END_OPTION_TABLE

static int
listItem (const char *line, void *data) {
  FILE *stream = stdout;
  fprintf(stream, "%s\n", line);
  if (!ferror(stream)) return 1;

  logSystemError("output");
  return 0;
}

int
main (int argc, char *argv[]) {
  {
    static const OptionsDescriptor descriptor = {
      OPTION_TABLE(programOptions),
      .applicationName = "hidtest",
    };

    PROCESS_OPTIONS(descriptor, argc, argv);
  }

  if (argc) {
    logMessage(LOG_ERR, "too many parameters");
    return PROG_EXIT_SYNTAX;
  }

  HidDeviceFilter_USB filter;
  hidInitializeDeviceFilter_USB(&filter);

  filter.manufacturerName = opt_manufacturerName;
  filter.productDescription = opt_productDescription;
  filter.serialNumber = opt_serialNumber;

  {
    int ok = 1;

    if (*opt_vendorIdentifier) {
      if (!hidParseIdentifier(&filter.vendorIdentifier, opt_vendorIdentifier)) {
        logMessage(LOG_ERR, "invalid vendor identifier: %s", opt_vendorIdentifier);
        ok = 0;
      }
    }

    if (*opt_productIdentifier) {
      if (!hidParseIdentifier(&filter.productIdentifier, opt_productIdentifier)) {
        logMessage(LOG_ERR, "invalid product identifier: %s", opt_productIdentifier);
        ok = 0;
      }
    }

    if (!ok) return PROG_EXIT_SYNTAX;
  }

  HidDevice *device = hidOpenDevice_USB(&filter);
  if (!device) {
    logMessage(LOG_ERR, "device not found");
    return PROG_EXIT_SEMANTIC;
  }

  if (opt_listItems) {
    HidItemsDescriptor *items = hidGetItems(device);

    if (!items) {
      logMessage(LOG_ERR, "descriptor not found");
      return PROG_EXIT_FATAL;
    } 

    int wasListed = hidListItems(items, listItem, NULL);
    free(items);
    if (!wasListed) return PROG_EXIT_FATAL;
  }

  hidCloseDevice(device);
  return PROG_EXIT_SUCCESS;
}