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

#ifndef BRLTTY_INCLUDED_HID_DEFS
#define BRLTTY_INCLUDED_HID_DEFS

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
  HID_ITM_UsagePage         = 0X04,
  HID_ITM_Usage             = 0X08,
  HID_ITM_LogicalMinimum    = 0X14,
  HID_ITM_UsageMinimum      = 0X18,
  HID_ITM_LogicalMaximum    = 0X24,
  HID_ITM_UsageMaximum      = 0X28,
  HID_ITM_PhysicalMinimum   = 0X34,
  HID_ITM_DesignatorIndex   = 0X38,
  HID_ITM_PhysicalMaximum   = 0X44,
  HID_ITM_DesignatorMinimum = 0X48,
  HID_ITM_UnitExponent      = 0X54,
  HID_ITM_DesignatorMaximum = 0X58,
  HID_ITM_Unit              = 0X64,
  HID_ITM_ReportSize        = 0X74,
  HID_ITM_StringIndex       = 0X78,
  HID_ITM_Input             = 0X80,
  HID_ITM_ReportID          = 0X84,
  HID_ITM_StringMinimum     = 0X88,
  HID_ITM_Output            = 0X90,
  HID_ITM_ReportCount       = 0X94,
  HID_ITM_StringMaximum     = 0X98,
  HID_ITM_Collection        = 0XA0,
  HID_ITM_Push              = 0XA4,
  HID_ITM_Delimiter         = 0XA8,
  HID_ITM_Feature           = 0XB0,
  HID_ITM_Pop               = 0XB4,
  HID_ITM_EndCollection     = 0XC0,

  HID_ITEM_TYPE_MASK        = 0XFC
} HidItemType;

static inline int
hidHasSignedValue (HidItemType type) {
  switch (type) {
    case HID_ITM_LogicalMinimum:
    case HID_ITM_LogicalMaximum:
    case HID_ITM_PhysicalMinimum:
    case HID_ITM_PhysicalMaximum:
    case HID_ITM_UnitExponent:
      return 1;

    default:
      return 0;
  }
}

#define HID_ITEM_TYPE(item) ((item) & HID_ITEM_TYPE_MASK)
#define HID_ITEM_LENGTH(item) ((item) & ~HID_ITEM_TYPE_MASK)
#define HID_ITEM_BIT(type) (UINT64_C(1) << ((type) >> 2))

typedef enum {
  HID_COL_Physical    = 0X00,
  HID_COL_Application = 0X01,
  HID_COL_Logical     = 0X02,
} HidCollectionType;

typedef enum {
  HID_USG_GDT_Pointer                   = 0X01,
  HID_USG_GDT_Mouse                     = 0X02,
  HID_USG_GDT_Joystick                  = 0X04,
  HID_USG_GDT_GamePad                   = 0X05,
  HID_USG_GDT_Keyboard                  = 0X06,
  HID_USG_GDT_Keypad                    = 0X07,
  HID_USG_GDT_MultiAxisController       = 0X08,
  HID_USG_GDT_TabletPCSystemControls    = 0X09,
  HID_USG_GDT_X                         = 0X30,
  HID_USG_GDT_Y                         = 0X31,
  HID_USG_GDT_Z                         = 0X32,
  HID_USG_GDT_Rx                        = 0X33,
  HID_USG_GDT_Ry                        = 0X34,
  HID_USG_GDT_Rz                        = 0X35,
  HID_USG_GDT_Slider                    = 0X36,
  HID_USG_GDT_Dial                      = 0X37,
  HID_USG_GDT_Wheel                     = 0X38,
  HID_USG_GDT_HatSwitch                 = 0X39,
  HID_USG_GDT_CountedBuffer             = 0X3A,
  HID_USG_GDT_ByteCount                 = 0X3B,
  HID_USG_GDT_MotionWakeup              = 0X3C,
  HID_USG_GDT_Start                     = 0X3D,
  HID_USG_GDT_Select                    = 0X3E,
  HID_USG_GDT_Vx                        = 0X40,
  HID_USG_GDT_Vy                        = 0X41,
  HID_USG_GDT_Vz                        = 0X42,
  HID_USG_GDT_Vbrx                      = 0X43,
  HID_USG_GDT_Vbry                      = 0X44,
  HID_USG_GDT_Vbrz                      = 0X45,
  HID_USG_GDT_Vno                       = 0X46,
  HID_USG_GDT_FeatureNotification       = 0X47,
  HID_USG_GDT_ResolutionMultiplier      = 0X48,
  HID_USG_GDT_SystemControl             = 0X80,
  HID_USG_GDT_SystemPowerDown           = 0X81,
  HID_USG_GDT_SystemSleep               = 0X82,
  HID_USG_GDT_SystemWakeUp              = 0X83,
  HID_USG_GDT_SystemContextMenu         = 0X84,
  HID_USG_GDT_SystemMainMenu            = 0X85,
  HID_USG_GDT_SystemAppMenu             = 0X86,
  HID_USG_GDT_SystemMenuHelp            = 0X87,
  HID_USG_GDT_SystemMenuExit            = 0X88,
  HID_USG_GDT_SystemMenuSelect          = 0X89,
  HID_USG_GDT_SystemMenuRight           = 0X8A,
  HID_USG_GDT_SystemMenuLeft            = 0X8B,
  HID_USG_GDT_SystemMenuUp              = 0X8C,
  HID_USG_GDT_SystemMenuDown            = 0X8D,
  HID_USG_GDT_SystemColdRestart         = 0X8E,
  HID_USG_GDT_SystemWarmRestart         = 0X8F,
  HID_USG_GDT_DPadUp                    = 0X90,
  HID_USG_GDT_DPadDown                  = 0X91,
  HID_USG_GDT_DPadRight                 = 0X92,
  HID_USG_GDT_DPadLeft                  = 0X93,
  HID_USG_GDT_SystemDock                = 0XA0,
  HID_USG_GDT_SystemUndock              = 0XA1,
  HID_USG_GDT_SystemSetup               = 0XA2,
  HID_USG_GDT_SystemBreak               = 0XA3,
  HID_USG_GDT_SystemDebuggerBreak       = 0XA4,
  HID_USG_GDT_ApplicationBreak          = 0XA5,
  HID_USG_GDT_ApplicationDebuggerBreak  = 0XA6,
  HID_USG_GDT_SystemSpeakerMute         = 0XA7,
  HID_USG_GDT_SystemHibernate           = 0XA8,
  HID_USG_GDT_SystemDisplayInvert       = 0XB0,
  HID_USG_GDT_SystemDisplayInternal     = 0XB1,
  HID_USG_GDT_SystemDisplayExternal     = 0XB2,
  HID_USG_GDT_SystemDisplayBoth         = 0XB3,
  HID_USG_GDT_SystemDisplayDual         = 0XB4,
  HID_USG_GDT_SystemDisplayToggleIntExt = 0XB5,
  HID_USG_GDT_SystemDisplaySwap         = 0XB6,
  HID_USG_GDT_SystemDisplayLCDAutoscale = 0XB7,
} HidGenericDesktopUsage;

typedef enum {
  HID_USG_KBD_KeyboardErrorRollOver     = 0X01,
  HID_USG_KBD_KeyboardPostFail          = 0X02,
  HID_USG_KBD_KeyboardErrorUndefined    = 0X03,
  HID_USG_KBD_KeyboardA                 = 0X04,
  HID_USG_KBD_KeyboardB                 = 0X05,
  HID_USG_KBD_KeyboardC                 = 0X06,
  HID_USG_KBD_KeyboardD                 = 0X07,
  HID_USG_KBD_KeyboardE                 = 0X08,
  HID_USG_KBD_KeyboardF                 = 0X09,
  HID_USG_KBD_KeyboardG                 = 0X0A,
  HID_USG_KBD_KeyboardH                 = 0X0B,
  HID_USG_KBD_KeyboardI                 = 0X0C,
  HID_USG_KBD_KeyboardJ                 = 0X0D,
  HID_USG_KBD_KeyboardK                 = 0X0E,
  HID_USG_KBD_KeyboardL                 = 0X0F,
  HID_USG_KBD_KeyboardM                 = 0X10,
  HID_USG_KBD_KeyboardN                 = 0X11,
  HID_USG_KBD_KeyboardO                 = 0X12,
  HID_USG_KBD_KeyboardP                 = 0X13,
  HID_USG_KBD_KeyboardQ                 = 0X14,
  HID_USG_KBD_KeyboardR                 = 0X15,
  HID_USG_KBD_KeyboardS                 = 0X16,
  HID_USG_KBD_KeyboardT                 = 0X17,
  HID_USG_KBD_KeyboardU                 = 0X18,
  HID_USG_KBD_KeyboardV                 = 0X19,
  HID_USG_KBD_KeyboardW                 = 0X1A,
  HID_USG_KBD_KeyboardX                 = 0X1B,
  HID_USG_KBD_KeyboardY                 = 0X1C,
  HID_USG_KBD_KeyboardZ                 = 0X1D,
  HID_USG_KBD_Keyboard1                 = 0X1E,
  HID_USG_KBD_Keyboard2                 = 0X1F,
  HID_USG_KBD_Keyboard3                 = 0X20,
  HID_USG_KBD_Keyboard4                 = 0X21,
  HID_USG_KBD_Keyboard5                 = 0X22,
  HID_USG_KBD_Keyboard6                 = 0X23,
  HID_USG_KBD_Keyboard7                 = 0X24,
  HID_USG_KBD_Keyboard8                 = 0X25,
  HID_USG_KBD_Keyboard9                 = 0X26,
  HID_USG_KBD_Keyboard0                 = 0X27,
  HID_USG_KBD_KeyboardEnter             = 0X28,
  HID_USG_KBD_KeyboardEscape            = 0X29,
  HID_USG_KBD_KeyboardBackspace         = 0X2A,
  HID_USG_KBD_KeyboardTab               = 0X2B,
  HID_USG_KBD_KeyboardSpace             = 0X2C,
  HID_USG_KBD_KeyboardMinus             = 0X2D,
  HID_USG_KBD_KeyboardEqual             = 0X2E,
  HID_USG_KBD_KeyboardLeftBracket       = 0X2F,
  HID_USG_KBD_KeyboardRightBracket      = 0X30,
  HID_USG_KBD_KeyboardBackslash         = 0X31,
  HID_USG_KBD_KeyboardEurope1           = 0X32,
  HID_USG_KBD_KeyboardSemicolon         = 0X33,
  HID_USG_KBD_KeyboardApostrophe        = 0X34,
  HID_USG_KBD_KeyboardGrave             = 0X35,
  HID_USG_KBD_KeyboardComma             = 0X36,
  HID_USG_KBD_KeyboardPeriod            = 0X37,
  HID_USG_KBD_KeyboardSlash             = 0X38,
  HID_USG_KBD_KeyboardCapsLock          = 0X39,
  HID_USG_KBD_KeyboardF1                = 0X3A,
  HID_USG_KBD_KeyboardF2                = 0X3B,
  HID_USG_KBD_KeyboardF3                = 0X3C,
  HID_USG_KBD_KeyboardF4                = 0X3D,
  HID_USG_KBD_KeyboardF5                = 0X3E,
  HID_USG_KBD_KeyboardF6                = 0X3F,
  HID_USG_KBD_KeyboardF7                = 0X40,
  HID_USG_KBD_KeyboardF8                = 0X41,
  HID_USG_KBD_KeyboardF9                = 0X42,
  HID_USG_KBD_KeyboardF10               = 0X43,
  HID_USG_KBD_KeyboardF11               = 0X44,
  HID_USG_KBD_KeyboardF12               = 0X45,
  HID_USG_KBD_KeyboardPrintScreen       = 0X46,
  HID_USG_KBD_KeyboardScrollLock        = 0X47,
  HID_USG_KBD_KeyboardPause             = 0X48,
  HID_USG_KBD_KeyboardInsert            = 0X49,
  HID_USG_KBD_KeyboardHome              = 0X4A,
  HID_USG_KBD_KeyboardPageUp            = 0X4B,
  HID_USG_KBD_KeyboardDelete            = 0X4C,
  HID_USG_KBD_KeyboardEnd               = 0X4D,
  HID_USG_KBD_KeyboardPageDown          = 0X4E,
  HID_USG_KBD_KeyboardRightArrow        = 0X4F,
  HID_USG_KBD_KeyboardLeftArrow         = 0X50,
  HID_USG_KBD_KeyboardDownArrow         = 0X51,
  HID_USG_KBD_KeyboardUpArrow           = 0X52,
  HID_USG_KBD_KeypadNumLock             = 0X53,
  HID_USG_KBD_KeypadSlash               = 0X54,
  HID_USG_KBD_KeypadAsterisk            = 0X55,
  HID_USG_KBD_KeypadMinus               = 0X56,
  HID_USG_KBD_KeypadPlus                = 0X57,
  HID_USG_KBD_KeypadEnter               = 0X58,
  HID_USG_KBD_Keypad1                   = 0X59,
  HID_USG_KBD_Keypad2                   = 0X5A,
  HID_USG_KBD_Keypad3                   = 0X5B,
  HID_USG_KBD_Keypad4                   = 0X5C,
  HID_USG_KBD_Keypad5                   = 0X5D,
  HID_USG_KBD_Keypad6                   = 0X5E,
  HID_USG_KBD_Keypad7                   = 0X5F,
  HID_USG_KBD_Keypad8                   = 0X60,
  HID_USG_KBD_Keypad9                   = 0X61,
  HID_USG_KBD_Keypad0                   = 0X62,
  HID_USG_KBD_KeypadPeriod              = 0X63,
  HID_USG_KBD_KeyboardEurope2           = 0X64,
  HID_USG_KBD_KeyboardApplication       = 0X65,
  HID_USG_KBD_KeyboardPower             = 0X66,
  HID_USG_KBD_KeypadEqual               = 0X67,
  HID_USG_KBD_KeyboardF13               = 0X68,
  HID_USG_KBD_KeyboardF14               = 0X69,
  HID_USG_KBD_KeyboardF15               = 0X6A,
  HID_USG_KBD_KeyboardF16               = 0X6B,
  HID_USG_KBD_KeyboardF17               = 0X6C,
  HID_USG_KBD_KeyboardF18               = 0X6D,
  HID_USG_KBD_KeyboardF19               = 0X6E,
  HID_USG_KBD_KeyboardF20               = 0X6F,
  HID_USG_KBD_KeyboardF21               = 0X70,
  HID_USG_KBD_KeyboardF22               = 0X71,
  HID_USG_KBD_KeyboardF23               = 0X72,
  HID_USG_KBD_KeyboardF24               = 0X73,
  HID_USG_KBD_KeyboardExecute           = 0X74,
  HID_USG_KBD_KeyboardHelp              = 0X75,
  HID_USG_KBD_KeyboardMenu              = 0X76,
  HID_USG_KBD_KeyboardSelect            = 0X77,
  HID_USG_KBD_KeyboardStop              = 0X78,
  HID_USG_KBD_KeyboardAgain             = 0X79,
  HID_USG_KBD_KeyboardUndo              = 0X7A,
  HID_USG_KBD_KeyboardCut               = 0X7B,
  HID_USG_KBD_KeyboardCopy              = 0X7C,
  HID_USG_KBD_KeyboardPaste             = 0X7D,
  HID_USG_KBD_KeyboardFind              = 0X7E,
  HID_USG_KBD_KeyboardMute              = 0X7F,
  HID_USG_KBD_KeyboardVolumeUp          = 0X80,
  HID_USG_KBD_KeyboardVolumeDown        = 0X81,
  HID_USG_KBD_KeyboardLockingCapsLock   = 0X82,
  HID_USG_KBD_KeyboardLockingNumLock    = 0X83,
  HID_USG_KBD_KeyboardLockingScrollLock = 0X84,
  HID_USG_KBD_KeypadComma               = 0X85,
  HID_USG_KBD_KeypadEqualSign           = 0X86,
  HID_USG_KBD_KeyboardInternational1    = 0X87,
  HID_USG_KBD_KeyboardInternational2    = 0X88,
  HID_USG_KBD_KeyboardInternational3    = 0X89,
  HID_USG_KBD_KeyboardInternational4    = 0X8A,
  HID_USG_KBD_KeyboardInternational5    = 0X8B,
  HID_USG_KBD_KeyboardInternational6    = 0X8C,
  HID_USG_KBD_KeyboardInternational7    = 0X8D,
  HID_USG_KBD_KeyboardInternational8    = 0X8E,
  HID_USG_KBD_KeyboardInternational9    = 0X8F,
  HID_USG_KBD_KeyboardLanguage1         = 0X90,
  HID_USG_KBD_KeyboardLanguage2         = 0X91,
  HID_USG_KBD_KeyboardLanguage3         = 0X92,
  HID_USG_KBD_KeyboardLanguage4         = 0X93,
  HID_USG_KBD_KeyboardLanguage5         = 0X94,
  HID_USG_KBD_KeyboardLanguage6         = 0X95,
  HID_USG_KBD_KeyboardLanguage7         = 0X96,
  HID_USG_KBD_KeyboardLanguage8         = 0X97,
  HID_USG_KBD_KeyboardLanguage9         = 0X98,
  HID_USG_KBD_KeyboardAlternateErase    = 0X99,
  HID_USG_KBD_KeyboardSystemRequest     = 0X9A,
  HID_USG_KBD_KeyboardCancel            = 0X9B,
  HID_USG_KBD_KeyboardClear             = 0X9C,
  HID_USG_KBD_KeyboardPrior             = 0X9D,
  HID_USG_KBD_KeyboardReturn            = 0X9E,
  HID_USG_KBD_KeyboardSeparator         = 0X9F,
  HID_USG_KBD_KeyboardOut               = 0XA0,
  HID_USG_KBD_KeyboardOper              = 0XA1,
  HID_USG_KBD_KeyboardClearAgain        = 0XA2,
  HID_USG_KBD_KeyboardCrSel             = 0XA3,
  HID_USG_KBD_KeyboardExSel             = 0XA4,
  HID_USG_KBD_Keypad00                  = 0XB0,
  HID_USG_KBD_Keypad000                 = 0XB1,
  HID_USG_KBD_ThousandsSeparator        = 0XB2,
  HID_USG_KBD_DecimalSeparator          = 0XB3,
  HID_USG_KBD_CurrencyUnit              = 0XB4,
  HID_USG_KBD_CurrencySubunit           = 0XB5,
  HID_USG_KBD_KeypadLeftParenthesis     = 0XB6,
  HID_USG_KBD_KeypadRightParenthesis    = 0XB7,
  HID_USG_KBD_KeypadLeftBrace           = 0XB8,
  HID_USG_KBD_KeypadRightBrace          = 0XB9,
  HID_USG_KBD_KeypadTab                 = 0XBA,
  HID_USG_KBD_KeypadBackspace           = 0XBB,
  HID_USG_KBD_KeypadA                   = 0XBC,
  HID_USG_KBD_KeypadB                   = 0XBD,
  HID_USG_KBD_KeypadC                   = 0XBE,
  HID_USG_KBD_KeypadD                   = 0XBF,
  HID_USG_KBD_KeypadE                   = 0XC0,
  HID_USG_KBD_KeypadF                   = 0XC1,
  HID_USG_KBD_KeypadBitwiseXOR          = 0XC2,
  HID_USG_KBD_KeypadExponentiate        = 0XC3,
  HID_USG_KBD_KeypadModulo              = 0XC4,
  HID_USG_KBD_KeypadLess                = 0XC5,
  HID_USG_KBD_KeypadGreater             = 0XC6,
  HID_USG_KBD_KeypadBitwiseAND          = 0XC7,
  HID_USG_KBD_KeypadBooleanAND          = 0XC8,
  HID_USG_KBD_KeypadBitwiseOR           = 0XC9,
  HID_USG_KBD_KeypadBooleanOR           = 0XCA,
  HID_USG_KBD_KeypadColon               = 0XCB,
  HID_USG_KBD_KeypadNumber              = 0XCC,
  HID_USG_KBD_KeypadSpace               = 0XCD,
  HID_USG_KBD_KeypadAt                  = 0XCE,
  HID_USG_KBD_KeypadBoleanNOT           = 0XCF,
  HID_USG_KBD_KeypadMemoryStore         = 0XD0,
  HID_USG_KBD_KeypadMemoryRecall        = 0XD1,
  HID_USG_KBD_KeypadMemoryClear         = 0XD2,
  HID_USG_KBD_KeypadMemoryAdd           = 0XD3,
  HID_USG_KBD_KeypadMemorySubtract      = 0XD4,
  HID_USG_KBD_KeypadMemoryMultiply      = 0XD5,
  HID_USG_KBD_KeypadMemoryDivide        = 0XD6,
  HID_USG_KBD_KeypadPlusMinus           = 0XD7,
  HID_USG_KBD_KeypadClear               = 0XD8,
  HID_USG_KBD_KeypadClearEntry          = 0XD9,
  HID_USG_KBD_KeypadBinary              = 0XDA,
  HID_USG_KBD_KeypadOctal               = 0XDB,
  HID_USG_KBD_KeypadDecimal             = 0XDC,
  HID_USG_KBD_KeypadHexadecimal         = 0XDD,
  HID_USG_KBD_KeyboardLeftControl       = 0XE0,
  HID_USG_KBD_KeyboardLeftShift         = 0XE1,
  HID_USG_KBD_KeyboardLeftAlt           = 0XE2,
  HID_USG_KBD_KeyboardLeftGUI           = 0XE3,
  HID_USG_KBD_KeyboardRightControl      = 0XE4,
  HID_USG_KBD_KeyboardRightShift        = 0XE5,
  HID_USG_KBD_KeyboardRightAlt          = 0XE6,
  HID_USG_KBD_KeyboardRightGUI          = 0XE7,
} HidKeyboardUsage;

typedef enum {
  HID_USG_LED_NumLock                 = 0X01,
  HID_USG_LED_CapsLock                = 0X02,
  HID_USG_LED_ScrollLock              = 0X03,
  HID_USG_LED_Compose                 = 0X04,
  HID_USG_LED_Kana                    = 0X05,
  HID_USG_LED_Power                   = 0X06,
  HID_USG_LED_Shift                   = 0X07,
  HID_USG_LED_DoNotDisturb            = 0X08,
  HID_USG_LED_Mute                    = 0X09,
  HID_USG_LED_ToneEnable              = 0X0A,
  HID_USG_LED_HighCutFilter           = 0X0B,
  HID_USG_LED_LowCutFilter            = 0X0C,
  HID_USG_LED_EqualizerEnable         = 0X0D,
  HID_USG_LED_SoundFieldOn            = 0X0E,
  HID_USG_LED_SurroundOn              = 0X0F,
  HID_USG_LED_Repeat                  = 0X10,
  HID_USG_LED_Stereo                  = 0X11,
  HID_USG_LED_SamplingRateDetect      = 0X12,
  HID_USG_LED_Spinning                = 0X13,
  HID_USG_LED_CAV                     = 0X14,
  HID_USG_LED_CLV                     = 0X15,
  HID_USG_LED_RecordingFormatDetect   = 0X16,
  HID_USG_LED_OffHook                 = 0X17,
  HID_USG_LED_Ring                    = 0X18,
  HID_USG_LED_MessageWaiting          = 0X19,
  HID_USG_LED_DataMode                = 0X1A,
  HID_USG_LED_BatteryOperation        = 0X1B,
  HID_USG_LED_BatteryOK               = 0X1C,
  HID_USG_LED_BatteryLow              = 0X1D,
  HID_USG_LED_Speaker                 = 0X1E,
  HID_USG_LED_HeadSet                 = 0X1F,
  HID_USG_LED_Hold                    = 0X20,
  HID_USG_LED_Microphone              = 0X21,
  HID_USG_LED_Coverage                = 0X22,
  HID_USG_LED_NightMode               = 0X23,
  HID_USG_LED_SendCalls               = 0X24,
  HID_USG_LED_CallPickup              = 0X25,
  HID_USG_LED_Conference              = 0X26,
  HID_USG_LED_StandBy                 = 0X27,
  HID_USG_LED_CameraOn                = 0X28,
  HID_USG_LED_CameraOff               = 0X29,
  HID_USG_LED_OnLine                  = 0X2A,
  HID_USG_LED_OffLine                 = 0X2B,
  HID_USG_LED_Busy                    = 0X2C,
  HID_USG_LED_Ready                   = 0X2D,
  HID_USG_LED_PaperOut                = 0X2E,
  HID_USG_LED_PaperJam                = 0X2F,
  HID_USG_LED_Remote                  = 0X30,
  HID_USG_LED_Forward                 = 0X31,
  HID_USG_LED_Reverse                 = 0X32,
  HID_USG_LED_Stop                    = 0X33,
  HID_USG_LED_Rewind                  = 0X34,
  HID_USG_LED_FastForward             = 0X35,
  HID_USG_LED_Play                    = 0X36,
  HID_USG_LED_Pause                   = 0X37,
  HID_USG_LED_Record                  = 0X38,
  HID_USG_LED_Error                   = 0X39,
  HID_USG_LED_UsageSelectedIndicator  = 0X3A,
  HID_USG_LED_UsageInUseIndicator     = 0X3B,
  HID_USG_LED_UsageMultiModeIndicator = 0X3C,
  HID_USG_LED_IndicatorOn             = 0X3D,
  HID_USG_LED_IndicatorFlash          = 0X3E,
  HID_USG_LED_IndicatorSlowBlink      = 0X3F,
  HID_USG_LED_IndicatorFastBlink      = 0X40,
  HID_USG_LED_IndicatorOff            = 0X41,
  HID_USG_LED_FlashOnTime             = 0X42,
  HID_USG_LED_SlowBlinkOnTime         = 0X43,
  HID_USG_LED_SlowBlinkOffTime        = 0X44,
  HID_USG_LED_FastBlinkOnTime         = 0X45,
  HID_USG_LED_FastBlinkOffTime        = 0X46,
  HID_USG_LED_UsageIndicatorColor     = 0X47,
  HID_USG_LED_IndicatorRed            = 0X48,
  HID_USG_LED_IndicatorGreen          = 0X49,
  HID_USG_LED_IndicatorAmber          = 0X4A,
  HID_USG_LED_GenericIndicator        = 0X4B,
  HID_USG_LED_SystemSuspend           = 0X4C,
  HID_USG_LED_ExternalPowerConnected  = 0X4D,
} HidLEDsUsage;

typedef enum {
  HID_USG_BRL_BrailleDisplay  = 0X001,
  HID_USG_BRL_CellRow         = 0X002,
  HID_USG_BRL_8DotCell        = 0X003,
  HID_USG_BRL_6DotCell        = 0X004,
  HID_USG_BRL_CellCount       = 0X005,
  HID_USG_BRL_ReaderControls  = 0X006,
  HID_USG_BRL_ReaderUUID      = 0X007,
  HID_USG_BRL_PrimaryRouter   = 0X0FA,
  HID_USG_BRL_SecondaryRouter = 0X0FB,
  HID_USG_BRL_TertiaryRouter  = 0X0FC,
  HID_USG_BRL_CellRouter      = 0X100,
  HID_USG_BRL_RowRouter       = 0X101,
  HID_USG_BRL_Buttons         = 0X200,
  HID_USG_BRL_KeyboardDot1    = 0X201,
  HID_USG_BRL_KeyboardDot2    = 0X202,
  HID_USG_BRL_KeyboardDot3    = 0X203,
  HID_USG_BRL_KeyboardDot4    = 0X204,
  HID_USG_BRL_KeyboardDot5    = 0X205,
  HID_USG_BRL_KeyboardDot6    = 0X206,
  HID_USG_BRL_KeyboardDot7    = 0X207,
  HID_USG_BRL_KeyboardDot8    = 0X208,
  HID_USG_BRL_KeyboardSpace   = 0X209,
  HID_USG_BRL_LeftSpace       = 0X20A,
  HID_USG_BRL_RightSpace      = 0X20B,
  HID_USG_BRL_FrontControls   = 0X20C,
  HID_USG_BRL_LeftControls    = 0X20D,
  HID_USG_BRL_RightControls   = 0X20E,
  HID_USG_BRL_TopControls     = 0X20F,
  HID_USG_BRL_JoystickCenter  = 0X210,
  HID_USG_BRL_JoystickUp      = 0X211,
  HID_USG_BRL_JoystickDown    = 0X212,
  HID_USG_BRL_JoystickLeft    = 0X213,
  HID_USG_BRL_JoystickRight   = 0X214,
  HID_USG_BRL_DPadCenter      = 0X215,
  HID_USG_BRL_DPadUp          = 0X216,
  HID_USG_BRL_DPadDown        = 0X217,
  HID_USG_BRL_DPadLeft        = 0X218,
  HID_USG_BRL_DPadRight       = 0X219,
  HID_USG_BRL_PanLeft         = 0X21A,
  HID_USG_BRL_PanRight        = 0X21B,
  HID_USG_BRL_RockerUp        = 0X21C,
  HID_USG_BRL_RockerDown      = 0X21D,
  HID_USG_BRL_RockerPress     = 0X21E,
} HidBrailleUsage;

typedef enum {
  HID_UPG_GenericDesktop          = 0X01,
  HID_UPG_Simulation              = 0X02,
  HID_UPG_VirtualReality          = 0X03,
  HID_UPG_Sport                   = 0X04,
  HID_UPG_Game                    = 0X05,
  HID_UPG_GenericDevice           = 0X06,
  HID_UPG_KeyboardKeypad          = 0X07,
  HID_UPG_LEDs                    = 0X08,
  HID_UPG_Button                  = 0X09,
  HID_UPG_Ordinal                 = 0X0A,
  HID_UPG_Telephony               = 0X0B,
  HID_UPG_Consumer                = 0X0C,
  HID_UPG_Digitizer               = 0X0D,
  HID_UPG_PhysicalInterfaceDevice = 0X0F,
  HID_UPG_Unicode                 = 0X10,
  HID_UPG_AlphanumericDisplay     = 0X14,
  HID_UPG_MedicalInstruments      = 0X40,
  HID_UPG_Braille                 = 0X41,
  HID_UPG_BarCodeScanner          = 0X8C,
  HID_UPG_Scale                   = 0X8D,
  HID_UPG_MagneticStripeReader    = 0X8E,
  HID_UPG_Camera                  = 0X90,
  HID_UPG_Arcade                  = 0X91,
} HidUsagePage;

typedef enum {
  HID_USG_FLG_CONSTANT      = 0X001,
  HID_USG_FLG_VARIABLE      = 0X002,
  HID_USG_FLG_RELATIVE      = 0X004,
  HID_USG_FLG_WRAP          = 0X008,
  HID_USG_FLG_NON_LINEAR    = 0X010,
  HID_USG_FLG_NO_PREFERRED  = 0X020,
  HID_USG_FLG_NULL_STATE    = 0X040,
  HID_USG_FLG_VOLATILE      = 0X080,
  HID_USG_FLG_BUFFERED_BYTE = 0X100,

  HID_USG_FLG_DATA           = 0, // !HID_USG_FLG_CONSTANT,
  HID_USG_FLG_ARRAY          = 0, // !HID_USG_FLG_VARIABLE,
  HID_USG_FLG_ABSOLUTE       = 0, // !HID_USG_FLAG_RELATIVE,
} HidUsageFlags;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_HID_DEFS */
