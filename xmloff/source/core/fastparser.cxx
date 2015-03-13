/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <xmloff/fastparser.hxx>
#include <xmloff/fasttokenhandler.hxx>
#include <xmloff/xmlnmspe.hxx>
#include <com/sun/star/xml/sax/FastParser.hpp>
#include <com/sun/star/xml/sax/FastToken.hpp>

using namespace css;
using namespace css::uno;
using css::xml::sax::FastToken::NAMESPACE;

namespace xmloff {
namespace core {

FastParser::FastParser(
    const Reference< XComponentContext >& rxContext,
    const Reference< xml::sax::XFastDocumentHandler >& rxDocHandler )
    throw( lang::IllegalArgumentException, RuntimeException )
{
    mxParser = xml::sax::FastParser::create(rxContext);
    mxParser->setTokenHandler( new xmloff::token::FastTokenHandler() );
    mxParser->setFastDocumentHandler( rxDocHandler );
    // register namespaces
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:office:1.0", NAMESPACE | XML_NAMESPACE_OFFICE );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:style:1.0", NAMESPACE | XML_NAMESPACE_STYLE );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:text:1.0", NAMESPACE | XML_NAMESPACE_TEXT );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:table:1.0", NAMESPACE | XML_NAMESPACE_TABLE );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:drawing:1.0", NAMESPACE | XML_NAMESPACE_DRAW );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0", NAMESPACE | XML_NAMESPACE_FO );
    mxParser->registerNamespace( "http://www.w3.org/1999/xlink", NAMESPACE | XML_NAMESPACE_XLINK );
    mxParser->registerNamespace( "http://purl.org/dc/elements/1.1/", NAMESPACE | XML_NAMESPACE_DC );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:meta:1.0", NAMESPACE | XML_NAMESPACE_META );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0", NAMESPACE | XML_NAMESPACE_NUMBER );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:presentation:1.0", NAMESPACE | XML_NAMESPACE_PRESENTATION );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0", NAMESPACE | XML_NAMESPACE_SVG );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:chart:1.0", NAMESPACE | XML_NAMESPACE_CHART );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0", NAMESPACE | XML_NAMESPACE_DR3D );
    mxParser->registerNamespace( "http://www.w3.org/1998/Math/MathML", NAMESPACE | XML_NAMESPACE_MATH );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:form:1.0", NAMESPACE | XML_NAMESPACE_FORM );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:script:1.0", NAMESPACE | XML_NAMESPACE_SCRIPT );
    mxParser->registerNamespace( "http://openoffice.org/2001/block-list", NAMESPACE | XML_NAMESPACE_BLOCKLIST );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:config:1.0", NAMESPACE | XML_NAMESPACE_CONFIG );
    mxParser->registerNamespace( "http://openoffice.org/2004/office", NAMESPACE | XML_NAMESPACE_OOO );
    mxParser->registerNamespace( "http://openoffice.org/2004/writer", NAMESPACE | XML_NAMESPACE_OOOW );
    mxParser->registerNamespace( "http://openoffice.org/2004/calc", NAMESPACE | XML_NAMESPACE_OOOC );
    mxParser->registerNamespace( "http://www.w3.org/2001/xml-events", NAMESPACE | XML_NAMESPACE_DOM );
    mxParser->registerNamespace( "http://openoffice.org/2004/database", NAMESPACE | XML_NAMESPACE_DB );
    mxParser->registerNamespace( "http://openoffice.org/2000/dialog", NAMESPACE | XML_NAMESPACE_DLG );
    mxParser->registerNamespace( "http://www.w3.org/2002/xforms", NAMESPACE | XML_NAMESPACE_XFORMS );
    mxParser->registerNamespace( "http://www.w3.org/2001/XMLSchema", NAMESPACE | XML_NAMESPACE_XSD );
    mxParser->registerNamespace( "http://www.w3.org/2001/XMLSchema-instance", NAMESPACE | XML_NAMESPACE_XSI );
    mxParser->registerNamespace( "http://www.w3.org/2001/SMIL20/", NAMESPACE | XML_NAMESPACE_SMIL );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:animation:1.0", NAMESPACE | XML_NAMESPACE_ANIMATION );
    mxParser->registerNamespace( "http://www.w3.org/XML/1998/namespace", NAMESPACE | XML_NAMESPACE_XML );
    mxParser->registerNamespace( "http://openoffice.org/2005/report", NAMESPACE | XML_NAMESPACE_REPORT );
    mxParser->registerNamespace( "urn:oasis:names:tc:opendocument:xmlns:of:1.2", NAMESPACE | XML_NAMESPACE_OF );
    mxParser->registerNamespace( "http://www.w3.org/1999/xhtml", NAMESPACE | XML_NAMESPACE_XHTML );
    mxParser->registerNamespace( "http://www.w3.org/2003/g/data-view#", NAMESPACE | XML_NAMESPACE_GRDDL );
    mxParser->registerNamespace( "http://openoffice.org/2009/office", NAMESPACE | XML_NAMESPACE_OFFICE_EXT );
    mxParser->registerNamespace( "http://openoffice.org/2009/table", NAMESPACE | XML_NAMESPACE_TABLE_EXT );
    mxParser->registerNamespace( "http://openoffice.org/2009/draw", NAMESPACE | XML_NAMESPACE_DRAW_EXT );
    mxParser->registerNamespace( "urn:org:documentfoundation:names:experimental:calc:xmlns:calcext:1.0", NAMESPACE | XML_NAMESPACE_CALC_EXT );
    mxParser->registerNamespace( "urn:org:documentfoundation:names:experimental:office:xmlns:loext:1.0", NAMESPACE | XML_NAMESPACE_LO_EXT );
    mxParser->registerNamespace( "urn:openoffice:names:experimental:ooo-ms-interop:xmlns:field:1.0", NAMESPACE | XML_NAMESPACE_FIELD );
    mxParser->registerNamespace( "http://www.w3.org/TR/css3-text/", NAMESPACE | XML_NAMESPACE_CSS3TEXT );
    mxParser->registerNamespace( "urn:openoffice:names:experimental:ooxml-odf-interop:xmlns:form:1.0", NAMESPACE | XML_NAMESPACE_FORMX );
}

void FastParser::parseStream( const xml::sax::InputSource& rInputSource )
    throw( xml::sax::SAXException, io::IOException, RuntimeException )
{
    mxParser->parseStream( rInputSource );
}

void FastParser::parseStream( const Reference< io::XInputStream >& rxInStream,
    const OUString& rStreamName )
    throw( xml::sax::SAXException, io::IOException, RuntimeException )
{
    xml::sax::InputSource aInputSource;
    aInputSource.sSystemId = rStreamName;
    aInputSource.aInputStream = rxInStream;
    parseStream( aInputSource );
}

} // namespace core
} // namespace xmloff

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
