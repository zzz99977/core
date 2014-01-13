/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_UCNV_H
#define INCLUDED_ICULESS_UNICODE_UCNV_H

#include <iculess.h>

struct UConverter;

U_STABLE UConverter* U_EXPORT2
ucnv_open(const char *converterName,
          UErrorCode *err);

U_STABLE UChar32 U_EXPORT2
ucnv_getNextUChar(UConverter *converter,
                  const char **source,
                  const char *sourceLimit,
                  UErrorCode *err);

U_STABLE void U_EXPORT2
ucnv_convertEx(UConverter *targetCnv,
               UConverter *sourceCnv,
               char **target,
               const char *targetLimit,
               const char **source,
               const char *sourceLimit,
               UChar *pivotStart,
               UChar **pivotSource,
               UChar **pivotTarget,
               const UChar *pivotLimit,
               UBool reset,
               UBool flush,
               UErrorCode *pErrorCode);

U_STABLE void U_EXPORT2
ucnv_close(UConverter *converter);

#endif // INCLUDED_ICULESS_UNICODE_UCNV_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
