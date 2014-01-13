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

#ifndef INCLUDED_I18N_INC_CCLASS_APPLE_HXX
#define INCLUDED_I18N_INC_CCLASS_APPLE_HXX

#include <com/sun/star/i18n/XNativeNumberSupplier.hpp>
#include <com/sun/star/i18n/XCharacterClassification.hpp>
#include <com/sun/star/i18n/XLocaleData4.hpp>
#include <cppuhelper/implbase2.hxx>
#include <com/sun/star/lang/XServiceInfo.hpp>

namespace com { namespace sun { namespace star { namespace uno {
    class XComponentContext;
} } } }

namespace com { namespace sun { namespace star { namespace i18n {

class cclass_Apple : public cppu::WeakImplHelper2 < XCharacterClassification, css::lang::XServiceInfo >
{
public:
    cclass_Apple(const com::sun::star::uno::Reference < com::sun::star::uno::XComponentContext >& rxContext );
    ~cclass_Apple();

    virtual OUString SAL_CALL toUpper( const OUString& Text, sal_Int32 nPos, sal_Int32 nCount,
        const com::sun::star::lang::Locale& rLocale ) throw(com::sun::star::uno::RuntimeException);
    virtual OUString SAL_CALL toLower( const OUString& Text, sal_Int32 nPos, sal_Int32 nCount,
        const com::sun::star::lang::Locale& rLocale ) throw(com::sun::star::uno::RuntimeException);
    virtual OUString SAL_CALL toTitle( const OUString& Text, sal_Int32 nPos, sal_Int32 nCount,
        const com::sun::star::lang::Locale& rLocale ) throw(com::sun::star::uno::RuntimeException);
    virtual sal_Int16 SAL_CALL getType( const OUString& Text, sal_Int32 nPos )  throw(com::sun::star::uno::RuntimeException);
    virtual sal_Int16 SAL_CALL getCharacterDirection( const OUString& Text, sal_Int32 nPos )
        throw(com::sun::star::uno::RuntimeException);
    virtual sal_Int16 SAL_CALL getScript( const OUString& Text, sal_Int32 nPos ) throw(com::sun::star::uno::RuntimeException);
    virtual sal_Int32 SAL_CALL getCharacterType( const OUString& text, sal_Int32 nPos,
        const com::sun::star::lang::Locale& rLocale ) throw(com::sun::star::uno::RuntimeException);
    virtual sal_Int32 SAL_CALL getStringType( const OUString& text, sal_Int32 nPos, sal_Int32 nCount,
        const com::sun::star::lang::Locale& rLocale ) throw(com::sun::star::uno::RuntimeException);
    virtual ParseResult SAL_CALL parseAnyToken( const OUString& Text, sal_Int32 nPos,
        const com::sun::star::lang::Locale& rLocale, sal_Int32 nStartCharFlags, const OUString& userDefinedCharactersStart,
        sal_Int32 nContCharFlags, const OUString& userDefinedCharactersCont ) throw(com::sun::star::uno::RuntimeException);
    virtual ParseResult SAL_CALL parsePredefinedToken( sal_Int32 nTokenType, const OUString& Text,
        sal_Int32 nPos, const com::sun::star::lang::Locale& rLocale, sal_Int32 nStartCharFlags,
        const OUString& userDefinedCharactersStart, sal_Int32 nContCharFlags,
        const OUString& userDefinedCharactersCont ) throw(com::sun::star::uno::RuntimeException);

    //XServiceInfo
    virtual OUString SAL_CALL getImplementationName() throw( com::sun::star::uno::RuntimeException );
    virtual sal_Bool SAL_CALL supportsService(const OUString& ServiceName) throw( com::sun::star::uno::RuntimeException );
    virtual com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() throw( com::sun::star::uno::RuntimeException );

private:
    /// Implementation of getCharacterType() for one single character
    sal_Int32 getCharType( const OUString& Text, sal_Int32 *nPos, sal_Int32 increment);
};

} } } }

#endif // INCLUDED_I18N_INC_CCLASS_APPLE_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
