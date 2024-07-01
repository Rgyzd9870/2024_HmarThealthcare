/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font F:/LVGL/assets/QingNiaoHuaGuangJianMeiHei-2.ttf -o F:/LVGL/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --symbols 时间温度湿度舵机开关屏幕电量今日步数自动心率左右液滴下落次数 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0x80,

    /* U+0022 "\"" */
    0x1, 0x24, 0xa4,

    /* U+0023 "#" */
    0x2, 0x11, 0x8, 0x84, 0x5f, 0xf1, 0x10, 0x88,
    0x44, 0x3f, 0xf1, 0x8, 0x84, 0x42, 0x0,

    /* U+0024 "$" */
    0x21, 0xbf, 0x4a, 0x30, 0xe5, 0xad, 0xdc, 0x40,

    /* U+0025 "%" */
    0x61, 0x12, 0x22, 0x48, 0x4a, 0x9, 0x5c, 0xd6,
    0xc2, 0x88, 0x91, 0x23, 0x64, 0x38,

    /* U+0026 "&" */
    0x38, 0x24, 0x12, 0x6, 0x7, 0x4, 0x52, 0x19,
    0x9c, 0x79, 0x0,

    /* U+0027 "'" */
    0x9, 0x40,

    /* U+0028 "(" */
    0x4b, 0x49, 0x24, 0x92, 0x24, 0xc0,

    /* U+0029 ")" */
    0x49, 0x92, 0x49, 0x24, 0xa5, 0x80,

    /* U+002A "*" */
    0x11, 0xac, 0xe3, 0xed, 0x62, 0x0,

    /* U+002B "+" */
    0x8, 0x4, 0x2, 0x1f, 0xf0, 0x80, 0x40, 0x20,
    0x10,

    /* U+002C "," */
    0x9, 0x40,

    /* U+002D "-" */
    0xff, 0x80,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x4, 0x20, 0x84, 0x10, 0x82, 0x10, 0x42, 0x0,

    /* U+0030 "0" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0031 "1" */
    0x64, 0x92, 0x49, 0x20,

    /* U+0032 "2" */
    0x79, 0x38, 0x41, 0xc, 0x21, 0x8c, 0x63, 0xf0,

    /* U+0033 "3" */
    0x39, 0x10, 0x41, 0x18, 0x30, 0x41, 0x4c, 0xe0,

    /* U+0034 "4" */
    0x0, 0x21, 0x86, 0x29, 0x24, 0xbf, 0x8,

    /* U+0035 "5" */
    0x3c, 0x87, 0x2, 0x4, 0x10, 0x72, 0x70,

    /* U+0036 "6" */
    0x18, 0x20, 0x83, 0xec, 0x70, 0x60, 0xe3, 0x3c,

    /* U+0037 "7" */
    0xfc, 0x18, 0x20, 0xc3, 0x4, 0x18, 0x20, 0x80,
    0x0,

    /* U+0038 "8" */
    0x7b, 0x1c, 0x71, 0x7a, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x38, 0x61, 0xcd, 0xe1, 0xc, 0x61, 0x0,

    /* U+003A ":" */
    0x90,

    /* U+003B ";" */
    0x41, 0x60,

    /* U+003C "<" */
    0x0, 0x0, 0x30, 0x30, 0x30, 0x10, 0x18, 0xc,
    0x0, 0xc0, 0xc, 0x0, 0xc0, 0xc,

    /* U+003D "=" */
    0xff, 0x0, 0xff,

    /* U+003E ">" */
    0x0, 0x30, 0x3, 0x0, 0x30, 0x2, 0x0, 0x60,
    0xc, 0xc, 0xc, 0xc, 0xc, 0x0,

    /* U+003F "?" */
    0xe9, 0x16, 0x89, 0x40, 0x60,

    /* U+0040 "@" */
    0x1f, 0x4, 0x11, 0x1, 0x47, 0x99, 0xb3, 0x22,
    0x64, 0x4e, 0x9b, 0x4f, 0xc6, 0x0, 0x3e, 0x0,

    /* U+0041 "A" */
    0x8, 0x4, 0x7, 0x2, 0x83, 0x21, 0x10, 0xfc,
    0x82, 0x41, 0x80,

    /* U+0042 "B" */
    0xe4, 0xa5, 0x2f, 0x46, 0x31, 0xf0,

    /* U+0043 "C" */
    0x1e, 0x61, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0x61,
    0x3e,

    /* U+0044 "D" */
    0xf9, 0x1a, 0x1c, 0x18, 0x30, 0x61, 0xc6, 0xf0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0xf8,

    /* U+0046 "F" */
    0xf8, 0x88, 0xf8, 0x88, 0x80,

    /* U+0047 "G" */
    0x1e, 0x30, 0xb0, 0x10, 0x8, 0x3c, 0x7, 0x4,
    0xc2, 0x3e, 0x0,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x1f, 0xf0, 0x60, 0xc1, 0x82,

    /* U+0049 "I" */
    0xff, 0x80,

    /* U+004A "J" */
    0x11, 0x11, 0x11, 0x11, 0x1e,

    /* U+004B "K" */
    0x85, 0x12, 0x47, 0xe, 0x16, 0x26, 0x44, 0x84,

    /* U+004C "L" */
    0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+004D "M" */
    0x20, 0x84, 0x10, 0xc6, 0x38, 0xa5, 0x94, 0x94,
    0x93, 0x92, 0x22, 0xc4, 0x60,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xb1, 0x99, 0x8d, 0x87, 0x83,
    0x81,

    /* U+004F "O" */
    0x1e, 0x18, 0x6c, 0xe, 0x1, 0x80, 0x60, 0x1c,
    0x9, 0x86, 0x3e, 0x0,

    /* U+0050 "P" */
    0xf4, 0x63, 0x1f, 0x42, 0x10, 0x80,

    /* U+0051 "Q" */
    0x1e, 0x18, 0x6c, 0xa, 0x1, 0x80, 0x60, 0x1c,
    0x6d, 0x8e, 0x3f, 0x80, 0x10,

    /* U+0052 "R" */
    0xf2, 0x28, 0xa2, 0xf2, 0x89, 0x26, 0x88,

    /* U+0053 "S" */
    0x39, 0x14, 0x18, 0x18, 0x30, 0x51, 0x38,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x20,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0056 "V" */
    0x41, 0x20, 0x98, 0x84, 0x43, 0x60, 0xa0, 0x70,
    0x10, 0x8, 0x0,

    /* U+0057 "W" */
    0x40, 0xa, 0x18, 0x58, 0xc4, 0x46, 0x22, 0x4b,
    0xa, 0x50, 0x52, 0x81, 0x8, 0x8, 0x40,

    /* U+0058 "X" */
    0x46, 0xc8, 0xa0, 0xc1, 0x7, 0xb, 0x22, 0x42,

    /* U+0059 "Y" */
    0x86, 0x89, 0xb1, 0x43, 0x2, 0x4, 0x8, 0x10,

    /* U+005A "Z" */
    0x7e, 0x8, 0x20, 0xc1, 0x6, 0x8, 0x20, 0x7e,

    /* U+005B "[" */
    0xea, 0xaa, 0xaa, 0xc0,

    /* U+005C "\\" */
    0x81, 0x4, 0x8, 0x20, 0x41, 0x2, 0x8, 0x10,

    /* U+005D "]" */
    0xd5, 0x55, 0x55, 0xc0,

    /* U+005E "^" */
    0x65,

    /* U+005F "_" */
    0xf0,

    /* U+0060 "`" */
    0x9, 0x60,

    /* U+0061 "a" */
    0x77, 0x38, 0x61, 0xcd, 0xd0,

    /* U+0062 "b" */
    0x82, 0x8, 0x20, 0x82, 0xec, 0xe1, 0x87, 0x3b,
    0x80,

    /* U+0063 "c" */
    0x3e, 0x21, 0xc, 0x3c,

    /* U+0064 "d" */
    0x4, 0x10, 0x41, 0x5, 0xdc, 0xe1, 0x87, 0x37,
    0x40,

    /* U+0065 "e" */
    0x7a, 0x2f, 0xe0, 0xc9, 0xc0,

    /* U+0066 "f" */
    0x34, 0x44, 0x4e, 0x44, 0x44, 0x40,

    /* U+0067 "g" */
    0x35, 0x38, 0x61, 0x4c, 0xd0, 0x51, 0x78,

    /* U+0068 "h" */
    0x84, 0x21, 0xf, 0x46, 0x31, 0x8c, 0x40,

    /* U+0069 "i" */
    0x9f, 0x80,

    /* U+006A "j" */
    0x9f, 0xf0,

    /* U+006B "k" */
    0x84, 0x21, 0x9, 0x53, 0x14, 0xb4, 0xc0,

    /* U+006C "l" */
    0xff, 0xc0,

    /* U+006D "m" */
    0xed, 0x26, 0x4c, 0x99, 0x32, 0x40,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc4,

    /* U+006F "o" */
    0x7d, 0x8e, 0xc, 0x1c, 0x6f, 0x80,

    /* U+0070 "p" */
    0xbb, 0x38, 0x61, 0xce, 0xe8, 0x20, 0x80,

    /* U+0071 "q" */
    0x77, 0x38, 0x61, 0xcd, 0xd0, 0x41, 0x4,

    /* U+0072 "r" */
    0xe8, 0x88, 0x88,

    /* U+0073 "s" */
    0xe8, 0xc2, 0x2e,

    /* U+0074 "t" */
    0x5d, 0x24, 0x90,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xb8,

    /* U+0076 "v" */
    0x45, 0x36, 0x8a, 0x30, 0x40,

    /* U+0077 "w" */
    0x48, 0x93, 0x26, 0xd0, 0xcc, 0x33, 0x4, 0x80,

    /* U+0078 "x" */
    0x64, 0x50, 0x41, 0xc2, 0x88, 0x80,

    /* U+0079 "y" */
    0x44, 0x88, 0xa1, 0xc1, 0x2, 0x8, 0x10, 0x40,

    /* U+007A "z" */
    0x7c, 0x10, 0x61, 0x82, 0xf, 0xc0,

    /* U+007B "{" */
    0xea, 0xaa, 0xaa, 0xb0,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc9, 0x24, 0x92, 0x49, 0x25, 0x0,

    /* U+007E "~" */
    0x4d, 0xc0,

    /* U+4E0B "下" */
    0xff, 0xe1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x3, 0xe0, 0x66, 0xc, 0xc1, 0x80, 0x30, 0x6,
    0x0, 0xc0, 0x18, 0x0,

    /* U+4ECA "今" */
    0xc, 0x3, 0xc0, 0x6c, 0x8, 0xc3, 0x8e, 0xcc,
    0xa1, 0x80, 0x0, 0x1, 0xcf, 0xf0, 0x6, 0x0,
    0x80, 0x30, 0x4, 0x1, 0x0, 0x0,

    /* U+5173 "关" */
    0x21, 0xc3, 0x30, 0x64, 0x1, 0x7, 0xfc, 0x18,
    0x3, 0x0, 0x60, 0xff, 0xe1, 0xc0, 0x38, 0xd,
    0x81, 0x98, 0x63, 0x98, 0x34, 0x2,

    /* U+52A8 "动" */
    0x3, 0xf, 0x60, 0xd, 0x3, 0xf0, 0x37, 0xf6,
    0xc8, 0xd9, 0x1b, 0x63, 0x6c, 0x6d, 0x29, 0xdd,
    0x3e, 0xe7, 0x8, 0xc2, 0x18, 0x86,

    /* U+53F3 "右" */
    0xc, 0x1, 0x83, 0xff, 0x8c, 0x1, 0x80, 0x60,
    0xc, 0x13, 0xff, 0x70, 0x76, 0xc, 0xc1, 0x98,
    0x33, 0x6, 0x7f, 0xcc, 0x18,

    /* U+5C4F "屏" */
    0x60, 0x6f, 0xfd, 0x81, 0xbf, 0xf6, 0x8e, 0xcd,
    0x98, 0xa3, 0x7f, 0x66, 0x8c, 0xd1, 0xff, 0xb3,
    0x44, 0x49, 0x99, 0x26, 0x20, 0x4,

    /* U+5DE6 "左" */
    0xc, 0x1, 0x83, 0xff, 0x8c, 0x1, 0x80, 0x20,
    0xf, 0xf1, 0x30, 0x46, 0x10, 0xc0, 0x18, 0x3,
    0x0, 0x60, 0xc, 0x1f, 0xf8,

    /* U+5E55 "幕" */
    0x31, 0x9f, 0xfc, 0xc6, 0x30, 0x67, 0xfc, 0xff,
    0x98, 0x33, 0xfe, 0xff, 0xe7, 0x61, 0xb7, 0xbf,
    0xf6, 0xc8, 0xdb, 0x3, 0x40,

    /* U+5EA6 "度" */
    0x6, 0xc, 0x41, 0xff, 0xb0, 0x6, 0xd8, 0xff,
    0xdb, 0x63, 0x7c, 0x60, 0xf, 0xf9, 0xa6, 0x32,
    0x86, 0x30, 0x9f, 0xdc, 0x3c, 0x0,

    /* U+5F00 "开" */
    0xff, 0xe6, 0x20, 0xc4, 0x18, 0x83, 0x11, 0xff,
    0xcc, 0x41, 0x88, 0x31, 0x6, 0x20, 0xc4, 0x10,
    0x84, 0x11, 0x2, 0x0,

    /* U+5FC3 "心" */
    0x4, 0x0, 0x40, 0xc, 0xd, 0x81, 0x80, 0xb0,
    0x96, 0x12, 0xc3, 0xd8, 0x7b, 0x2f, 0x65, 0xcc,
    0xb1, 0xb8, 0x3e, 0x7, 0xc0,

    /* U+6570 "数" */
    0x23, 0x15, 0xe1, 0xac, 0x19, 0xff, 0xe0, 0xd5,
    0xaa, 0xb0, 0x16, 0x2a, 0xdf, 0xb9, 0xa6, 0x2c,
    0xc3, 0x1c, 0x7f, 0xf1, 0x10,

    /* U+65E5 "日" */
    0xc1, 0xbf, 0xec, 0x1b, 0x6, 0xc1, 0xb0, 0x6c,
    0x1b, 0xfe, 0xc1, 0xb0, 0x6c, 0x1b, 0x6, 0xc1,
    0xbf, 0xec, 0x18,

    /* U+65F6 "时" */
    0x1, 0xb6, 0x6f, 0x9b, 0x7f, 0xd9, 0xb6, 0x6f,
    0xdb, 0xf6, 0xdf, 0xb6, 0x6d, 0x9b, 0x66, 0xf9,
    0xb7, 0xe0, 0x38,

    /* U+673A "机" */
    0x36, 0xe6, 0xfb, 0xfb, 0x1b, 0x63, 0x6c, 0xed,
    0x9f, 0xb3, 0xf6, 0x76, 0xce, 0xd9, 0xdb, 0x5a,
    0x63, 0x4e, 0x69, 0xce, 0x38,

    /* U+6B21 "次" */
    0xc, 0x11, 0x91, 0xbf, 0x34, 0x61, 0x8, 0x4c,
    0x1, 0x81, 0x30, 0x26, 0xc, 0xe1, 0x34, 0x66,
    0xcc, 0x8c, 0x21, 0x88, 0x10,

    /* U+6B65 "步" */
    0x6, 0x4, 0xc0, 0x9f, 0x93, 0x2, 0x61, 0xff,
    0xc0, 0x0, 0x30, 0x36, 0xec, 0xd9, 0x9f, 0x23,
    0xc8, 0x70, 0x18, 0x3c, 0x0,

    /* U+6DB2 "液" */
    0x83, 0x8, 0x61, 0xff, 0x80, 0x0, 0xd1, 0x1e,
    0x92, 0xf3, 0x52, 0x1a, 0x47, 0xb8, 0x2b, 0x14,
    0xc6, 0x99, 0x93, 0x92, 0x78, 0x50,

    /* U+6E29 "温" */
    0x8c, 0xcd, 0xf9, 0xb3, 0x7, 0xe8, 0xcd, 0x9f,
    0x90, 0x0, 0xc2, 0x1f, 0xeb, 0xa9, 0x75, 0x6e,
    0xad, 0xd5, 0xba, 0x8f, 0xf8,

    /* U+6E7F "湿" */
    0x4, 0x36, 0x7e, 0x24, 0x20, 0x7e, 0x4, 0x20,
    0x42, 0x63, 0xc2, 0x3c, 0x33, 0xc1, 0xbf, 0x27,
    0xe6, 0x7e, 0x63, 0xc4, 0x3c, 0x4f, 0xf0,

    /* U+6EF4 "滴" */
    0x82, 0xc, 0x61, 0xff, 0x2, 0xc8, 0x78, 0xf2,
    0x9f, 0xf0, 0xd2, 0x1f, 0x43, 0x48, 0xfd, 0x3f,
    0xad, 0xf5, 0xb0, 0x86, 0x30,

    /* U+7387 "率" */
    0xc, 0x3, 0xf, 0xfc, 0x20, 0xda, 0xd5, 0xa5,
    0xd1, 0x24, 0xfe, 0xe8, 0x30, 0xc3, 0xff, 0xc,
    0x3, 0x0, 0xc0, 0x30,

    /* U+7535 "电" */
    0xc, 0x19, 0x9b, 0xff, 0x66, 0x6c, 0xcd, 0xff,
    0xb3, 0x36, 0x66, 0xcc, 0xdf, 0xfb, 0x33, 0x6,
    0x10, 0xc4, 0x18, 0x83, 0xf0,

    /* U+81EA "自" */
    0x30, 0x8, 0xe, 0x1b, 0xfe, 0xc1, 0xb0, 0x6f,
    0xfb, 0x6, 0xc1, 0xbf, 0xec, 0x1b, 0x6, 0xc1,
    0xbf, 0xec, 0x18,

    /* U+8235 "舵" */
    0x11, 0x2, 0x31, 0xeb, 0xbd, 0xe6, 0xe4, 0xf0,
    0x1a, 0x47, 0xca, 0x69, 0x4f, 0x31, 0xe4, 0x24,
    0x94, 0x93, 0x12, 0x66, 0x78,

    /* U+843D "落" */
    0x31, 0x9f, 0xfc, 0xc6, 0x0, 0x6, 0x4c, 0x5f,
    0x83, 0x36, 0x5c, 0x63, 0x8c, 0xfc, 0x70, 0xb7,
    0xe4, 0xcd, 0x99, 0xa3, 0xf0, 0x66,

    /* U+91CF "量" */
    0x60, 0xcf, 0xf9, 0x83, 0x3f, 0xe1, 0xf0, 0x0,
    0x3f, 0xf8, 0x0, 0x7f, 0xcc, 0xd9, 0xff, 0x3f,
    0xe0, 0x60, 0xff, 0xff, 0xf8,

    /* U+95F4 "间" */
    0x80, 0x4b, 0xf9, 0x3, 0x0, 0x6d, 0x2d, 0xbd,
    0xb4, 0xb6, 0xf6, 0xd2, 0xda, 0x5b, 0x7b, 0x69,
    0x6c, 0xd, 0x85, 0xb0, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 35, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 3, .adv_w = 95, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 155, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 21, .adv_w = 107, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 29, .adv_w = 184, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 143, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 48, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 56, .adv_w = 58, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 62, .adv_w = 58, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 68, .adv_w = 118, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 74, .adv_w = 143, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 83, .adv_w = 48, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 85, .adv_w = 148, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 87, .adv_w = 40, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 100, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 115, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 115, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 155, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 171, .adv_w = 30, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 43, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 174, .adv_w = 185, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 138, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 191, .adv_w = 185, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 84, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 148, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 94, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 129, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 125, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 93, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 83, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 158, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 123, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 30, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 72, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 297, .adv_w = 120, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 78, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 178, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 143, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 169, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 363, .adv_w = 108, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 107, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 100, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 122, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 143, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 220, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 118, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 125, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 118, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 48, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 445, .adv_w = 100, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 48, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 457, .adv_w = 75, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 458, .adv_w = 73, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 459, .adv_w = 48, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 461, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 89, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 99, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 65, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 104, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 506, .adv_w = 90, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 35, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 35, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 517, .adv_w = 90, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 28, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 138, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 90, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 116, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 107, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 549, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 556, .adv_w = 68, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 70, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 53, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 90, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 105, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 574, .adv_w = 160, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 110, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 113, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 596, .adv_w = 110, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 45, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 606, .adv_w = 23, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 608, .adv_w = 43, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 614, .adv_w = 86, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 616, .adv_w = 256, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 636, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 658, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 680, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 702, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 723, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 745, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 766, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 787, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 809, .adv_w = 256, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 829, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 850, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 871, .adv_w = 256, .box_w = 10, .box_h = 15, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 890, .adv_w = 256, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 909, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 930, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 951, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 972, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 994, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1015, .adv_w = 256, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1038, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1059, .adv_w = 256, .box_w = 10, .box_h = 16, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 1079, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 1100, .adv_w = 256, .box_w = 10, .box_h = 15, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 1119, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1140, .adv_w = 256, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1162, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1183, .adv_w = 256, .box_w = 11, .box_h = 15, .ofs_x = 3, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0xbf, 0x368, 0x49d, 0x5e8, 0xe44, 0xfdb, 0x104a,
    0x109b, 0x10f5, 0x11b8, 0x1765, 0x17da, 0x17eb, 0x192f, 0x1d16,
    0x1d5a, 0x1fa7, 0x201e, 0x2074, 0x20e9, 0x257c, 0x272a, 0x33df,
    0x342a, 0x3632, 0x43c4, 0x47e9
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 19979, .range_length = 18410, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 28, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/

