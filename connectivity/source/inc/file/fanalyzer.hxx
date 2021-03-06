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

#ifndef INCLUDED_CONNECTIVITY_SOURCE_INC_FILE_FANALYZER_HXX
#define INCLUDED_CONNECTIVITY_SOURCE_INC_FILE_FANALYZER_HXX

#include "file/fcomp.hxx"
#include "file/filedllapi.hxx"

namespace connectivity
{
    namespace file
    {
        class OConnection;
        class OOO_DLLPUBLIC_FILE OSQLAnalyzer
        {
            typedef ::std::list<OEvaluateSet*>      OEvaluateSetList;
            typedef ::std::pair< ::rtl::Reference<OPredicateCompiler>,::rtl::Reference<OPredicateInterpreter> > TPredicates;

            ::std::vector< TPredicates >        m_aSelectionEvaluations;
            ::rtl::Reference<OPredicateCompiler>        m_aCompiler;
            ::rtl::Reference<OPredicateInterpreter> m_aInterpreter;
            OConnection*                        m_pConnection;

            mutable bool                    m_bHasSelectionCode;
            mutable bool                    m_bSelectionFirstTime;

            static void bindRow(OCodeList& rCodeList,const OValueRefRow& _pRow);

        public:
            OSQLAnalyzer(OConnection* _pConnection);
            virtual ~OSQLAnalyzer();
            inline static void * SAL_CALL operator new( size_t nSize )
                { return ::rtl_allocateMemory( nSize ); }
            inline static void * SAL_CALL operator new( size_t /*nSize*/,void* _pHint )
                { return _pHint; }
            inline static void SAL_CALL operator delete( void * pMem )
                { ::rtl_freeMemory( pMem ); }
            inline static void SAL_CALL operator delete( void * /*pMem*/,void* /*_pHint*/ )
                {  }

            OConnection* getConnection() const { return m_pConnection; }
            void bindEvaluationRow(OValueRefRow& _pRow); // Bind an evaluation row to the restriction
            /** bind the select columns if they contain a function which needs a row value
                @param  _pRow   the result row
            */
            void bindSelectRow(const OValueRefRow& _pRow);

            /** binds the row to parameter for the restrictions
                @param  _pRow   the parameter row
            */
            void bindParameterRow(OValueRefRow& _pRow);

            void setIndexes(const ::com::sun::star::uno::Reference< ::com::sun::star::container::XNameAccess>& _xIndexes);

            void dispose();
            void start(OSQLParseNode* pSQLParseNode);
            bool hasRestriction() const;
            bool hasFunctions() const;
            inline bool evaluateRestriction()   { return m_aInterpreter->start(); }
            void setSelectionEvaluationResult(OValueRefRow& _pRow,const ::std::vector<sal_Int32>& _rColumnMapping);
            void setOrigColumns(const OFileColumns& rCols);
            static OOperandAttr* createOperandAttr(sal_Int32 _nPos,
                                                    const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySet>& _xCol,
                                                    const ::com::sun::star::uno::Reference< ::com::sun::star::container::XNameAccess>& _xIndexes=NULL);
        };
    }
}
#endif // INCLUDED_CONNECTIVITY_SOURCE_INC_FILE_FANALYZER_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
