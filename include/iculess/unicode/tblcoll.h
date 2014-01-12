/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_TBLCOLL_H
#define INCLUDED_ICULESS_UNICODE_TBLCOLL_H

#include <sal/types.h>

#include <iculess.h>

#include <unicode/locid.h>

typedef enum {
  /** string a == string b */
  UCOL_EQUAL    = 0,
  /** string a > string b */
  UCOL_GREATER    = 1,
  /** string a < string b */
  UCOL_LESS    = -1
} UCollationResult;

typedef enum {
  /** accepted by most attributes */
  UCOL_DEFAULT = -1,

  /** Primary collation strength */
  UCOL_PRIMARY = 0,
  /** Secondary collation strength */
  UCOL_SECONDARY = 1,
  /** Tertiary collation strength */
  UCOL_TERTIARY = 2,
  /** Default collation strength */
  UCOL_DEFAULT_STRENGTH = UCOL_TERTIARY,
  UCOL_CE_STRENGTH_LIMIT,
  /** Quaternary collation strength */
  UCOL_QUATERNARY=3,
  /** Identical collation strength */
  UCOL_IDENTICAL=15,
  UCOL_STRENGTH_LIMIT,

  /** Turn the feature off - works for UCOL_FRENCH_COLLATION,
      UCOL_CASE_LEVEL, UCOL_HIRAGANA_QUATERNARY_MODE
      & UCOL_DECOMPOSITION_MODE*/
  UCOL_OFF = 16,
  /** Turn the feature on - works for UCOL_FRENCH_COLLATION,
      UCOL_CASE_LEVEL, UCOL_HIRAGANA_QUATERNARY_MODE
      & UCOL_DECOMPOSITION_MODE*/
  UCOL_ON = 17,

  /** Valid for UCOL_ALTERNATE_HANDLING. Alternate handling will be shifted */
  UCOL_SHIFTED = 20,
  /** Valid for UCOL_ALTERNATE_HANDLING. Alternate handling will be non ignorable */
  UCOL_NON_IGNORABLE = 21,

  /** Valid for UCOL_CASE_FIRST -
      lower case sorts before upper case */
  UCOL_LOWER_FIRST = 24,
  /** upper case sorts before lower case */
  UCOL_UPPER_FIRST = 25,

  UCOL_ATTRIBUTE_VALUE_COUNT

} UColAttributeValue;

namespace icu {
#if 0
}
#endif

class Collator {
private:

public:
    enum ECollationStrength
    {
        PRIMARY    = UCOL_PRIMARY,  // 0
        SECONDARY  = UCOL_SECONDARY,  // 1
        TERTIARY   = UCOL_TERTIARY,  // 2
        QUATERNARY = UCOL_QUATERNARY,  // 3
        IDENTICAL  = UCOL_IDENTICAL  // 15
    };

    enum EComparisonResult
    {
        LESS = UCOL_LESS,  // -1
        EQUAL = UCOL_EQUAL,  // 0
        GREATER = UCOL_GREATER  // 1
    };

    virtual ~Collator();

    virtual void setStrength(ECollationStrength newStrength);

    virtual EComparisonResult compare(const UnicodeString& source,
                                      const UnicodeString& target) const;

    virtual EComparisonResult compare(const UChar* source,
                                      int32_t sourceLength,
                                      const UChar* target,
                                      int32_t targetLength) const;

    static Collator* createInstance(const Locale& loc,
                                    UErrorCode& err);
};

class RuleBasedCollator : public Collator {
private:

public:
    RuleBasedCollator(const UnicodeString& rules, UErrorCode& status);

    RuleBasedCollator(const uint8_t *bin,
                      int32_t length,
                      const RuleBasedCollator *base,
                      UErrorCode &status);

    virtual ~RuleBasedCollator() SAL_OVERRIDE;

    virtual EComparisonResult compare(const UnicodeString& source,
                                      const UnicodeString& target) const SAL_OVERRIDE;

    virtual EComparisonResult compare(const UChar* source,
                                      int32_t sourceLength,
                                      const UChar* target,
                                      int32_t targetLength) const SAL_OVERRIDE;
};

} // namespace icu

#endif // INCLUDED_ICULESS_UNICODE_TBLCOLL_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
