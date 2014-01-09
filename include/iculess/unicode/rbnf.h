/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_RBNF_H
#define INCLUDED_ICULESS_UNICODE_RBNF_H

#include <iculess.h>

namespace icu {
#if 0
}
#endif

enum URBNFRuleSetTag {
    URBNF_SPELLOUT,
    URBNF_ORDINAL,
    URBNF_DURATION,
    URBNF_NUMBERING_SYSTEM,
    URBNF_COUNT
};

class RuleBasedNumberFormat {
private:

public:
    RuleBasedNumberFormat(URBNFRuleSetTag tag, const Locale& locale, UErrorCode& status);

    virtual ~RuleBasedNumberFormat();
};


} // namespace icu

#endif // INCLUDED_ICULESS_UNICODE_RBNF_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
