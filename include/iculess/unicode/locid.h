/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_LOCID_H
#define INCLUDED_ICULESS_UNICODE_LOCID_H

#include <sal/types.h>

#include <iculess.h>
#include <iculess/dllapi.h>

#ifdef __APPLE__

#include <premac.h>
#include <CoreFoundation/CFLocale.h>
#include <postmac.h>

#endif // __APPLE__

namespace icu {
#if 0
}
#endif

class ICULESS_DLLPUBLIC Locale {
private:
#ifdef __APPLE__
    CFLocaleRef m_localeRef;
#endif

public:
    Locale();
    Locale(const char *language,
           const char *country = 0,
           const char *variant = 0,
           const char *keywordsAndValues = 0);
    virtual ~Locale();

    static Locale createFromName(const char *name);
};

} // namespace icu

#endif // INCLUDED_ICULESS_UNICODE_LOCID_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
