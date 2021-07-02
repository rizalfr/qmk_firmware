#pragma once

#include <inttypes.h>
#include <stddef.h>

/* take qmk config macros and set up helper variables for default settings */

/* ========================================================================== */
/* Grave escape                                                               */
/* ========================================================================== */
#ifdef GRAVE_ESC_ALT_OVERRIDE
#define GRAVE_ESC_ALT_OVERRIDE_Defined 1
#else
#define GRAVE_ESC_ALT_OVERRIDE_Defined 0
#endif

#ifdef GRAVE_ESC_CTRL_OVERRIDE
#define GRAVE_ESC_CTRL_OVERRIDE_Defined 1
#else
#define GRAVE_ESC_CTRL_OVERRIDE_Defined 0
#endif

#ifdef GRAVE_ESC_GUI_OVERRIDE
#define GRAVE_ESC_GUI_OVERRIDE_Defined 1
#else
#define GRAVE_ESC_GUI_OVERRIDE_Defined 0
#endif

#ifdef GRAVE_ESC_SHIFT_OVERRIDE
#define GRAVE_ESC_SHIFT_OVERRIDE_Defined 1
#else
#define GRAVE_ESC_SHIFT_OVERRIDE_Defined 0
#endif

/* ========================================================================== */
/* Auto shift                                                                 */
/* ========================================================================== */
#ifdef AUTO_SHIFT_ENABLE
#define AUTO_SHIFT_ENABLE_Defined 1
#else
#define AUTO_SHIFT_ENABLE_Defined 0
#endif

#ifdef AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_MODIFIERS_Defined 1
#else
#define AUTO_SHIFT_MODIFIERS_Defined 0
#endif

#ifdef NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_SPECIAL_Defined 1
#else
#define NO_AUTO_SHIFT_SPECIAL_Defined 0
#endif

#ifdef NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_NUMERIC_Defined 1
#else
#define NO_AUTO_SHIFT_NUMERIC_Defined 0
#endif

#ifdef NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_ALPHA_Defined 1
#else
#define NO_AUTO_SHIFT_ALPHA_Defined 0
#endif

#ifdef AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_REPEAT_Defined 1
#else
#define AUTO_SHIFT_REPEAT_Defined 0
#endif

#ifdef AUTO_SHIFT_NO_AUTO_REPEAT
#define AUTO_SHIFT_NO_AUTO_REPEAT_Defined 1
#else
#define AUTO_SHIFT_NO_AUTO_REPEAT_Defined 0
#endif

#ifdef QMK_SETTINGS
/* dynamic settings framework is enabled */

/* actual settings - stored in RAM and backed by EEPROM
   these are in arbitrary order to ensure they are aligned w/o any holes, and the order can be changed at will */
typedef struct {
    uint8_t grave_esc_override;
    uint8_t auto_shift;
    uint8_t osk_tap_toggle;
    uint8_t tap_hold;
    uint16_t debounce_time;
    uint16_t auto_shift_timeout;
    uint16_t osk_timeout;
    uint16_t tapping_term;
} qmk_settings_t;
_Static_assert(sizeof(qmk_settings_t) == 12, "unexpected size of the qmk_settings_t structure");

typedef void (*qmk_setting_callback_t)(void);

/* setting prototype - describes how to get/set settings, stored in flash */
typedef struct {
    uint16_t qsid;
    uint16_t sz;
    void *ptr;
    qmk_setting_callback_t cb;
} qmk_settings_proto_t;

void qmk_settings_init(void);
void qmk_settings_reset(void);
void qmk_settings_query(uint16_t qsid_gt, void *buffer, size_t sz);
int qmk_settings_get(uint16_t qsid, void *setting, size_t maxsz);
int qmk_settings_set(uint16_t qsid, const void *setting, size_t maxsz);

extern qmk_settings_t QS;

/* Grave escape */
#define QS_grave_esc_alt_override (QS.grave_esc_override & 1)
#define QS_grave_esc_ctrl_override (QS.grave_esc_override & 2)
#define QS_grave_esc_gui_override (QS.grave_esc_override & 4)
#define QS_grave_esc_shift_override (QS.grave_esc_override & 8)

/* Auto shift */
#define QS_auto_shift_enable (QS.auto_shift & 1)
#define QS_auto_shift_modifiers (QS.auto_shift & 2)
#define QS_auto_shift_no_auto_shift_special (QS.auto_shift & 4)
#define QS_auto_shift_no_auto_shift_numeric (QS.auto_shift & 8)
#define QS_auto_shift_no_auto_shift_alpha (QS.auto_shift & 16)
#define QS_auto_shift_repeat (QS.auto_shift & 32)
#define QS_auto_shift_no_auto_repeat (QS.auto_shift & 64)

/* One Shot Keys */
#define QS_oneshot_tap_toggle (QS.osk_tap_toggle)
#define QS_oneshot_timeout (QS.osk_timeout)

#else
/* dynamic settings framework is disabled => hardcode the settings and let the compiler optimize extra branches out */

/* Grave escape */
#define QS_grave_esc_alt_override GRAVE_ESC_ALT_OVERRIDE_Defined
#define QS_grave_esc_ctrl_override GRAVE_ESC_CTRL_OVERRIDE_Defined
#define QS_grave_esc_gui_override GRAVE_ESC_GUI_OVERRIDE_Defined
#define QS_grave_esc_shift_override GRAVE_ESC_SHIFT_OVERRIDE_Defined

/* Auto shift */
#define QS_auto_shift_enable AUTO_SHIFT_ENABLE_Defined
#define QS_auto_shift_modifiers AUTO_SHIFT_MODIFIERS_Defined
#define QS_auto_shift_no_auto_shift_special NO_AUTO_SHIFT_SPECIAL_Defined
#define QS_auto_shift_no_auto_shift_numeric NO_AUTO_SHIFT_NUMERIC_Defined
#define QS_auto_shift_no_auto_shift_alpha NO_AUTO_SHIFT_ALPHA_Defined
#define QS_auto_shift_repeat AUTO_SHIFT_REPEAT_Defined
#define QS_auto_shift_no_auto_repeat AUTO_SHIFT_NO_AUTO_REPEAT_Defined

/* One Shot Keys */
#define QS_oneshot_tap_toggle ONESHOT_TAP_TOGGLE
#define QS_oneshot_timeout ONESHOT_TIMEOUT

#endif
