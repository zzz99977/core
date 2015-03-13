/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_XMLOFF_FASTPARSER_HXX
#define INCLUDED_XMLOFF_FASTPARSER_HXX

#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/xml/sax/XFastParser.hpp>
#include <xmloff/dllapi.h>

namespace xmloff {
namespace core {

class XMLOFF_DLLPUBLIC FastParser
{
private:
    css::uno::Reference< css::xml::sax::XFastParser > mxParser;

public:
    FastParser(
        const css::uno::Reference< css::uno::XComponentContext >& rxContext,
        const css::uno::Reference< css::xml::sax::XFastDocumentHandler >& rxDocHandler )
        throw( css::lang::IllegalArgumentException, css::uno::RuntimeException );

    void parseStream( const css::xml::sax::InputSource& rInputSoure )
        throw( css::xml::sax::SAXException, css::io::IOException, css::uno::RuntimeException );

    void parseStream( const css::uno::Reference< css::io::XInputStream >& rxInStream,
            const OUString& rStreamName )
        throw( css::xml::sax::SAXException, css::io::IOException, css::uno::RuntimeException );
};

} // namespace core
} // namespace xmloff

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
