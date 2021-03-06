
#include "LedControlMS.h"
#include <avr/pgmspace.h>

#define M_CLK    7
#define M_CS     6
#define M_DIN    5

LedControl lc = LedControl(M_DIN,M_CLK,M_CS,1);

const uint8_t heart[][8] PROGMEM =  {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
                                     {0x7e,0x7e,0x18,0x18,0x18,0x18,0x7e,0x7e},
                                     {0x7e,0x7e,0x18,0x18,0x18,0x18,0x7e,0x7e},
                                     {0x00,0x66,0xff,0xff,0x7e,0x3c,0x18,0x00},
                                     {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
                                     {0x00,0x66,0xff,0xff,0x7e,0x3c,0x18,0x00},
                                     {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
                                     {0x00,0x66,0xff,0xff,0x7e,0x3c,0x18,0x00},
                                     {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
                                     {0x00,0x66,0xff,0xff,0x7e,0x3c,0x18,0x00},
                                     {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x3c},
                                     {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x3c}
                                     };
//uint8_t heart[] = {0x00,0xff,0x00,0xff,0x02,0x02,0x02,0x0};

const uint8_t font[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00,// (space)
                                0x00, 0x00, 0x5F, 0x00, 0x00,// !
                                0x00, 0x07, 0x00, 0x07, 0x00,// "
                                0x14, 0x7F, 0x14, 0x7F, 0x14,// #
                                0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
                                0x23, 0x13, 0x08, 0x64, 0x62,// %
                                0x36, 0x49, 0x55, 0x22, 0x50,// &
                                0x00, 0x05, 0x03, 0x00, 0x00,// '
                                0x00, 0x1C, 0x22, 0x41, 0x00,// (
                                0x00, 0x41, 0x22, 0x1C, 0x00,// )
                                0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
                                0x08, 0x08, 0x3E, 0x08, 0x08,// +
                                0x00, 0x50, 0x30, 0x00, 0x00,// ,
                                0x08, 0x08, 0x08, 0x08, 0x08,// -
                                0x00, 0x60, 0x60, 0x00, 0x00,// .
                                0x20, 0x10, 0x08, 0x04, 0x02,// /
                                0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
                                0x00, 0x42, 0x7F, 0x40, 0x00,// 1
                                0x42, 0x61, 0x51, 0x49, 0x46,// 2
                                0x21, 0x41, 0x45, 0x4B, 0x31,// 3
                                0x18, 0x14, 0x12, 0x7F, 0x10,// 4
                                0x27, 0x45, 0x45, 0x45, 0x39,// 5
                                0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
                                0x01, 0x71, 0x09, 0x05, 0x03,// 7
                                0x36, 0x49, 0x49, 0x49, 0x36,// 8
                                0x06, 0x49, 0x49, 0x29, 0x1E,// 9
                                0x00, 0x36, 0x36, 0x00, 0x00,// :
                                0x00, 0x56, 0x36, 0x00, 0x00,// ;
                                0x00, 0x08, 0x14, 0x22, 0x41,// <
                                0x14, 0x14, 0x14, 0x14, 0x14,// =
                                0x41, 0x22, 0x14, 0x08, 0x00,// >
                                0x02, 0x01, 0x51, 0x09, 0x06,// ?
                                0x32, 0x49, 0x79, 0x41, 0x3E,// @
                                0x7E, 0x11, 0x11, 0x11, 0x7E,// A
                                0x7F, 0x49, 0x49, 0x49, 0x36,// B
                                0x3E, 0x41, 0x41, 0x41, 0x22,// C
                                0x7F, 0x41, 0x41, 0x22, 0x1C,// D
                                0x7F, 0x49, 0x49, 0x49, 0x41,// E
                                0x7F, 0x09, 0x09, 0x01, 0x01,// F
                                0x3E, 0x41, 0x41, 0x51, 0x32,// G
                                0x7F, 0x08, 0x08, 0x08, 0x7F,// H
                                0x00, 0x41, 0x7F, 0x41, 0x00,// I
                                0x20, 0x40, 0x41, 0x3F, 0x01,// J
                                0x7F, 0x08, 0x14, 0x22, 0x41,// K
                                0x7F, 0x40, 0x40, 0x40, 0x40,// L
                                0x7F, 0x02, 0x04, 0x02, 0x7F,// M
                                0x7F, 0x04, 0x08, 0x10, 0x7F,// N
                                0x3E, 0x41, 0x41, 0x41, 0x3E,// O
                                0x7F, 0x09, 0x09, 0x09, 0x06,// P
                                0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
                                0x7F, 0x09, 0x19, 0x29, 0x46,// R
                                0x46, 0x49, 0x49, 0x49, 0x31,// S 
                                0x01, 0x01, 0x7F, 0x01, 0x01,// T
                                0x3F, 0x40, 0x40, 0x40, 0x3F,// U
                                0x1F, 0x20, 0x40, 0x20, 0x1F,// V
                                0x7F, 0x20, 0x18, 0x20, 0x7F,// W
                                0x63, 0x14, 0x08, 0x14, 0x63,// X
                                0x03, 0x04, 0x78, 0x04, 0x03,// Y
                                0x61, 0x51, 0x49, 0x45, 0x43,// Z
                                0x00, 0x00, 0x7F, 0x41, 0x41,// [
                                0x02, 0x04, 0x08, 0x10, 0x20,// "\" 
                                0x41, 0x41, 0x7F, 0x00, 0x00,// ]
                                0x04, 0x02, 0x01, 0x02, 0x04,// ^
                                0x40, 0x40, 0x40, 0x40, 0x40,// _
                                0x00, 0x01, 0x02, 0x04, 0x00,// `
                                0x20, 0x54, 0x54, 0x54, 0x78,// a
                                0x7F, 0x48, 0x44, 0x44, 0x38,// b
                                0x38, 0x44, 0x44, 0x44, 0x20,// c
                                0x38, 0x44, 0x44, 0x48, 0x7F,// d
                                0x38, 0x54, 0x54, 0x54, 0x18,// e
                                0x08, 0x7E, 0x09, 0x01, 0x02,// f
                                0x08, 0x14, 0x54, 0x54, 0x3C,// g
                                0x7F, 0x08, 0x04, 0x04, 0x78,// h
                                0x00, 0x44, 0x7D, 0x40, 0x00,// i
                                0x20, 0x40, 0x44, 0x3D, 0x00,// j
                                0x00, 0x7F, 0x10, 0x28, 0x44,// k
                                0x00, 0x41, 0x7F, 0x40, 0x00,// l
                                0x7C, 0x04, 0x18, 0x04, 0x78,// m
                                0x7C, 0x08, 0x04, 0x04, 0x78,// n
                                0x38, 0x44, 0x44, 0x44, 0x38,// o
                                0x7C, 0x14, 0x14, 0x14, 0x08,// p
                                0x08, 0x14, 0x14, 0x18, 0x7C,// q
                                0x7C, 0x08, 0x04, 0x04, 0x08,// r
                                0x48, 0x54, 0x54, 0x54, 0x20,// s
                                0x04, 0x3F, 0x44, 0x40, 0x20,// t
                                0x3C, 0x40, 0x40, 0x20, 0x7C,// u
                                0x1C, 0x20, 0x40, 0x20, 0x1C,// v
                                0x3C, 0x40, 0x30, 0x40, 0x3C,// w
                                0x44, 0x28, 0x10, 0x28, 0x44,// x
                                0x0C, 0x50, 0x50, 0x50, 0x3C,// y
                                0x44, 0x64, 0x54, 0x4C, 0x44,// z
                                0x00, 0x08, 0x36, 0x41, 0x00,// {
                                0x00, 0x00, 0x7F, 0x00, 0x00,// |
                                0x00, 0x41, 0x36, 0x08, 0x00,// }
                                0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
                                0x08, 0x1C, 0x2A, 0x08, 0x08,// <-
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 128)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 129)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 130)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 131)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 132)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 133)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 134)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 135)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 136)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 137)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 138)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 139)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 140)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 141)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 142)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 143)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 144)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 145)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 146)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 147)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 148)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 149)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 150)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 151)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 152)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 153)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 154)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 155)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 156)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 157)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 158)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 159)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 160)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 161)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 162)
                                0x48, 0x3e, 0x49, 0x49, 0x20,// £ (code 163)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 164)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 165)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 166)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 167)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 168)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 169)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 170)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 171)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 172)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 173)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 174)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 175)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 176)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 177)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 178)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 179)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 180)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 181)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 182)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 183)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 184)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 185)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 186)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 187)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 188)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 189)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 190)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 191)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 192)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 193)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 194)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 195)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 196)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 197)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 198)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 199)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 200)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 201)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 202)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 203)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 204)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 205)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 206)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 207)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 208)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 209)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 210)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 211)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 212)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 213)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 214)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 215)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 216)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 217)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 218)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 219)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 220)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 221)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 222)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 223)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 224)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 225)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 226)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 227)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 228)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 229)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 230)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 231)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 232)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 233)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 234)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 235)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 236)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 237)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 238)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 239)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 240)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 241)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 242)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 243)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 244)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 245)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 246)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 247)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 248)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 249)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 250)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 251)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 252)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 253)
                                0x00, 0x00, 0x00, 0x00, 0x00,//   (code 254)
                                0x00, 0x00, 0x00, 0x00, 0x00 //   (code 255)
                                };
    
    
//const uint8_t txt_message1[] PROGMEM =  {" Congratulations! you have managed to complete the first phase of the Torbay TechJam mini matrix sign builder workshop at Paignton Library    "};

//const uint8_t txt_message1[] PROGMEM =  {" Welcome to the Paignton Library Tech Jam 9th April 2016. Sign up for our mini matrix sign building workshop and you could build a mini matrix sign like this one for £15.    "};

const uint8_t txt_message1[] PROGMEM =  {"   Welcome to the September Tech jam,  "};

//const uint8_t txt_message1[] PROGMEM =  {"   Sherwell  Valley  Primary  School - Digital   Leaders  Club,  "};

//const uint8_t txt_message1[] PROGMEM =  {"   Priory School - Year 4 - Computer project demonstration  "};


void bitmap(const uint8_t * ptr)
    {
    for(int row=0;row<8;row++)
        for(int col=0;col<8;col++)
          if(  (pgm_read_byte_near(ptr + row) & (128 >> col)) != 0)
               lc.setLed(0,col,7 - row,true);
          else
               lc.setLed(0,col,7 - row,false);
    }

void message(const uint8_t * ptr, const uint8_t * font, unsigned int tdelay)
    {
    uint8_t mcounter = 0;
    uint8_t mptr;
    uint8_t fptr;
    
    do
        {
        mptr = pgm_read_byte_near(ptr+mcounter);
        if(mptr != 0)
            {
            for(int fcounter=0;fcounter<5;fcounter++)
                {
                fptr = pgm_read_byte_near(font+((mptr-32)*5)+fcounter);
                for(int i=0;i<8;i++)
                    if((fptr & (128 >> i)) !=0)
                        lc.setLed(0,fcounter+1,i,true);
                    else
                        lc.setLed(0,fcounter+1,i,false);
                }
            }
        mcounter++;
        delay(tdelay); 
        }
        while(mptr !=0 );
    }
    
unsigned int calculate_length(const uint8_t * ptr)
    {
    unsigned int counter = 0;
    
    while(pgm_read_byte_near(ptr+counter) != 0)
        counter++;
        
    return(counter);
    }
    
void message_scroll(const uint8_t * ptr, const uint8_t * font, unsigned int tdelay)
    {
    uint8_t  mcounter = 0;
    uint8_t  mptr[3];
    uint8_t  fptr[15];
    
    unsigned int length = calculate_length(ptr); 
    unsigned int ccounter;
    
    for(ccounter=0;ccounter < (length - 1); ccounter++)
        {
          
        mptr[0] = pgm_read_byte_near(ptr+ccounter);
        mptr[1] = pgm_read_byte_near(ptr+((ccounter+1) % length));
        mptr[2] = pgm_read_byte_near(ptr+((ccounter+2) % length));
        
        for(int fcounter=0;fcounter<5;fcounter++)
            {
            fptr[fcounter]    = pgm_read_byte_near(font + ((mptr[0] - 32) * 5)+fcounter);
            fptr[fcounter+5]  = pgm_read_byte_near(font + ((mptr[1] - 32) * 5)+fcounter);
            fptr[fcounter+10] = pgm_read_byte_near(font + ((mptr[2] - 32) * 5)+fcounter);
            }
            
        for(int letter=0;letter<5;letter++)
            {    
            for(int fcounter=0;fcounter<8;fcounter++)
                {
                for(int i=0;i<8;i++)
                    if((fptr[fcounter + letter] & (128 >> i)) != 0)
                        lc.setLed(0,fcounter,i,true);
                    else
                        lc.setLed(0,fcounter,i,false);
                }
                    
            delay(tdelay);    
            } 
        }
    }

void setup()
    {
    // the zero refers to the MAX7219 number, it is zero for 1 chip
    lc.shutdown(0,false);// turn off power saving, enables display
    lc.setIntensity(0,1);// sets brightness (0~15 possible values)
    lc.clearDisplay(0);// clear screen
    
    for(int row=0;row<8;row++)
       for(int col=0;col<8;col++)
           lc.setLed(0,col,row,false);
    delay(2000);
    
    Serial.begin(9600);
    Serial.print("£\n");
    Serial.print('£',DEC);
    }

void loop()
    {
    message_scroll(txt_message1,font,60);
    }
