/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include <com/sun/star/i18n/UnicodeScript.hpp>
#include <com/sun/star/i18n/UnicodeType.hpp>
#include <com/sun/star/i18n/KCharacterType.hpp>
#include <comphelper/string.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <unicode/uchar.h>

#include <cclass_apple.hxx>

using namespace ::com::sun::star::uno;
using namespace ::com::sun::star::lang;

namespace com { namespace sun { namespace star { namespace i18n {

cclass_Apple::cclass_Apple( const uno::Reference < XComponentContext >& rxContext )
{
    (void) rxContext;
}

cclass_Apple::~cclass_Apple()
{
}

OUString
cclass_Apple::toUpper( const OUString& Text,
                       sal_Int32 nPos,
                       sal_Int32 nCount,
                       const Locale& rLocale )
    throw(RuntimeException)
{
    (void) rLocale;

    sal_Int32 len = Text.getLength();
    if (nPos >= len)
        return OUString();
    if (nCount + nPos > len)
        nCount = len - nPos;

    return OUString();
}

OUString
cclass_Apple::toLower( const OUString& Text,
                       sal_Int32 nPos,
                       sal_Int32 nCount,
                       const Locale& rLocale )
    throw(RuntimeException)
{
    (void) rLocale;

    sal_Int32 len = Text.getLength();
    if (nPos >= len)
        return OUString();
    if (nCount + nPos > len)
        nCount = len - nPos;

    return OUString();
}

OUString
cclass_Apple::toTitle( const OUString& Text,
                       sal_Int32 nPos,
                       sal_Int32 nCount,
                       const Locale& rLocale )
    throw(RuntimeException)
{
    (void) rLocale;

    sal_Int32 len = Text.getLength();
    if (nPos >= len)
        return OUString();
    if (nCount + nPos > len)
        nCount = len - nPos;

    return OUString();
}

sal_Int16
cclass_Apple::getType( const OUString& Text,
                       sal_Int32 nPos )
    throw(RuntimeException)
{
    if ( nPos < 0 || Text.getLength() <= nPos ) return 0;
    return (sal_Int16) u_charType(Text.iterateCodePoints(&nPos, 0));
}

sal_Int16
cclass_Apple::getCharacterDirection( const OUString& Text,
                                     sal_Int32 nPos )
    throw(RuntimeException)
{
    if ( nPos < 0 || Text.getLength() <= nPos ) return 0;

    return 0;
}

sal_Int16
cclass_Apple::getScript( const OUString& Text,
                         sal_Int32 nPos )
    throw(RuntimeException)
{
    if ( nPos < 0 || Text.getLength() <= nPos ) return 0;

    return 0;
}

sal_Int32
cclass_Apple::getCharacterType( const OUString& Text,
                                sal_Int32 nPos,
                                const Locale& /*rLocale*/ )
    throw(RuntimeException)
{
    if ( nPos < 0 || Text.getLength() <= nPos ) return 0;

    return getCharType(Text, &nPos, 0);
}

sal_Int32
cclass_Apple::getStringType( const OUString& Text,
                             sal_Int32 nPos,
                             sal_Int32 nCount,
                             const Locale& /*rLocale*/ )
    throw(RuntimeException)
{
    if ( nPos < 0 || Text.getLength() <= nPos ) return 0;

    sal_Int32 result = 0;

    while (nCount > 0 && nPos < Text.getLength())
    {
        sal_Int32 nOrigPos = nPos;
        result |= getCharType(Text, &nPos, 1);
        sal_Int32 nUtf16Units = nPos - nOrigPos;
        nCount -= nUtf16Units;
    }

    return result;
}

ParseResult
cclass_Apple::parseAnyToken( const OUString& Text,
                             sal_Int32 nPos,
                             const Locale& rLocale,
                             sal_Int32 startCharTokenType,
                             const OUString& userDefinedCharactersStart,
                             sal_Int32 contCharTokenType,
                             const OUString& userDefinedCharactersCont )
    throw(RuntimeException)
{
    (void) Text;
    (void) nPos;
    (void) rLocale;
    (void) startCharTokenType;
    (void) userDefinedCharactersStart;
    (void) contCharTokenType;
    (void) userDefinedCharactersCont;

    ParseResult r;

    return r;
}


ParseResult
cclass_Apple::parsePredefinedToken( sal_Int32 nTokenType,
                                    const OUString& Text,
                                    sal_Int32 nPos,
                                    const Locale& rLocale,
                                    sal_Int32 startCharTokenType,
                                    const OUString& userDefinedCharactersStart,
                                    sal_Int32 contCharTokenType,
                                    const OUString& userDefinedCharactersCont )
    throw(RuntimeException)
{
    (void) nTokenType;
    (void) Text;
    (void) nPos;
    (void) rLocale;
    (void) startCharTokenType;
    (void) userDefinedCharactersStart;
    (void) contCharTokenType;
    (void) userDefinedCharactersCont;

    ParseResult r;
    if ( Text.getLength() <= nPos )
        return r;

    return r;
}

OUString
cclass_Apple::getImplementationName()
    throw( RuntimeException )
{
  return OUString( "com.sun.star.i18n.CharacterClassification_Apple" );
}

sal_Bool
cclass_Apple::supportsService( const OUString& rServiceName )
    throw( RuntimeException )
{
    return cppu::supportsService(this, rServiceName);
}

Sequence< OUString >
cclass_Apple::getSupportedServiceNames()
    throw( RuntimeException )
{
    Sequence< OUString > aRet(1);
    aRet[0] = OUString( "com.sun.star.i18n.CharacterClassification_Apple" );

    return aRet;
}

sal_Int32
cclass_Apple::getCharType( const OUString& Text,
                           sal_Int32* nPos,
                           sal_Int32 increment)
{
    using namespace ::com::sun::star::i18n::KCharacterType;

    sal_uInt32 ch = Text.iterateCodePoints(nPos, increment);
    switch ( u_charType(ch) ) {
    // Upper
    case U_UPPERCASE_LETTER :
        return UPPER|LETTER|PRINTABLE|BASE_FORM;

    // Lower
    case U_LOWERCASE_LETTER :
        return LOWER|LETTER|PRINTABLE|BASE_FORM;

    // Title
    case U_TITLECASE_LETTER :
        return TITLE_CASE|LETTER|PRINTABLE|BASE_FORM;

    // Letter
    case U_MODIFIER_LETTER :
    case U_OTHER_LETTER :
        return LETTER|PRINTABLE|BASE_FORM;

    // Digit
    case U_DECIMAL_DIGIT_NUMBER:
    case U_LETTER_NUMBER:
    case U_OTHER_NUMBER:
        return DIGIT|PRINTABLE|BASE_FORM;

    // Base
    case U_NON_SPACING_MARK:
    case U_ENCLOSING_MARK:
    case U_COMBINING_SPACING_MARK:
        return BASE_FORM|PRINTABLE;

    // Print
    case U_SPACE_SEPARATOR:

    case U_DASH_PUNCTUATION:
    case U_INITIAL_PUNCTUATION:
    case U_FINAL_PUNCTUATION:
    case U_CONNECTOR_PUNCTUATION:
    case U_OTHER_PUNCTUATION:

    case U_MATH_SYMBOL:
    case U_CURRENCY_SYMBOL:
    case U_MODIFIER_SYMBOL:
    case U_OTHER_SYMBOL:
        return PRINTABLE;

    // Control
    case U_CONTROL_CHAR:
    case U_FORMAT_CHAR:
        return CONTROL;

    case U_LINE_SEPARATOR:
    case U_PARAGRAPH_SEPARATOR:
        return CONTROL|PRINTABLE;

    // for all others
    default:
        return U_GENERAL_OTHER_TYPES;
    }
}

} } } }

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
