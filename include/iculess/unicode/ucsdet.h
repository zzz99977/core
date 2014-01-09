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

UCharsetDetector *ucsdet_open(UErrorCode *status);

UBool ucsdet_enableInputFilter(UCharsetDetector *ucsd,
                               UBool filter);

void ucsdet_setText(UCharsetDetector *ucsd,
                    const char *textIn,
                    int32_t len,
                    UErrorCode *status);

const UCharsetMatch *ucsdet_detect(UCharsetDetector *ucsd,
                                   UErrorCode *status);

const UCharsetMatch **ucsdet_detectAll(UCharsetDetector *ucsd,
                                       int32_t *matchesFound,
                                       UErrorCode *status);

int32_t ucsdet_getConfidence(const UCharsetMatch *ucsm,
                             UErrorCode *status);

const char *ucsdet_getName(const UCharsetMatch *ucsm,
                           UErrorCode *status);

void ucsdet_close(UCharsetDetector *ucsd);

#endif // INCLUDED_ICULESS_UNICODE_UCSDET_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
