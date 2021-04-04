#pragma once

#include "quantum.h"
#define KNO KC_NO

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B,      \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      \
    K30, K31,      K33,      K35,      K37, K38,      K3A            \
) { \
	{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, KNO }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, KNO }, \
    { K30, K31, KNO, K33, KNO, K35, KNO, K37, K38, KNO, K3A, KNO, KNO }, \
}
