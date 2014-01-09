/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_NORMLZR_H
#define INCLUDED_ICULESS_UNICODE_NORMLZR_H

#include <iculess.h>

typedef enum {
  /** No decomposition/composition. @stable ICU 2.0 */
  UNORM_NONE = 1,
  /** Canonical decomposition. @stable ICU 2.0 */
  UNORM_NFD = 2,
  /** Compatibility decomposition. @stable ICU 2.0 */
  UNORM_NFKD = 3,
  /** Canonical decomposition followed by canonical composition. @stable ICU 2.0 */
  UNORM_NFC = 4,
  /** Default normalization. @stable ICU 2.0 */
  UNORM_DEFAULT = UNORM_NFC,
  /** Compatibility decomposition followed by canonical composition. @stable ICU 2.0 */
  UNORM_NFKC =5,
  /** "Fast C or D" form. @stable ICU 2.0 */
  UNORM_FCD = 6,

  /** One more than the highest normalization mode constant. @stable ICU 2.0 */
  UNORM_MODE_COUNT
} UNormalizationMode;

namespace icu {
#if 0
}
#endif

class Normalizer {
private:
public:
  static void normalize(const UnicodeString& source,
                        UNormalizationMode mode,
                        int32_t options,
                        UnicodeString& result,
                        UErrorCode &status);
};

} // namespace icu

#endif // INCLUDED_ICULESS_UNICODE_NORMLZR_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
