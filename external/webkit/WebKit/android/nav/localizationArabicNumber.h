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

#ifndef _LOCALIZATION_ARABIC_NUMBER_H_
#define _LOCALIZATION_ARABIC_NUMBER_H_

//#define _SHP_SIMUL
#ifndef _SHP_SIMUL
//#include "WmGrpType.h"
#endif
/////////////////////////////////////////////////////////////////
// define
typedef enum{
	AN_SCAN_START,
	AN_SCAN_NUM,
	AN_SCAN_UNIT_AND_PROPER_NOUN,
	AN_SCAN_IMOTICON,
	AN_SCAN_ENG,
	AN_SCAN_SPECIAL,
	AN_SCAN_DIVIDER,
	AN_SCAN_OTHER,
	AN_SCAN_SPACE,
	AN_SCAN_END
} AN_SCAN_STATE;

typedef enum{
	AN_SYNTAX_NUM,
	AN_SYNTAX_UNIT,
	AN_SYNTAX_PROPER_NOUN,
	AN_SYNTAX_IMOTICON,
	AN_SYNTAX_ENG,
	AN_SYNTAX_SPECIAL,
	AN_SYNTAX_DIVIDER,
	AN_SYNTAX_OTHER, 
	AN_SYNTAX_SPACE,
	AN_SYNTAX_NULL,
} AN_SYNTAX;

typedef struct{
	int iStart;
	int iEnd;
	AN_SYNTAX eSyntax;
} AN_STRUCT_SYNTAX;

typedef enum{
	AN_PARSER_NONE = 0,
	AN_PARSER_START,
	AN_PARSER_NUM,
	AN_PARSER_NUM_DIVIDER,
	AN_PARSER_SPACE_CHECK,
	AN_PARSER_ENG,
} AN_PARSER_STATE;

// EX, IMO 시작부분이 둘다 매칭이 되는 경우 : EX CHECK, IMO CHECK > IMO CHECK > NO CHECK 순으로 실행
typedef enum{
	NO_CHECK_EX_IMO = 0x0,
	CHECK_EX = 0x1,
	CHECK_IMO = 0x2,
	CHECK_EX_IMO = 0x3
} CHECK_EXCEPTION_TYPE;

#define NUM_OF_UNIT	7
#define NUM_OF_PROPER_NOUN	10
#define NUM_OF_IMOTICON	10
#define NUM_OF_EXCEPTION (NUM_OF_UNIT+NUM_OF_PROPER_NOUN)
#define MAX_SIZE_OF_EXCEPTION_STRING	6
#if 0 //def _SHP_SIMUL
typedef enum {
	NUMBER_DISPLAY_NO,							// 아랍넘버 디스플레이 하지 않음
	NUMBER_DISPLAY_CHECK_LTR,				// 문장에 영문등이 있으면 디스플레이 하지 않음
	NUMBER_DISPLAY_CHECK_LANGUAGE,		// 영문등(아랍 아닌) 뒤쪽 디스플레이 하지 않음
	NUMBER_DISPLAY_CHECK_WORD,			// 제외 문자외 모두 디스플레이(디폴트)
	NUMBER_DISPLAY_ALL							// 언제나 디스플레이
} WmNumberDisplay;

#define UINT8	BYTE
#define UINT16	BYTE
#define AN_LPTSTR	LPTSTR
#define AN_STR TCHAR
#else
#define AN_LPTSTR	UINT16*
#define AN_STR UINT16
#endif
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// define functions
//void ChangeArabicNumber(AN_LPTSTR u16Str, int length, WmNumberDisplay check);
//AN_STRUCT_SYNTAX ArabicNumberScanner(AN_LPTSTR u16Str, int iIndex, int length, CHECK_EXCEPTION_TYPE CheckException);

#endif // _LOCALIZATION_ARABIC_NUMBER_H_
