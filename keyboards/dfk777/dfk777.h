/* Copyright 2019 coseyfannitutti
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define _x_ KC_NO

#include "quantum.h"

#define LAYOUT_65_ansi( \
  K0E, K0F, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0G, K0H, K0I, K0J, \
  K1E, K1F, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1G, K1H, K1I, K1J, \
  K2E, K2F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, K2G, K2H, K2I, K2J, \
  K3E, K3F, K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3G, K3H, K3I, K3J, \
  K4E, K4F, K40, K41, K42,                K46,           K49, K4A, K4B, K4C,      K4G, K4H, K4I \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E, K2F, K2G, K2H, K2I, K2J }, \
{ K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J }, \
{ K40, K41, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, K4B, K4C, _x_, K4E, K4F, K4G, K4H, K4I, _x_ } \
}

#define LAYOUT_65_ansi_blocker( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, K2E, \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40, K41, K42,                K46,           K49, K4A,      K4C, K4D, K4E \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
{ K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
{ K40, K41, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, _x_, K4C, K4D, K4E} \
}

#define LAYOUT_65_ansi_2_right_mods LAYOUT_65_ansi_blocker

#define LAYOUT_wkl_ansi_2_right_mods( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, K2E, \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40,      K42,                K46,           K49, K4A,      K4C, K4D, K4E \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
{ K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
{ K40, _x_, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, _x_, K4C, K4D, K4E} \
}

#define LAYOUT_wkl_ansi_3_right_mods( \
  KF00, KF01, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KN00, KN01, KN02, KN03, \
  KF10, KF11, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, KN10, KN11, KN12, KN13, \
  KF20, KF21, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, KN20, KN21, KN22, KN23, \
  KF30, KF31, K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, KN30, KN31, KN32, KN33, \
  KF40, KF41, K40,      K42,                K46,           K49, K4A, K4B, K4C, K4D, KN40, KN41, KN42 \
) { \
{ KF00, KF01, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KN00, KN01, KN02, KN03 }, \
{ KF10, KF11, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, KN10, KN11, KN12, KN13 }, \
{ KF20, KF21, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, KN20, KN21, KN22, KN23 }, \
{ KF30, KF31, K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, KN30, KN31, KN32, KN33 }, \
{ KF40, KF41, K40, _x_, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, K4B, K4C, K4D, KN40, KN41, KN42, _x_ } \
}

#define LAYOUT_65_iso( \
  KF00, KF01, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KN00, KN01, KN02, KN03, \
  KF10, KF11, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      KN10, KN11, KN12, KN13, \
  KF20, KF21, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D, K1D, KN20, KN21, KN22, KN23, \
  KF30, KF31, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, KN30, KN31, KN32, KN33, \
  KF40, KF41, K40, K41, K42,                K46,           K49, K4A, K4B, K4C, K4D, KN40, KN41, KN42 \
) { \
{ KF00, KF01, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KN00, KN01, KN02, KN03 }, \
{ KF10, KF11, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, KN10, KN11, KN12, KN13 }, \
{ KF20, KF21, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, KN20, KN21, KN22, KN23 }, \
{ KF30, KF31, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, KN30, KN31, KN32, KN33 }, \
{ KF40, KF41, K40, K41, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, K4B, K4C, K4D, KN40, KN41, KN42, _x_ } \
}

#define LAYOUT_65_iso_blocker( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D, K1D, K2E, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40, K41, K42,                K46,           K49, K4A,      K4C, K4D, K4E \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
{ K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
{ K40, K41, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, _x_, K4C, K4D, K4E} \
}

#define LAYOUT_65_iso_2_right_mods LAYOUT_65_iso_blocker

#define LAYOUT_wkl_iso_2_right_mods( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D, K1D, K2E, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40,      K42,                K46,           K49, K4A,      K4C, K4D, K4E \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
{ K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
{ K40, _x_, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, _x_, K4C, K4D, K4E} \
}

#define LAYOUT_wkl_iso_3_right_mods( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D, K1D, K2E, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40,      K42,                K46,           K49, K4A, K4B, K4C, K4D, K4E \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
{ K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
{ K40, _x_, K42, _x_, _x_, _x_, K46, _x_, _x_, K49, K4A, K4B, K4C, K4D, K4E} \
}
