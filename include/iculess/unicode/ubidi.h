/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_UBIDI_H
#define INCLUDED_ICULESS_UNICODE_UBIDI_H

#include <iculess.h>

#define UBIDI_DEFAULT_LTR 0xfe
#define UBIDI_DEFAULT_RTL 0xff

typedef uint8_t UBiDiLevel;

struct UBiDi;

enum UBiDiDirection {
  /** Left-to-right text. This is a 0 value.
   * <ul>
   * <li>As return value for <code>ubidi_getDirection()</code>, it means
   *     that the source string contains no right-to-left characters, or
   *     that the source string is empty and the paragraph level is even.
   * <li> As return value for <code>ubidi_getBaseDirection()</code>, it
   *      means that the first strong character of the source string has
   *      a left-to-right direction.
   * </ul>
   * @stable ICU 2.0
   */
  UBIDI_LTR,
  /** Right-to-left text. This is a 1 value.
   * <ul>
   * <li>As return value for <code>ubidi_getDirection()</code>, it means
   *     that the source string contains no left-to-right characters, or
   *     that the source string is empty and the paragraph level is odd.
   * <li> As return value for <code>ubidi_getBaseDirection()</code>, it
   *      means that the first strong character of the source string has
   *      a right-to-left direction.
   * </ul>
   * @stable ICU 2.0
   */
  UBIDI_RTL,
  /** Mixed-directional text.
   * <p>As return value for <code>ubidi_getDirection()</code>, it means
   *    that the source string contains both left-to-right and
   *    right-to-left characters.
   * @stable ICU 2.0
   */
  UBIDI_MIXED,
  /** No strongly directional text.
   * <p>As return value for <code>ubidi_getBaseDirection()</code>, it means
   *    that the source string is missing or empty, or contains neither left-to-right
   *    nor right-to-left characters.
   * @stable ICU 4.6
   */
  UBIDI_NEUTRAL
};

UBiDi *ubidi_openSized(int32_t maxLength, int32_t maxRunCount, UErrorCode *pErrorCode);

void ubidi_setLine(const UBiDi *pParaBiDi,
                   int32_t start,
                   int32_t limit,
                   UBiDi *pLineBiDi,
                   UErrorCode *pErrorCode);

void ubidi_setPara(UBiDi *pBiDi,
                   const UChar *text,
                   int32_t length,
                   UBiDiLevel paraLevel,
                   UBiDiLevel *embeddingLevels,
                   UErrorCode *pErrorCode);

int32_t ubidi_countRuns(UBiDi *pBiDi,
                        UErrorCode *pErrorCode);

void ubidi_getLogicalRun(const UBiDi *pBiDi,
                         int32_t logicalPosition,
                         int32_t *pLogicalLimit,
                         UBiDiLevel *pLevel);

UBiDiDirection ubidi_getVisualRun(UBiDi *pBiDi,
                                  int32_t runIndex,
                                  int32_t *pLogicalStart,
                                  int32_t *pLength);

void ubidi_close(UBiDi *pBiDi);

#endif // INCLUDED_ICULESS_UNICODE_UBIDI_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
