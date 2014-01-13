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

// Lifted from ICU:

typedef enum UProperty {
    /*
     * Note: UProperty constants are parsed by preparseucd.py.
     * It matches lines like
     *     UCHAR_<Unicode property name>=<integer>,
     */

    /*  Note: Place UCHAR_ALPHABETIC before UCHAR_BINARY_START so that
    debuggers display UCHAR_ALPHABETIC as the symbolic name for 0,
    rather than UCHAR_BINARY_START.  Likewise for other *_START
    identifiers. */

    /** Binary property Alphabetic. Same as u_isUAlphabetic, different from u_isalpha.
        Lu+Ll+Lt+Lm+Lo+Nl+Other_Alphabetic @stable ICU 2.1 */
    UCHAR_ALPHABETIC=0,
    /** First constant for binary Unicode properties. @stable ICU 2.1 */
    UCHAR_BINARY_START=UCHAR_ALPHABETIC,
    /** Binary property ASCII_Hex_Digit. 0-9 A-F a-f @stable ICU 2.1 */
    UCHAR_ASCII_HEX_DIGIT=1,
    /** Binary property Bidi_Control.
        Format controls which have specific functions
        in the Bidi Algorithm. @stable ICU 2.1 */
    UCHAR_BIDI_CONTROL=2,
    /** Binary property Bidi_Mirrored.
        Characters that may change display in RTL text.
        Same as u_isMirrored.
        See Bidi Algorithm, UTR 9. @stable ICU 2.1 */
    UCHAR_BIDI_MIRRORED=3,
    /** Binary property Dash. Variations of dashes. @stable ICU 2.1 */
    UCHAR_DASH=4,
    /** Binary property Default_Ignorable_Code_Point (new in Unicode 3.2).
        Ignorable in most processing.
        <2060..206F, FFF0..FFFB, E0000..E0FFF>+Other_Default_Ignorable_Code_Point+(Cf+Cc+Cs-White_Space) @stable ICU 2.1 */
    UCHAR_DEFAULT_IGNORABLE_CODE_POINT=5,
    /** Binary property Deprecated (new in Unicode 3.2).
        The usage of deprecated characters is strongly discouraged. @stable ICU 2.1 */
    UCHAR_DEPRECATED=6,
    /** Binary property Diacritic. Characters that linguistically modify
        the meaning of another character to which they apply. @stable ICU 2.1 */
    UCHAR_DIACRITIC=7,
    /** Binary property Extender.
        Extend the value or shape of a preceding alphabetic character,
        e.g., length and iteration marks. @stable ICU 2.1 */
    UCHAR_EXTENDER=8,
    /** Binary property Full_Composition_Exclusion.
        CompositionExclusions.txt+Singleton Decompositions+
        Non-Starter Decompositions. @stable ICU 2.1 */
    UCHAR_FULL_COMPOSITION_EXCLUSION=9,
    /** Binary property Grapheme_Base (new in Unicode 3.2).
        For programmatic determination of grapheme cluster boundaries.
        [0..10FFFF]-Cc-Cf-Cs-Co-Cn-Zl-Zp-Grapheme_Link-Grapheme_Extend-CGJ @stable ICU 2.1 */
    UCHAR_GRAPHEME_BASE=10,
    /** Binary property Grapheme_Extend (new in Unicode 3.2).
        For programmatic determination of grapheme cluster boundaries.
        Me+Mn+Mc+Other_Grapheme_Extend-Grapheme_Link-CGJ @stable ICU 2.1 */
    UCHAR_GRAPHEME_EXTEND=11,
    /** Binary property Grapheme_Link (new in Unicode 3.2).
        For programmatic determination of grapheme cluster boundaries. @stable ICU 2.1 */
    UCHAR_GRAPHEME_LINK=12,
    /** Binary property Hex_Digit.
        Characters commonly used for hexadecimal numbers. @stable ICU 2.1 */
    UCHAR_HEX_DIGIT=13,
    /** Binary property Hyphen. Dashes used to mark connections
        between pieces of words, plus the Katakana middle dot. @stable ICU 2.1 */
    UCHAR_HYPHEN=14,
    /** Binary property ID_Continue.
        Characters that can continue an identifier.
        DerivedCoreProperties.txt also says "NOTE: Cf characters should be filtered out."
        ID_Start+Mn+Mc+Nd+Pc @stable ICU 2.1 */
    UCHAR_ID_CONTINUE=15,
    /** Binary property ID_Start.
        Characters that can start an identifier.
        Lu+Ll+Lt+Lm+Lo+Nl @stable ICU 2.1 */
    UCHAR_ID_START=16,
    /** Binary property Ideographic.
        CJKV ideographs. @stable ICU 2.1 */
    UCHAR_IDEOGRAPHIC=17,
    /** Binary property IDS_Binary_Operator (new in Unicode 3.2).
        For programmatic determination of
        Ideographic Description Sequences. @stable ICU 2.1 */
    UCHAR_IDS_BINARY_OPERATOR=18,
    /** Binary property IDS_Trinary_Operator (new in Unicode 3.2).
        For programmatic determination of
        Ideographic Description Sequences. @stable ICU 2.1 */
    UCHAR_IDS_TRINARY_OPERATOR=19,
    /** Binary property Join_Control.
        Format controls for cursive joining and ligation. @stable ICU 2.1 */
    UCHAR_JOIN_CONTROL=20,
    /** Binary property Logical_Order_Exception (new in Unicode 3.2).
        Characters that do not use logical order and
        require special handling in most processing. @stable ICU 2.1 */
    UCHAR_LOGICAL_ORDER_EXCEPTION=21,
    /** Binary property Lowercase. Same as u_isULowercase, different from u_islower.
        Ll+Other_Lowercase @stable ICU 2.1 */
    UCHAR_LOWERCASE=22,
    /** Binary property Math. Sm+Other_Math @stable ICU 2.1 */
    UCHAR_MATH=23,
    /** Binary property Noncharacter_Code_Point.
        Code points that are explicitly defined as illegal
        for the encoding of characters. @stable ICU 2.1 */
    UCHAR_NONCHARACTER_CODE_POINT=24,
    /** Binary property Quotation_Mark. @stable ICU 2.1 */
    UCHAR_QUOTATION_MARK=25,
    /** Binary property Radical (new in Unicode 3.2).
        For programmatic determination of
        Ideographic Description Sequences. @stable ICU 2.1 */
    UCHAR_RADICAL=26,
    /** Binary property Soft_Dotted (new in Unicode 3.2).
        Characters with a "soft dot", like i or j.
        An accent placed on these characters causes
        the dot to disappear. @stable ICU 2.1 */
    UCHAR_SOFT_DOTTED=27,
    /** Binary property Terminal_Punctuation.
        Punctuation characters that generally mark
        the end of textual units. @stable ICU 2.1 */
    UCHAR_TERMINAL_PUNCTUATION=28,
    /** Binary property Unified_Ideograph (new in Unicode 3.2).
        For programmatic determination of
        Ideographic Description Sequences. @stable ICU 2.1 */
    UCHAR_UNIFIED_IDEOGRAPH=29,
    /** Binary property Uppercase. Same as u_isUUppercase, different from u_isupper.
        Lu+Other_Uppercase @stable ICU 2.1 */
    UCHAR_UPPERCASE=30,
    /** Binary property White_Space.
        Same as u_isUWhiteSpace, different from u_isspace and u_isWhitespace.
        Space characters+TAB+CR+LF-ZWSP-ZWNBSP @stable ICU 2.1 */
    UCHAR_WHITE_SPACE=31,
    /** Binary property XID_Continue.
        ID_Continue modified to allow closure under
        normalization forms NFKC and NFKD. @stable ICU 2.1 */
    UCHAR_XID_CONTINUE=32,
    /** Binary property XID_Start. ID_Start modified to allow
        closure under normalization forms NFKC and NFKD. @stable ICU 2.1 */
    UCHAR_XID_START=33,
    /** Binary property Case_Sensitive. Either the source of a case
        mapping or _in_ the target of a case mapping. Not the same as
        the general category Cased_Letter. @stable ICU 2.6 */
   UCHAR_CASE_SENSITIVE=34,
    /** Binary property STerm (new in Unicode 4.0.1).
        Sentence Terminal. Used in UAX #29: Text Boundaries
        (http://www.unicode.org/reports/tr29/)
        @stable ICU 3.0 */
    UCHAR_S_TERM=35,
    /** Binary property Variation_Selector (new in Unicode 4.0.1).
        Indicates all those characters that qualify as Variation Selectors.
        For details on the behavior of these characters,
        see StandardizedVariants.html and 15.6 Variation Selectors.
        @stable ICU 3.0 */
    UCHAR_VARIATION_SELECTOR=36,
    /** Binary property NFD_Inert.
        ICU-specific property for characters that are inert under NFD,
        i.e., they do not interact with adjacent characters.
        See the documentation for the Normalizer2 class and the
        Normalizer2::isInert() method.
        @stable ICU 3.0 */
    UCHAR_NFD_INERT=37,
    /** Binary property NFKD_Inert.
        ICU-specific property for characters that are inert under NFKD,
        i.e., they do not interact with adjacent characters.
        See the documentation for the Normalizer2 class and the
        Normalizer2::isInert() method.
        @stable ICU 3.0 */
    UCHAR_NFKD_INERT=38,
    /** Binary property NFC_Inert.
        ICU-specific property for characters that are inert under NFC,
        i.e., they do not interact with adjacent characters.
        See the documentation for the Normalizer2 class and the
        Normalizer2::isInert() method.
        @stable ICU 3.0 */
    UCHAR_NFC_INERT=39,
    /** Binary property NFKC_Inert.
        ICU-specific property for characters that are inert under NFKC,
        i.e., they do not interact with adjacent characters.
        See the documentation for the Normalizer2 class and the
        Normalizer2::isInert() method.
        @stable ICU 3.0 */
    UCHAR_NFKC_INERT=40,
    /** Binary Property Segment_Starter.
        ICU-specific property for characters that are starters in terms of
        Unicode normalization and combining character sequences.
        They have ccc=0 and do not occur in non-initial position of the
        canonical decomposition of any character
        (like a-umlaut in NFD and a Jamo T in an NFD(Hangul LVT)).
        ICU uses this property for segmenting a string for generating a set of
        canonically equivalent strings, e.g. for canonical closure while
        processing collation tailoring rules.
        @stable ICU 3.0 */
    UCHAR_SEGMENT_STARTER=41,
    /** Binary property Pattern_Syntax (new in Unicode 4.1).
        See UAX #31 Identifier and Pattern Syntax
        (http://www.unicode.org/reports/tr31/)
        @stable ICU 3.4 */
    UCHAR_PATTERN_SYNTAX=42,
    /** Binary property Pattern_White_Space (new in Unicode 4.1).
        See UAX #31 Identifier and Pattern Syntax
        (http://www.unicode.org/reports/tr31/)
        @stable ICU 3.4 */
    UCHAR_PATTERN_WHITE_SPACE=43,
    /** Binary property alnum (a C/POSIX character class).
        Implemented according to the UTS #18 Annex C Standard Recommendation.
        See the uchar.h file documentation.
        @stable ICU 3.4 */
    UCHAR_POSIX_ALNUM=44,
    /** Binary property blank (a C/POSIX character class).
        Implemented according to the UTS #18 Annex C Standard Recommendation.
        See the uchar.h file documentation.
        @stable ICU 3.4 */
    UCHAR_POSIX_BLANK=45,
    /** Binary property graph (a C/POSIX character class).
        Implemented according to the UTS #18 Annex C Standard Recommendation.
        See the uchar.h file documentation.
        @stable ICU 3.4 */
    UCHAR_POSIX_GRAPH=46,
    /** Binary property print (a C/POSIX character class).
        Implemented according to the UTS #18 Annex C Standard Recommendation.
        See the uchar.h file documentation.
        @stable ICU 3.4 */
    UCHAR_POSIX_PRINT=47,
    /** Binary property xdigit (a C/POSIX character class).
        Implemented according to the UTS #18 Annex C Standard Recommendation.
        See the uchar.h file documentation.
        @stable ICU 3.4 */
    UCHAR_POSIX_XDIGIT=48,
    /** Binary property Cased. For Lowercase, Uppercase and Titlecase characters. @stable ICU 4.4 */
    UCHAR_CASED=49,
    /** Binary property Case_Ignorable. Used in context-sensitive case mappings. @stable ICU 4.4 */
    UCHAR_CASE_IGNORABLE=50,
    /** Binary property Changes_When_Lowercased. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_LOWERCASED=51,
    /** Binary property Changes_When_Uppercased. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_UPPERCASED=52,
    /** Binary property Changes_When_Titlecased. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_TITLECASED=53,
    /** Binary property Changes_When_Casefolded. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_CASEFOLDED=54,
    /** Binary property Changes_When_Casemapped. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_CASEMAPPED=55,
    /** Binary property Changes_When_NFKC_Casefolded. @stable ICU 4.4 */
    UCHAR_CHANGES_WHEN_NFKC_CASEFOLDED=56,
    /** One more than the last constant for binary Unicode properties. @stable ICU 2.1 */
    UCHAR_BINARY_LIMIT=57,

    /** Enumerated property Bidi_Class.
        Same as u_charDirection, returns UCharDirection values. @stable ICU 2.2 */
    UCHAR_BIDI_CLASS=0x1000,
    /** First constant for enumerated/integer Unicode properties. @stable ICU 2.2 */
    UCHAR_INT_START=UCHAR_BIDI_CLASS,
    /** Enumerated property Block.
        Same as ublock_getCode, returns UBlockCode values. @stable ICU 2.2 */
    UCHAR_BLOCK=0x1001,
    /** Enumerated property Canonical_Combining_Class.
        Same as u_getCombiningClass, returns 8-bit numeric values. @stable ICU 2.2 */
    UCHAR_CANONICAL_COMBINING_CLASS=0x1002,
    /** Enumerated property Decomposition_Type.
        Returns UDecompositionType values. @stable ICU 2.2 */
    UCHAR_DECOMPOSITION_TYPE=0x1003,
    /** Enumerated property East_Asian_Width.
        See http://www.unicode.org/reports/tr11/
        Returns UEastAsianWidth values. @stable ICU 2.2 */
    UCHAR_EAST_ASIAN_WIDTH=0x1004,
    /** Enumerated property General_Category.
        Same as u_charType, returns UCharCategory values. @stable ICU 2.2 */
    UCHAR_GENERAL_CATEGORY=0x1005,
    /** Enumerated property Joining_Group.
        Returns UJoiningGroup values. @stable ICU 2.2 */
    UCHAR_JOINING_GROUP=0x1006,
    /** Enumerated property Joining_Type.
        Returns UJoiningType values. @stable ICU 2.2 */
    UCHAR_JOINING_TYPE=0x1007,
    /** Enumerated property Line_Break.
        Returns ULineBreak values. @stable ICU 2.2 */
    UCHAR_LINE_BREAK=0x1008,
    /** Enumerated property Numeric_Type.
        Returns UNumericType values. @stable ICU 2.2 */
    UCHAR_NUMERIC_TYPE=0x1009,
    /** Enumerated property Script.
        Same as uscript_getScript, returns UScriptCode values. @stable ICU 2.2 */
    UCHAR_SCRIPT=0x100A,
    /** Enumerated property Hangul_Syllable_Type, new in Unicode 4.
        Returns UHangulSyllableType values. @stable ICU 2.6 */
    UCHAR_HANGUL_SYLLABLE_TYPE=0x100B,
    /** Enumerated property NFD_Quick_Check.
        Returns UNormalizationCheckResult values. @stable ICU 3.0 */
    UCHAR_NFD_QUICK_CHECK=0x100C,
    /** Enumerated property NFKD_Quick_Check.
        Returns UNormalizationCheckResult values. @stable ICU 3.0 */
    UCHAR_NFKD_QUICK_CHECK=0x100D,
    /** Enumerated property NFC_Quick_Check.
        Returns UNormalizationCheckResult values. @stable ICU 3.0 */
    UCHAR_NFC_QUICK_CHECK=0x100E,
    /** Enumerated property NFKC_Quick_Check.
        Returns UNormalizationCheckResult values. @stable ICU 3.0 */
    UCHAR_NFKC_QUICK_CHECK=0x100F,
    /** Enumerated property Lead_Canonical_Combining_Class.
        ICU-specific property for the ccc of the first code point
        of the decomposition, or lccc(c)=ccc(NFD(c)[0]).
        Useful for checking for canonically ordered text;
        see UNORM_FCD and http://www.unicode.org/notes/tn5/#FCD .
        Returns 8-bit numeric values like UCHAR_CANONICAL_COMBINING_CLASS. @stable ICU 3.0 */
    UCHAR_LEAD_CANONICAL_COMBINING_CLASS=0x1010,
    /** Enumerated property Trail_Canonical_Combining_Class.
        ICU-specific property for the ccc of the last code point
        of the decomposition, or tccc(c)=ccc(NFD(c)[last]).
        Useful for checking for canonically ordered text;
        see UNORM_FCD and http://www.unicode.org/notes/tn5/#FCD .
        Returns 8-bit numeric values like UCHAR_CANONICAL_COMBINING_CLASS. @stable ICU 3.0 */
    UCHAR_TRAIL_CANONICAL_COMBINING_CLASS=0x1011,
    /** Enumerated property Grapheme_Cluster_Break (new in Unicode 4.1).
        Used in UAX #29: Text Boundaries
        (http://www.unicode.org/reports/tr29/)
        Returns UGraphemeClusterBreak values. @stable ICU 3.4 */
    UCHAR_GRAPHEME_CLUSTER_BREAK=0x1012,
    /** Enumerated property Sentence_Break (new in Unicode 4.1).
        Used in UAX #29: Text Boundaries
        (http://www.unicode.org/reports/tr29/)
        Returns USentenceBreak values. @stable ICU 3.4 */
    UCHAR_SENTENCE_BREAK=0x1013,
    /** Enumerated property Word_Break (new in Unicode 4.1).
        Used in UAX #29: Text Boundaries
        (http://www.unicode.org/reports/tr29/)
        Returns UWordBreakValues values. @stable ICU 3.4 */
    UCHAR_WORD_BREAK=0x1014,
    /** Enumerated property Bidi_Paired_Bracket_Type (new in Unicode 6.3).
        Used in UAX #9: Unicode Bidirectional Algorithm
        (http://www.unicode.org/reports/tr9/)
        Returns UBidiPairedBracketType values. @stable ICU 52 */
    UCHAR_BIDI_PAIRED_BRACKET_TYPE=0x1015,
    /** One more than the last constant for enumerated/integer Unicode properties. @stable ICU 2.2 */
    UCHAR_INT_LIMIT=0x1016,

    /** Bitmask property General_Category_Mask.
        This is the General_Category property returned as a bit mask.
        When used in u_getIntPropertyValue(c), same as U_MASK(u_charType(c)),
        returns bit masks for UCharCategory values where exactly one bit is set.
        When used with u_getPropertyValueName() and u_getPropertyValueEnum(),
        a multi-bit mask is used for sets of categories like "Letters".
        Mask values should be cast to uint32_t.
        @stable ICU 2.4 */
    UCHAR_GENERAL_CATEGORY_MASK=0x2000,
    /** First constant for bit-mask Unicode properties. @stable ICU 2.4 */
    UCHAR_MASK_START=UCHAR_GENERAL_CATEGORY_MASK,
    /** One more than the last constant for bit-mask Unicode properties. @stable ICU 2.4 */
    UCHAR_MASK_LIMIT=0x2001,

    /** Double property Numeric_Value.
        Corresponds to u_getNumericValue. @stable ICU 2.4 */
    UCHAR_NUMERIC_VALUE=0x3000,
    /** First constant for double Unicode properties. @stable ICU 2.4 */
    UCHAR_DOUBLE_START=UCHAR_NUMERIC_VALUE,
    /** One more than the last constant for double Unicode properties. @stable ICU 2.4 */
    UCHAR_DOUBLE_LIMIT=0x3001,

    /** String property Age.
        Corresponds to u_charAge. @stable ICU 2.4 */
    UCHAR_AGE=0x4000,
    /** First constant for string Unicode properties. @stable ICU 2.4 */
    UCHAR_STRING_START=UCHAR_AGE,
    /** String property Bidi_Mirroring_Glyph.
        Corresponds to u_charMirror. @stable ICU 2.4 */
    UCHAR_BIDI_MIRRORING_GLYPH=0x4001,
    /** String property Case_Folding.
        Corresponds to u_strFoldCase in ustring.h. @stable ICU 2.4 */
    UCHAR_CASE_FOLDING=0x4002,
#ifndef U_HIDE_DEPRECATED_API
    /** Deprecated string property ISO_Comment.
        Corresponds to u_getISOComment. @deprecated ICU 49 */
    UCHAR_ISO_COMMENT=0x4003,
#endif  /* U_HIDE_DEPRECATED_API */
    /** String property Lowercase_Mapping.
        Corresponds to u_strToLower in ustring.h. @stable ICU 2.4 */
    UCHAR_LOWERCASE_MAPPING=0x4004,
    /** String property Name.
        Corresponds to u_charName. @stable ICU 2.4 */
    UCHAR_NAME=0x4005,
    /** String property Simple_Case_Folding.
        Corresponds to u_foldCase. @stable ICU 2.4 */
    UCHAR_SIMPLE_CASE_FOLDING=0x4006,
    /** String property Simple_Lowercase_Mapping.
        Corresponds to u_tolower. @stable ICU 2.4 */
    UCHAR_SIMPLE_LOWERCASE_MAPPING=0x4007,
    /** String property Simple_Titlecase_Mapping.
        Corresponds to u_totitle. @stable ICU 2.4 */
    UCHAR_SIMPLE_TITLECASE_MAPPING=0x4008,
    /** String property Simple_Uppercase_Mapping.
        Corresponds to u_toupper. @stable ICU 2.4 */
    UCHAR_SIMPLE_UPPERCASE_MAPPING=0x4009,
    /** String property Titlecase_Mapping.
        Corresponds to u_strToTitle in ustring.h. @stable ICU 2.4 */
    UCHAR_TITLECASE_MAPPING=0x400A,
#ifndef U_HIDE_DEPRECATED_API
    /** String property Unicode_1_Name.
        This property is of little practical value.
        Beginning with ICU 49, ICU APIs return an empty string for this property.
        Corresponds to u_charName(U_UNICODE_10_CHAR_NAME). @deprecated ICU 49 */
    UCHAR_UNICODE_1_NAME=0x400B,
#endif  /* U_HIDE_DEPRECATED_API */
    /** String property Uppercase_Mapping.
        Corresponds to u_strToUpper in ustring.h. @stable ICU 2.4 */
    UCHAR_UPPERCASE_MAPPING=0x400C,
    /** String property Bidi_Paired_Bracket (new in Unicode 6.3).
        Corresponds to u_getBidiPairedBracket. @stable ICU 52 */
    UCHAR_BIDI_PAIRED_BRACKET=0x400D,
    /** One more than the last constant for string Unicode properties. @stable ICU 2.4 */
    UCHAR_STRING_LIMIT=0x400E,

    /** Miscellaneous property Script_Extensions (new in Unicode 6.0).
        Some characters are commonly used in multiple scripts.
        For more information, see UAX #24: http://www.unicode.org/reports/tr24/.
        Corresponds to uscript_hasScript and uscript_getScriptExtensions in uscript.h.
        @stable ICU 4.6 */
    UCHAR_SCRIPT_EXTENSIONS=0x7000,
    /** First constant for Unicode properties with unusual value types. @stable ICU 4.6 */
    UCHAR_OTHER_PROPERTY_START=UCHAR_SCRIPT_EXTENSIONS,
    /** One more than the last constant for Unicode properties with unusual value types.
     * @stable ICU 4.6 */
    UCHAR_OTHER_PROPERTY_LIMIT=0x7001,
    /** Represents a nonexistent or invalid property or property value. @stable ICU 2.4 */
    UCHAR_INVALID_CODE = -1
} UProperty;

typedef enum UCharCategory
{
    /*
     * Note: UCharCategory constants and their API comments are parsed by preparseucd.py.
     * It matches pairs of lines like
     *     / ** <Unicode 2-letter General_Category value> comment... * /
     *     U_<[A-Z_]+> = <integer>,
     */

    /** Non-category for unassigned and non-character code points. @stable ICU 2.0 */
    U_UNASSIGNED              = 0,
    /** Cn "Other, Not Assigned (no characters in [UnicodeData.txt] have this property)" (same as U_UNASSIGNED!) @stable ICU 2.0 */
    U_GENERAL_OTHER_TYPES     = 0,
    /** Lu @stable ICU 2.0 */
    U_UPPERCASE_LETTER        = 1,
    /** Ll @stable ICU 2.0 */
    U_LOWERCASE_LETTER        = 2,
    /** Lt @stable ICU 2.0 */
    U_TITLECASE_LETTER        = 3,
    /** Lm @stable ICU 2.0 */
    U_MODIFIER_LETTER         = 4,
    /** Lo @stable ICU 2.0 */
    U_OTHER_LETTER            = 5,
    /** Mn @stable ICU 2.0 */
    U_NON_SPACING_MARK        = 6,
    /** Me @stable ICU 2.0 */
    U_ENCLOSING_MARK          = 7,
    /** Mc @stable ICU 2.0 */
    U_COMBINING_SPACING_MARK  = 8,
    /** Nd @stable ICU 2.0 */
    U_DECIMAL_DIGIT_NUMBER    = 9,
    /** Nl @stable ICU 2.0 */
    U_LETTER_NUMBER           = 10,
    /** No @stable ICU 2.0 */
    U_OTHER_NUMBER            = 11,
    /** Zs @stable ICU 2.0 */
    U_SPACE_SEPARATOR         = 12,
    /** Zl @stable ICU 2.0 */
    U_LINE_SEPARATOR          = 13,
    /** Zp @stable ICU 2.0 */
    U_PARAGRAPH_SEPARATOR     = 14,
    /** Cc @stable ICU 2.0 */
    U_CONTROL_CHAR            = 15,
    /** Cf @stable ICU 2.0 */
    U_FORMAT_CHAR             = 16,
    /** Co @stable ICU 2.0 */
    U_PRIVATE_USE_CHAR        = 17,
    /** Cs @stable ICU 2.0 */
    U_SURROGATE               = 18,
    /** Pd @stable ICU 2.0 */
    U_DASH_PUNCTUATION        = 19,
    /** Ps @stable ICU 2.0 */
    U_START_PUNCTUATION       = 20,
    /** Pe @stable ICU 2.0 */
    U_END_PUNCTUATION         = 21,
    /** Pc @stable ICU 2.0 */
    U_CONNECTOR_PUNCTUATION   = 22,
    /** Po @stable ICU 2.0 */
    U_OTHER_PUNCTUATION       = 23,
    /** Sm @stable ICU 2.0 */
    U_MATH_SYMBOL             = 24,
    /** Sc @stable ICU 2.0 */
    U_CURRENCY_SYMBOL         = 25,
    /** Sk @stable ICU 2.0 */
    U_MODIFIER_SYMBOL         = 26,
    /** So @stable ICU 2.0 */
    U_OTHER_SYMBOL            = 27,
    /** Pi @stable ICU 2.0 */
    U_INITIAL_PUNCTUATION     = 28,
    /** Pf @stable ICU 2.0 */
    U_FINAL_PUNCTUATION       = 29,
    /** One higher than the last enum UCharCategory constant. @stable ICU 2.0 */
    U_CHAR_CATEGORY_COUNT
} UCharCategory;

typedef enum UCharDirection {
    /*
     * Note: UCharDirection constants and their API comments are parsed by preparseucd.py.
     * It matches pairs of lines like
     *     / ** <Unicode 1..3-letter Bidi_Class value> comment... * /
     *     U_<[A-Z_]+> = <integer>,
     */

    /** L @stable ICU 2.0 */
    U_LEFT_TO_RIGHT               = 0,
    /** R @stable ICU 2.0 */
    U_RIGHT_TO_LEFT               = 1,
    /** EN @stable ICU 2.0 */
    U_EUROPEAN_NUMBER             = 2,
    /** ES @stable ICU 2.0 */
    U_EUROPEAN_NUMBER_SEPARATOR   = 3,
    /** ET @stable ICU 2.0 */
    U_EUROPEAN_NUMBER_TERMINATOR  = 4,
    /** AN @stable ICU 2.0 */
    U_ARABIC_NUMBER               = 5,
    /** CS @stable ICU 2.0 */
    U_COMMON_NUMBER_SEPARATOR     = 6,
    /** B @stable ICU 2.0 */
    U_BLOCK_SEPARATOR             = 7,
    /** S @stable ICU 2.0 */
    U_SEGMENT_SEPARATOR           = 8,
    /** WS @stable ICU 2.0 */
    U_WHITE_SPACE_NEUTRAL         = 9,
    /** ON @stable ICU 2.0 */
    U_OTHER_NEUTRAL               = 10,
    /** LRE @stable ICU 2.0 */
    U_LEFT_TO_RIGHT_EMBEDDING     = 11,
    /** LRO @stable ICU 2.0 */
    U_LEFT_TO_RIGHT_OVERRIDE      = 12,
    /** AL @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_ARABIC        = 13,
    /** RLE @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_EMBEDDING     = 14,
    /** RLO @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_OVERRIDE      = 15,
    /** PDF @stable ICU 2.0 */
    U_POP_DIRECTIONAL_FORMAT      = 16,
    /** NSM @stable ICU 2.0 */
    U_DIR_NON_SPACING_MARK        = 17,
    /** BN @stable ICU 2.0 */
    U_BOUNDARY_NEUTRAL            = 18,
    /** FSI @stable ICU 52 */
    U_FIRST_STRONG_ISOLATE        = 19,
    /** LRI @stable ICU 52 */
    U_LEFT_TO_RIGHT_ISOLATE       = 20,
    /** RLI @stable ICU 52 */
    U_RIGHT_TO_LEFT_ISOLATE       = 21,
    /** PDI @stable ICU 52 */
    U_POP_DIRECTIONAL_ISOLATE     = 22,
    /** @stable ICU 2.0 */
    U_CHAR_DIRECTION_COUNT
} UCharDirection;

#define u_isalpha U_ICULESS_ENTRY_POINT_RENAME(u_isalpha)
U_STABLE UBool U_EXPORT2
u_isalpha(UChar32 c);

#define u_ispunct U_ICULESS_ENTRY_POINT_RENAME(u_ispunct)
U_STABLE UBool U_EXPORT2
u_ispunct(UChar32 c);

#define u_isWhitespace U_ICULESS_ENTRY_POINT_RENAME(u_isWhitespace)
U_STABLE UBool U_EXPORT2
u_isWhitespace(UChar32 c);

#define u_charType U_ICULESS_ENTRY_POINT_RENAME(u_charType)
U_STABLE int8_t U_EXPORT2
u_charType(UChar32 c);

#define u_charDirection U_ICULESS_ENTRY_POINT_RENAME(u_charDirection)
U_STABLE UCharDirection U_EXPORT2
u_charDirection(UChar32 c);

#define u_charMirror U_ICULESS_ENTRY_POINT_RENAME(u_charMirror)
U_STABLE UChar32 U_EXPORT2
u_charMirror(UChar32 c);

#define u_getIntPropertyValue U_ICULESS_ENTRY_POINT_RENAME(u_getIntPropertyValue)
U_STABLE int32_t U_EXPORT2
u_getIntPropertyValue(UChar32 c, UProperty which);

#endif // INCLUDED_ICULESS_UNICODE_UCHAR_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
