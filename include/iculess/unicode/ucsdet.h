/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_UCSDET_H
#define INCLUDED_ICULESS_UNICODE_UCSDET_H

#include <iculess.h>

struct UCharsetDetector;
struct UCharsetMatch;

U_STABLE UCharsetDetector* U_EXPORT2
ucsdet_open(UErrorCode *status);

U_STABLE UBool U_EXPORT2
ucsdet_enableInputFilter(UCharsetDetector *ucsd,
                         UBool filter);

U_STABLE void U_EXPORT2
ucsdet_setText(UCharsetDetector *ucsd,
               const char *textIn,
               int32_t len,
               UErrorCode *status);

U_STABLE const UCharsetMatch * U_EXPORT2
ucsdet_detect(UCharsetDetector *ucsd,
              UErrorCode *status);

U_STABLE const UCharsetMatch ** U_EXPORT2
ucsdet_detectAll(UCharsetDetector *ucsd,
                 int32_t *matchesFound,
                 UErrorCode *status);

U_STABLE int32_t U_EXPORT2
ucsdet_getConfidence(const UCharsetMatch *ucsm,
                     UErrorCode *status);

U_STABLE const char * U_EXPORT2
ucsdet_getName(const UCharsetMatch *ucsm,
               UErrorCode *status);

U_STABLE void U_EXPORT2
ucsdet_close(UCharsetDetector *ucsd);

#endif // INCLUDED_ICULESS_UNICODE_UCSDET_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
