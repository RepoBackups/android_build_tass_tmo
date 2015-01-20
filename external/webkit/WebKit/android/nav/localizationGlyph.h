/* 
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOCALIZATION_GLYPH_H
#define _LOCALIZATION_GLYPH_H


typedef unsigned short u16;
typedef unsigned char u8;
#define UINT8 u8
#define UINT16 u16

#define NUMBER_OF_NONBINDING_CHAR   19 //우르드 독립글자도 포함된 최종 갯수
#define RtkGetMemory 		malloc
#define RtkReleaseMemory	free
#define GetCurrentTextLanguage	LocGetLanguage

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif

 

#include "localization.hit"
#include "localization_glyph.hiv"
//#include "MemMgr.h"

void getCharInfo(u16 inChar, t_CharDefine *charInfo);
u8 isLigarture ( u16 curChar, u16 nextChar, u16 *isolated, u16 *initial, u16 *medial, u16 *final );
u8 isTransformArabic ( u16 inChar );
int ConvertToGlyphForm(u16 * inStr, int length, int flagDigit);

int hasArabicLetters(unsigned short * text, int length);
int isArabicChar(unsigned short isArabChar);
int isLigartureCharacter( u16 curChar, u16 nextChar); 

//#if defined(_SHP_LANG_ARABIC) || defined(_SHP_MIDASIA_DEV) 
int CheckNeedToTranslateNumber(void);
UINT8 checkAlpha(UINT16 ch, int num);
//#ifndef _SHP_ARABIC_NUMBER_DISPLAY
int UTF8DecodeOneChar( char *InString, UINT16 *OutString );
void ChangeDigitToArabicNumberUTF8(char *utf8Str);
void ChangeDigitToArabicNumberCheckAllUTF8(char * utf8Str, int length, int checkLTR, int checkEngWord);
//#endif
//#ifndef _SHP_ARABIC_NUMBER_DISPLAY
void ChangeDigitToArabicNumberCheckAllU16(UINT16 *u16Str, int length, int checkLTR, int checkEngWord);
void ChangeArabicToDigitNumber(UINT16 *u16Str, int length);
//#else
void ChangeDigitToArabicNumberCheckAllU16(UINT16 *u16Str, int length, int check);
//#endif
//#ifndef _SHP_ARABIC_NUMBER_DISPLAY
void ChangeDigitToArabicNumber(char *utf8Str);
void ChangeDigitToArabicNumberCheckLTR(char *utf8Str);
void ChangeDigitToArabicNumberUTF8SkipCheckTL(char* strUTF8);
//#endif
void ChangeDigitToArabicNumberU16SkipCheckTL(UINT16* strU16);
//#ifndef _SHP_ARABIC_NUMBER_DISPLAY
void ChangeDigitToArabicNumberStrongUTF8SkipCheckTL(char* strUTF8);
void ChangeDigitToArabicNumberStrongU16SkipCheckTL(UINT16* strU16);
//#endif
//#endif

#endif
