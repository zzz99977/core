/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

// Partial ICU replacement for iOS and OS X

#include <stdlib.h>

#import <CoreFoundation/CFString.h>

#include <unicode/locid.h>
#include <unicode/uchar.h>
#include <unicode/ubidi.h>

#ifndef __IPHONE_OS_VERSION_MIN_REQUIRED

#define G_UNICODE_CONTROL U_CONTROL_CHAR
#define G_UNICODE_FORMAT U_FORMAT_CHAR
#define G_UNICODE_UNASSIGNED U_UNASSIGNED
#define G_UNICODE_PRIVATE_USE U_PRIVATE_USE_CHAR
#define G_UNICODE_SURROGATE U_SURROGATE
#define G_UNICODE_LOWERCASE_LETTER U_LOWERCASE_LETTER
#define G_UNICODE_MODIFIER_LETTER U_MODIFIER_LETTER
#define G_UNICODE_OTHER_LETTER U_OTHER_LETTER
#define G_UNICODE_TITLECASE_LETTER U_TITLECASE_LETTER
#define G_UNICODE_UPPERCASE_LETTER U_UPPERCASE_LETTER
#define G_UNICODE_SPACING_MARK U_COMBINING_SPACING_MARK
#define G_UNICODE_ENCLOSING_MARK U_ENCLOSING_MARK
#define G_UNICODE_NON_SPACING_MARK U_NON_SPACING_MARK
#define G_UNICODE_DECIMAL_NUMBER U_DECIMAL_DIGIT_NUMBER
#define G_UNICODE_LETTER_NUMBER U_LETTER_NUMBER
#define G_UNICODE_OTHER_NUMBER U_OTHER_NUMBER
#define G_UNICODE_CONNECT_PUNCTUATION U_CONNECTOR_PUNCTUATION
#define G_UNICODE_DASH_PUNCTUATION U_DASH_PUNCTUATION
#define G_UNICODE_CLOSE_PUNCTUATION U_END_PUNCTUATION
#define G_UNICODE_FINAL_PUNCTUATION U_FINAL_PUNCTUATION
#define G_UNICODE_INITIAL_PUNCTUATION U_INITIAL_PUNCTUATION
#define G_UNICODE_OTHER_PUNCTUATION U_OTHER_PUNCTUATION
#define G_UNICODE_OPEN_PUNCTUATION U_START_PUNCTUATION
#define G_UNICODE_CURRENCY_SYMBOL U_CURRENCY_SYMBOL
#define G_UNICODE_MODIFIER_SYMBOL U_MODIFIER_SYMBOL
#define G_UNICODE_MATH_SYMBOL U_MATH_SYMBOL
#define G_UNICODE_OTHER_SYMBOL U_OTHER_SYMBOL
#define G_UNICODE_LINE_SEPARATOR U_LINE_SEPARATOR
#define G_UNICODE_PARAGRAPH_SEPARATOR U_PARAGRAPH_SEPARATOR
#define G_UNICODE_SPACE_SEPARATOR U_SPACE_SEPARATOR

typedef char gchar;
typedef int16_t gint16;
typedef uint16_t guint16;
typedef uint32_t gunichar;

#include "gunichartables.h"

#endif

using namespace icu;

// locid.h

Locale::Locale() :
    m_localeRef(NULL)
{
}

Locale::Locale(const char *language,
               const char *country,
               const char *variant,
               const char * /* keywordsAndValues */)
{
    CFMutableStringRef identifier = CFStringCreateMutable(NULL, 0);

    CFStringAppendCString(identifier, language, kCFStringEncodingUTF8);

    if (country) {
        CFStringAppendCString(identifier, "_", kCFStringEncodingUTF8);
        CFStringAppendCString(identifier, country, kCFStringEncodingUTF8);

        if (variant) {
            CFStringAppendCString(identifier, "_", kCFStringEncodingUTF8);
            CFStringAppendCString(identifier, variant, kCFStringEncodingUTF8);
        }
    }

    m_localeRef = CFLocaleCreate(NULL, identifier);

    CFRelease(identifier);
}

Locale::~Locale()
{
    if (m_localeRef)
        CFRelease(m_localeRef);
}

Locale Locale::createFromName(const char *name)
{
    return Locale(name);
}

// uchar.h

UBool u_isalpha(UChar32 c)
{
    return CFCharacterSetIsLongCharacterMember(CFCharacterSetGetPredefined(kCFCharacterSetLetter), c);
}

UBool u_ispunct(UChar32 c)
{
    return CFCharacterSetIsLongCharacterMember(CFCharacterSetGetPredefined(kCFCharacterSetPunctuation), c);
}

UBool u_isWhitespace(UChar32 c)
{
    return ((c != 0x00A0 &&
             c != 0x2007 &&
             c != 0x202F &&
             CFCharacterSetIsLongCharacterMember(CFCharacterSetGetPredefined(kCFCharacterSetWhitespaceAndNewline), c)) ||
            (c >= 0x001C && c <= 0x001F));
}

int8_t u_charType(UChar32 c)
{
#ifndef __IPHONE_OS_VERSION_MIN_REQUIRED
    if (c <= G_UNICODE_LAST_CHAR_PART1) {
        const int page = (c >> 8);
        if (type_table_part1[page] >= G_UNICODE_MAX_TABLE_INDEX)
            return type_table_part1[page] - G_UNICODE_MAX_TABLE_INDEX;
        else
            return type_data[type_table_part1[page]][c & 0xFF];
    } else if (c >= 0xE0000 && c <= G_UNICODE_LAST_CHAR) {
        const int page = ((c - 0xE0000) >> 8);
        if (type_table_part2[page] >= G_UNICODE_MAX_TABLE_INDEX)
            return type_table_part2[page] - G_UNICODE_MAX_TABLE_INDEX;
        else
            return type_data[type_table_part2[page]][c & 0xFF];
    } else {
        return G_UNICODE_UNASSIGNED;
    }
#else
#undef u_charType
    extern extern "C" int8_t u_charType(UChar32 c);
    return u_charType(c);
#endif
}

UCharDirection
u_charDirection(UChar32 c)
{
    (void) c;

    return U_OTHER_NEUTRAL;
}

UChar32
u_charMirror(UChar32 c)
{
    (void) c;

    return 0;
}

// ubidi.h

UBiDi *
ubidi_openSized(int32_t maxLength,
                int32_t maxRunCount,
                UErrorCode *pErrorCode)
{
    (void) maxLength;
    (void) maxRunCount;
    (void) pErrorCode;

    return NULL;
}

void
ubidi_setLine(const UBiDi *pParaBiDi,
              int32_t start,
              int32_t limit,
              UBiDi *pLineBiDi,
              UErrorCode *pErrorCode)
{
    (void) pParaBiDi;
    (void) start;
    (void) limit;
    (void) pLineBiDi;
    (void) pErrorCode;
}

void
ubidi_setPara(UBiDi *pBiDi,
              const UChar *text,
              int32_t length,
              UBiDiLevel paraLevel,
              UBiDiLevel *embeddingLevels,
              UErrorCode *pErrorCode)
{
    (void) pBiDi;
    (void) text;
    (void) length;
    (void) paraLevel;
    (void) embeddingLevels;
    (void) pErrorCode;
}

int32_t
ubidi_countRuns(UBiDi *pBiDi,
                UErrorCode *pErrorCode)
{
    (void) pBiDi;
    (void) pErrorCode;

    return 0;
}

void
ubidi_getLogicalRun(const UBiDi *pBiDi,
                    int32_t logicalPosition,
                    int32_t *pLogicalLimit,
                    UBiDiLevel *pLevel)
{
    (void) pBiDi;
    (void) logicalPosition;
    (void) pLogicalLimit;
    (void) pLevel;
}

UBiDiDirection
ubidi_getVisualRun(UBiDi *pBiDi,
                   int32_t runIndex,
                   int32_t *pLogicalStart,
                   int32_t *pLength)
{
    (void) pBiDi;
    (void) runIndex;
    (void) pLogicalStart;
    (void) pLength;

    return UBIDI_NEUTRAL;
}

void
ubidi_close(UBiDi *pBiDi)
{
    (void) pBiDi;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
