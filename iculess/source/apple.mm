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

using namespace icu;

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

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
