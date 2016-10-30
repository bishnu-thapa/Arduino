
#include <avr/pgmspace.h>

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

//using namespace std;

#define byte uint8_t

#define OP_NOOP         0
#define OP_DECODEMODE   9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

const unsigned char powers[] = {1,2,4,8,16,32,64,128};

const byte standardFontData[] PROGMEM = 
       
    {0x00, 0x00, 0x00, 0x00, 0x00, // (Code 000) DONT USER THIS CODE FOR CUSTOMISATION....
     0x00, 0x06, 0x09, 0x09, 0x06, // (Code 001) Degree Symbol
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 002)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 003)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 004)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 005)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 006)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 007)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 008)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 009)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 010)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 011)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 012)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 013)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 014)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 015)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 016)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 017)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 018)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 019)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 020)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 021)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 022)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 023)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 024)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 025)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 026)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 027)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 028)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 029)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 030)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 031)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 032) (space)
     0x00, 0x00, 0x5F, 0x00, 0x00, // (Code 033) !
     0x00, 0x07, 0x00, 0x07, 0x00, // (Code 034) "
     0x14, 0x7F, 0x14, 0x7F, 0x14, // (Code 035) #
     0x24, 0x2A, 0x7F, 0x2A, 0x12, // (Code 036) $
     0x23, 0x13, 0x08, 0x64, 0x62, // (Code 037) %
     0x36, 0x49, 0x55, 0x22, 0x50, // (Code 038) &
     0x00, 0x05, 0x03, 0x00, 0x00, // (Code 039) '
     0x00, 0x1C, 0x22, 0x41, 0x00, // (Code 040) (
     0x00, 0x41, 0x22, 0x1C, 0x00, // (Code 041) )
     0x08, 0x2A, 0x1C, 0x2A, 0x08, // (Code 042) *
     0x08, 0x08, 0x3E, 0x08, 0x08, // (Code 043) +
     0x00, 0x50, 0x30, 0x00, 0x00, // (Code 044) ,
     0x08, 0x08, 0x08, 0x08, 0x08, // (Code 045) -
     0x00, 0x60, 0x60, 0x00, 0x00, // (Code 046) .
     0x20, 0x10, 0x08, 0x04, 0x02, // (Code 047) /
     0x3E, 0x51, 0x49, 0x45, 0x3E, // (Code 048) 0
     0x00, 0x42, 0x7F, 0x40, 0x00, // (Code 049) 1
     0x42, 0x61, 0x51, 0x49, 0x46, // (Code 050) 2
     0x21, 0x41, 0x45, 0x4B, 0x31, // (Code 051) 3
     0x18, 0x14, 0x12, 0x7F, 0x10, // (Code 052) 4
     0x27, 0x45, 0x45, 0x45, 0x39, // (Code 053) 5
     0x3C, 0x4A, 0x49, 0x49, 0x30, // (Code 054) 6
     0x01, 0x71, 0x09, 0x05, 0x03, // (Code 055) 7
     0x36, 0x49, 0x49, 0x49, 0x36, // (Code 056) 8
     0x06, 0x49, 0x49, 0x29, 0x1E, // (Code 057) 9
     0x00, 0x36, 0x36, 0x00, 0x00, // (Code 058) :
     0x00, 0x56, 0x36, 0x00, 0x00, // (Code 059) ;
     0x00, 0x08, 0x14, 0x22, 0x41, // (Code 060) <
     0x14, 0x14, 0x14, 0x14, 0x14, // (Code 061) =
     0x41, 0x22, 0x14, 0x08, 0x00, // (Code 062) >
     0x02, 0x01, 0x51, 0x09, 0x06, // (Code 063) ?
     0x32, 0x49, 0x79, 0x41, 0x3E, // (Code 064) @
     0x7E, 0x11, 0x11, 0x11, 0x7E, // (Code 065) A
     0x7F, 0x49, 0x49, 0x49, 0x36, // (Code 066) B
     0x3E, 0x41, 0x41, 0x41, 0x22, // (Code 067) C
     0x7F, 0x41, 0x41, 0x22, 0x1C, // (Code 068) D
     0x7F, 0x49, 0x49, 0x49, 0x41, // (Code 069) E
     0x7F, 0x09, 0x09, 0x01, 0x01, // (Code 070) F
     0x3E, 0x41, 0x41, 0x51, 0x32, // (Code 071) G
     0x7F, 0x08, 0x08, 0x08, 0x7F, // (Code 072) H
     0x00, 0x41, 0x7F, 0x41, 0x00, // (Code 073) I
     0x20, 0x40, 0x41, 0x3F, 0x01, // (Code 074) J
     0x7F, 0x08, 0x14, 0x22, 0x41, // (Code 075) K
     0x7F, 0x40, 0x40, 0x40, 0x40, // (Code 076) L
     0x7F, 0x02, 0x04, 0x02, 0x7F, // (Code 077) M
     0x7F, 0x04, 0x08, 0x10, 0x7F, // (Code 078) N
     0x3E, 0x41, 0x41, 0x41, 0x3E, // (Code 079) O
     0x7F, 0x09, 0x09, 0x09, 0x06, // (Code 080) P
     0x3E, 0x41, 0x51, 0x21, 0x5E, // (Code 081) Q
     0x7F, 0x09, 0x19, 0x29, 0x46, // (Code 082) R
     0x46, 0x49, 0x49, 0x49, 0x31, // (Code 083) S
     0x01, 0x01, 0x7F, 0x01, 0x01, // (Code 084) T
     0x3F, 0x40, 0x40, 0x40, 0x3F, // (Code 085) U
     0x1F, 0x20, 0x40, 0x20, 0x1F, // (Code 086) V
     0x7F, 0x20, 0x18, 0x20, 0x7F, // (Code 087) W
     0x63, 0x14, 0x08, 0x14, 0x63, // (Code 088) X
     0x03, 0x04, 0x78, 0x04, 0x03, // (Code 089) Y
     0x61, 0x51, 0x49, 0x45, 0x43, // (Code 090) Z
     0x00, 0x00, 0x7F, 0x41, 0x41, // (Code 091) [
     0x02, 0x04, 0x08, 0x10, 0x20, // (Code 092) 
     0x41, 0x41, 0x7F, 0x00, 0x00, // (Code 093) ]
     0x04, 0x02, 0x01, 0x02, 0x04, // (Code 094) ^
     0x40, 0x40, 0x40, 0x40, 0x40, // (Code 095) _
     0x00, 0x01, 0x02, 0x04, 0x00, // (Code 096) `
     0x20, 0x54, 0x54, 0x54, 0x78, // (Code 097) a
     0x7F, 0x48, 0x44, 0x44, 0x38, // (Code 098) b
     0x38, 0x44, 0x44, 0x44, 0x20, // (Code 099) c
     0x38, 0x44, 0x44, 0x48, 0x7F, // (Code 100) d
     0x38, 0x54, 0x54, 0x54, 0x18, // (Code 101) e
     0x08, 0x7E, 0x09, 0x01, 0x02, // (Code 102) f
     0x08, 0x14, 0x54, 0x54, 0x3C, // (Code 103) g
     0x7F, 0x08, 0x04, 0x04, 0x78, // (Code 104) h
     0x00, 0x44, 0x7D, 0x40, 0x00, // (Code 105) i
     0x20, 0x40, 0x44, 0x3D, 0x00, // (Code 106) j
     0x00, 0x7F, 0x10, 0x28, 0x44, // (Code 107) k
     0x00, 0x41, 0x7F, 0x40, 0x00, // (Code 108) l
     0x7C, 0x04, 0x18, 0x04, 0x78, // (Code 109) m
     0x7C, 0x08, 0x04, 0x04, 0x78, // (Code 110) n
     0x38, 0x44, 0x44, 0x44, 0x38, // (Code 111) o
     0x7C, 0x14, 0x14, 0x14, 0x08, // (Code 112) p
     0x08, 0x14, 0x14, 0x18, 0x7C, // (Code 113) q
     0x7C, 0x08, 0x04, 0x04, 0x08, // (Code 114) r
     0x48, 0x54, 0x54, 0x54, 0x20, // (Code 115) s
     0x04, 0x3F, 0x44, 0x40, 0x20, // (Code 116) t
     0x3C, 0x40, 0x40, 0x20, 0x7C, // (Code 117) u
     0x1C, 0x20, 0x40, 0x20, 0x1C, // (Code 118) v
     0x3C, 0x40, 0x30, 0x40, 0x3C, // (Code 119) w
     0x44, 0x28, 0x10, 0x28, 0x44, // (Code 120) x
     0x0C, 0x50, 0x50, 0x50, 0x3C, // (Code 121) y
     0x44, 0x64, 0x54, 0x4C, 0x44, // (Code 122) z
     0x00, 0x08, 0x36, 0x41, 0x00, // (Code 123) "{"
     0x00, 0x00, 0x7F, 0x00, 0x00, // (Code 124) |
     0x00, 0x41, 0x36, 0x08, 0x00, // (Code 125) "}"
     0x08, 0x08, 0x2A, 0x1C, 0x08, // (Code 126) ->
     0x08, 0x1C, 0x2A, 0x08, 0x08, // (Code 127) <-
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 128)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 129)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 130)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 131)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 132)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 133)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 134)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 135)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 136)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 137)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 138)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 139)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 140)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 141)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 142)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 143)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 144)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 145)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 146)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 147)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 148)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 149)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 150)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 151)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 152)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 153)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 154)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 155)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 156)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 157)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 158)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 159)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 160)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 161)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 162)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 163)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 164)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 165)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 166)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 167)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 168)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 169)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 170)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 171)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 172)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 173)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 174)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 175)
     0x00, 0x60, 0x90, 0x90, 0x60, // (Code 176)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 177)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 178)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 179)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 180)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 181)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 182)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 183)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 184)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 185)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 186)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 187)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 188)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 189)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 190)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 191)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 192)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 193)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 194)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 195)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 196)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 197)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 198)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 199)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 200)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 201)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 202)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 203)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 204)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 205)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 206)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 207)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 208)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 209)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 210)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 211)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 212)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 213)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 214)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 215)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 216)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 217)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 218)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 219)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 220)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 221)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 222)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 223)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 224)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 225)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 226)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 227)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 228)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 229)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 230)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 231)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 232)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 233)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 234)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 235)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 236)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 237)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 238)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 239)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 240)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 241)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 242)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 243)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 244)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 245)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 246)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 247)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 248)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 249)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 250)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 251)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 252)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 253)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 254)
     0x00, 0x00, 0x00, 0x00, 0x00, // (Code 255)
     } ;

class MaxScroll 

    {

    private:

        int pinCS;                     // Chip Selection Pin
        int pinDIN;                    // Data IN Pin
        int pinCLK;                    // Data Clock Pin
        int noOfDevices;               // Number of Devices in chain

        void command(byte opcode, byte data);

    public:

        MaxScroll(int pinCS,int pinDIN,int pinCLK,int noOfDevices);
        void setNormalMode();
        void setTestMode();
        void setStateStartup();
        void setStateShutdown();
        void setDecodeMode(volatile byte mode);
        void setDisplayScanLimit(volatile byte limit);
        void setIntensity(volatile byte intensity);
        void print(int offset,const char *displayText);
    };

int getPixelWidthOfString(const char *string);