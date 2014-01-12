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

#include <breakiterator_apple.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <localedata.hxx>
#include <i18nlangtag/languagetag.hxx>
#include <i18nlangtag/languagetagicu.hxx>
#include <unicode/uchar.h>
#include <unicode/locid.h>
#include <rtl/strbuf.hxx>
#include <rtl/ustring.hxx>
#include <string.h>

using namespace ::com::sun::star;
using namespace ::com::sun::star::lang;

namespace com { namespace sun { namespace star { namespace i18n {

BreakIterator_Apple::BreakIterator_Apple() :
    cBreakIterator( "com.sun.star.i18n.BreakIterator_Apple" ),    // implementation name
    wordRule( "word" ),
    lineRule( "line" )
{
}

BreakIterator_Apple::~BreakIterator_Apple()
{
}

/*
    Wrapper class to provide public access to the RuleBasedBreakIterator's
    setbreakType method.
*/
class OOoRuleBasedBreakIterator : public RuleBasedBreakIterator {
    public:
        inline void publicSetBreakType(int32_t type) {
            setBreakType(type);
        };
        OOoRuleBasedBreakIterator(UDataMemory* image,
                UErrorCode &status) :
            RuleBasedBreakIterator(image, status) { };

};

void SAL_CALL BreakIterator_Apple::loadBreakIterator(const com::sun::star::lang::Locale& rLocale,
                                                     sal_Int16 rBreakType,
                                                     sal_Int16 nWordType,
                                                     const sal_Char *rule,
                                                     const OUString& rText)
    throw(uno::RuntimeException)
{
    (void) rBreakType;
    (void) nWordType;
    (void) rule;

    if (rLocale.Language != BI->maLocale.Language ||
        rLocale.Country  != BI->maLocale.Country  ||
        rLocale.Variant  != BI->maLocale.Variant) {
        BI->aText = rText;
    }
}

sal_Int32 SAL_CALL BreakIterator_Apple::nextCharacters( const OUString& Text,
                                                        sal_Int32 nStartPos,
                                                        const lang::Locale &rLocale,
                                                        sal_Int16 nCharacterIteratorMode,
                                                        sal_Int32 nCount,
                                                        sal_Int32& nDone )
        throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;
    (void) nCharacterIteratorMode;
    (void) nCount;
    (void) nDone;

    return 0;
}

sal_Int32 SAL_CALL BreakIterator_Apple::previousCharacters( const OUString& Text,
                                                            sal_Int32 nStartPos,
                                                            const lang::Locale& rLocale,
                                                            sal_Int16 nCharacterIteratorMode,
                                                            sal_Int32 nCount,
                                                            sal_Int32& nDone )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;
    (void) nCharacterIteratorMode;
    (void) nCount;
    (void) nDone;

    return 0;
}

Boundary SAL_CALL BreakIterator_Apple::nextWord( const OUString& Text,
                                                 sal_Int32 nStartPos,
                                                 const lang::Locale& rLocale,
                                                 sal_Int16 rWordType )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;
    (void) rWordType;

    return 0;
}


Boundary SAL_CALL BreakIterator_Apple::previousWord(const OUString& Text,
                                                    sal_Int32 nStartPos,
                                                    const lang::Locale& rLocale,
                                                    sal_Int16 rWordType)
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;
    (void) nCharacterIteratorMode;
    (void) rWordType;

    return 0;
}


Boundary SAL_CALL BreakIterator_Apple::getWordBoundary( const OUString& Text,
                                                        sal_Int32 nPos,
                                                        const lang::Locale& rLocale,
                                                        sal_Int16 rWordType,
                                                        sal_Bool bDirection )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nPos;
    (void) rLocale;
    (void) nCharacterIteratorMode;
    (void) rWordType;
    (void) bDirection;

    return 0;
}


sal_Int32 SAL_CALL BreakIterator_Apple::beginOfSentence( const OUString& Text,
                                                         sal_Int32 nStartPos,
                                                         const lang::Locale &rLocale )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;

    return 0;
}

sal_Int32 SAL_CALL BreakIterator_Apple::endOfSentence( const OUString& Text,
                                                       sal_Int32 nStartPos,
                                                       const lang::Locale &rLocale )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;

    return 0;
}

LineBreakResults SAL_CALL BreakIterator_Apple::getLineBreak( const OUString& Text,
                                                             sal_Int32 nStartPos,
                                                             const lang::Locale& rLocale,
                                                             sal_Int32 nMinBreakPos,
                                                             const LineBreakHyphenationOptions& hOptions,
                                                             const LineBreakUserOptions& /*rOptions*/ )
    throw(uno::RuntimeException)
{
    (void) Text;
    (void) nStartPos;
    (void) rLocale;
    (void) nMinBreakPos;
    (void) hOptions;

    return 0;
}

OUString SAL_CALL
BreakIterator_Apple::getImplementationName(void)
    throw( uno::RuntimeException )
{
    return OUString::createFromAscii(cBreakIterator);
}

sal_Bool SAL_CALL
BreakIterator_Apple::supportsService(const OUString& rServiceName)
    throw( uno::RuntimeException )
{
    return cppu::supportsService(this, rServiceName);
}

uno::Sequence< OUString > SAL_CALL
BreakIterator_Apple::getSupportedServiceNames(void)
    throw( uno::RuntimeException )
{
    uno::Sequence< OUString > aRet(1);
    aRet[0] = OUString::createFromAscii(cBreakIterator);
    return aRet;
}

} } } }

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
