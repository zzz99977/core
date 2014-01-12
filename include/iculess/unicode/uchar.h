/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_UCHAR_H
#define INCLUDED_ICULESS_UNICODE_UCHAR_H

#include <iculess.h>

#define u_isalpha U_ICU_ENTRY_POINT_RENAME(u_isalpha)
UBool u_isalpha(UChar32 c);

#define u_ispunct U_ICU_ENTRY_POINT_RENAME(u_ispunct)
UBool u_ispunct(UChar32 c);

#define u_isWhitespace U_ICU_ENTRY_POINT_RENAME(u_isWhitespace)
UBool u_isWhitespace(UChar32 c);

#endif // INCLUDED_ICULESS_UNICODE_UCHAR_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
