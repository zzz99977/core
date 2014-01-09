/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_ICULESS_UNICODE_CALENDAR_H
#define INCLUDED_ICULESS_UNICODE_CALENDAR_H

#include <iculess.h>

#include <unicode/locid.h>

enum UCalendarDaysOfWeek {
  /** Sunday */
  UCAL_SUNDAY = 1,
  /** Monday */
  UCAL_MONDAY,
  /** Tuesday */
  UCAL_TUESDAY,
  /** Wednesday */
  UCAL_WEDNESDAY,
  /** Thursday */
  UCAL_THURSDAY,
  /** Friday */
  UCAL_FRIDAY,
  /** Saturday */
  UCAL_SATURDAY
};

enum UCalendarDateFields {
  /**
   * Field number indicating the era, e.g., AD or BC in the Gregorian (Julian) calendar.
   * This is a calendar-specific value.
   * @stable ICU 2.6
   */
  UCAL_ERA,

  /**
   * Field number indicating the year. This is a calendar-specific value.
   * @stable ICU 2.6
   */
  UCAL_YEAR,

  /**
   * Field number indicating the month. This is a calendar-specific value.
   * The first month of the year is
   * <code>JANUARY</code>; the last depends on the number of months in a year.
   * @see #UCAL_JANUARY
   * @see #UCAL_FEBRUARY
   * @see #UCAL_MARCH
   * @see #UCAL_APRIL
   * @see #UCAL_MAY
   * @see #UCAL_JUNE
   * @see #UCAL_JULY
   * @see #UCAL_AUGUST
   * @see #UCAL_SEPTEMBER
   * @see #UCAL_OCTOBER
   * @see #UCAL_NOVEMBER
   * @see #UCAL_DECEMBER
   * @see #UCAL_UNDECIMBER
   * @stable ICU 2.6
   */
  UCAL_MONTH,

  /**
   * Field number indicating the
   * week number within the current year.  The first week of the year, as
   * defined by <code>UCAL_FIRST_DAY_OF_WEEK</code> and <code>UCAL_MINIMAL_DAYS_IN_FIRST_WEEK</code>
   * attributes, has value 1.  Subclasses define
   * the value of <code>UCAL_WEEK_OF_YEAR</code> for days before the first week of
   * the year.
   * @see ucal_getAttribute
   * @see ucal_setAttribute
   * @stable ICU 2.6
   */
  UCAL_WEEK_OF_YEAR,

 /**
   * Field number indicating the
   * week number within the current month.  The first week of the month, as
   * defined by <code>UCAL_FIRST_DAY_OF_WEEK</code> and <code>UCAL_MINIMAL_DAYS_IN_FIRST_WEEK</code>
   * attributes, has value 1.  Subclasses define
   * the value of <code>WEEK_OF_MONTH</code> for days before the first week of
   * the month.
   * @see ucal_getAttribute
   * @see ucal_setAttribute
   * @see #UCAL_FIRST_DAY_OF_WEEK
   * @see #UCAL_MINIMAL_DAYS_IN_FIRST_WEEK
   * @stable ICU 2.6
   */
  UCAL_WEEK_OF_MONTH,

 /**
   * Field number indicating the
   * day of the month. This is a synonym for <code>DAY_OF_MONTH</code>.
   * The first day of the month has value 1.
   * @see #UCAL_DAY_OF_MONTH
   * @stable ICU 2.6
   */
  UCAL_DATE,

 /**
   * Field number indicating the day
   * number within the current year.  The first day of the year has value 1.
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_YEAR,

 /**
   * Field number indicating the day
   * of the week.  This field takes values <code>SUNDAY</code>,
   * <code>MONDAY</code>, <code>TUESDAY</code>, <code>WEDNESDAY</code>,
   * <code>THURSDAY</code>, <code>FRIDAY</code>, and <code>SATURDAY</code>.
   * @see #UCAL_SUNDAY
   * @see #UCAL_MONDAY
   * @see #UCAL_TUESDAY
   * @see #UCAL_WEDNESDAY
   * @see #UCAL_THURSDAY
   * @see #UCAL_FRIDAY
   * @see #UCAL_SATURDAY
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_WEEK,

 /**
   * Field number indicating the
   * ordinal number of the day of the week within the current month. Together
   * with the <code>DAY_OF_WEEK</code> field, this uniquely specifies a day
   * within a month.  Unlike <code>WEEK_OF_MONTH</code> and
   * <code>WEEK_OF_YEAR</code>, this field's value does <em>not</em> depend on
   * <code>getFirstDayOfWeek()</code> or
   * <code>getMinimalDaysInFirstWeek()</code>.  <code>DAY_OF_MONTH 1</code>
   * through <code>7</code> always correspond to <code>DAY_OF_WEEK_IN_MONTH
   * 1</code>; <code>8</code> through <code>15</code> correspond to
   * <code>DAY_OF_WEEK_IN_MONTH 2</code>, and so on.
   * <code>DAY_OF_WEEK_IN_MONTH 0</code> indicates the week before
   * <code>DAY_OF_WEEK_IN_MONTH 1</code>.  Negative values count back from the
   * end of the month, so the last Sunday of a month is specified as
   * <code>DAY_OF_WEEK = SUNDAY, DAY_OF_WEEK_IN_MONTH = -1</code>.  Because
   * negative values count backward they will usually be aligned differently
   * within the month than positive values.  For example, if a month has 31
   * days, <code>DAY_OF_WEEK_IN_MONTH -1</code> will overlap
   * <code>DAY_OF_WEEK_IN_MONTH 5</code> and the end of <code>4</code>.
   * @see #UCAL_DAY_OF_WEEK
   * @see #UCAL_WEEK_OF_MONTH
   * @stable ICU 2.6
   */
  UCAL_DAY_OF_WEEK_IN_MONTH,

 /**
   * Field number indicating
   * whether the <code>HOUR</code> is before or after noon.
   * E.g., at 10:04:15.250 PM the <code>AM_PM</code> is <code>PM</code>.
   * @see #UCAL_AM
   * @see #UCAL_PM
   * @see #UCAL_HOUR
   * @stable ICU 2.6
   */
  UCAL_AM_PM,

 /**
   * Field number indicating the
   * hour of the morning or afternoon. <code>HOUR</code> is used for the 12-hour
   * clock.
   * E.g., at 10:04:15.250 PM the <code>HOUR</code> is 10.
   * @see #UCAL_AM_PM
   * @see #UCAL_HOUR_OF_DAY
   * @stable ICU 2.6
   */
  UCAL_HOUR,

 /**
   * Field number indicating the
   * hour of the day. <code>HOUR_OF_DAY</code> is used for the 24-hour clock.
   * E.g., at 10:04:15.250 PM the <code>HOUR_OF_DAY</code> is 22.
   * @see #UCAL_HOUR
   * @stable ICU 2.6
   */
  UCAL_HOUR_OF_DAY,

 /**
   * Field number indicating the
   * minute within the hour.
   * E.g., at 10:04:15.250 PM the <code>UCAL_MINUTE</code> is 4.
   * @stable ICU 2.6
   */
  UCAL_MINUTE,

 /**
   * Field number indicating the
   * second within the minute.
   * E.g., at 10:04:15.250 PM the <code>UCAL_SECOND</code> is 15.
   * @stable ICU 2.6
   */
  UCAL_SECOND,

 /**
   * Field number indicating the
   * millisecond within the second.
   * E.g., at 10:04:15.250 PM the <code>UCAL_MILLISECOND</code> is 250.
   * @stable ICU 2.6
   */
  UCAL_MILLISECOND,

 /**
   * Field number indicating the
   * raw offset from GMT in milliseconds.
   * @stable ICU 2.6
   */
  UCAL_ZONE_OFFSET,

 /**
   * Field number indicating the
   * daylight savings offset in milliseconds.
   * @stable ICU 2.6
   */
  UCAL_DST_OFFSET,

 /**
   * Field number
   * indicating the extended year corresponding to the
   * <code>UCAL_WEEK_OF_YEAR</code> field.  This may be one greater or less
   * than the value of <code>UCAL_EXTENDED_YEAR</code>.
   * @stable ICU 2.6
   */
  UCAL_YEAR_WOY,

 /**
   * Field number
   * indicating the localized day of week.  This will be a value from 1
   * to 7 inclusive, with 1 being the localized first day of the week.
   * @stable ICU 2.6
   */
  UCAL_DOW_LOCAL,

  /**
   * Year of this calendar system, encompassing all supra-year fields. For example,
   * in Gregorian/Julian calendars, positive Extended Year values indicate years AD,
   *  1 BC = 0 extended, 2 BC = -1 extended, and so on.
   * @stable ICU 2.8
   */
  UCAL_EXTENDED_YEAR,

 /**
   * Field number
   * indicating the modified Julian day number.  This is different from
   * the conventional Julian day number in two regards.  First, it
   * demarcates days at local zone midnight, rather than noon GMT.
   * Second, it is a local number; that is, it depends on the local time
   * zone.  It can be thought of as a single number that encompasses all
   * the date-related fields.
   * @stable ICU 2.8
   */
  UCAL_JULIAN_DAY,

  /**
   * Ranges from 0 to 23:59:59.999 (regardless of DST).  This field behaves <em>exactly</em>
   * like a composite of all time-related fields, not including the zone fields.  As such,
   * it also reflects discontinuities of those fields on DST transition days.  On a day
   * of DST onset, it will jump forward.  On a day of DST cessation, it will jump
   * backward.  This reflects the fact that it must be combined with the DST_OFFSET field
   * to obtain a unique local time value.
   * @stable ICU 2.8
   */
  UCAL_MILLISECONDS_IN_DAY,

  /**
   * Whether or not the current month is a leap month (0 or 1). See the Chinese calendar for
   * an example of this.
   */
  UCAL_IS_LEAP_MONTH,

  /**
   * Field count
   * @stable ICU 2.6
   */
  UCAL_FIELD_COUNT,

 /**
   * Field number indicating the
   * day of the month. This is a synonym for <code>UCAL_DATE</code>.
   * The first day of the month has value 1.
   * @see #UCAL_DATE
   * Synonym for UCAL_DATE
   * @stable ICU 2.8
   **/
  UCAL_DAY_OF_MONTH=UCAL_DATE
};

namespace icu {
#if 0
}
#endif

class Calendar {
private:

public:
    enum EDaysOfWeek {
        SUNDAY = 1,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    };

    virtual ~Calendar();

    UDate getTime(UErrorCode& status) const;

    void setTime(UDate date,
                 UErrorCode& status);

    EDaysOfWeek getFirstDayOfWeek(void) const;

    UCalendarDaysOfWeek getFirstDayOfWeek(UErrorCode &status) const;

    void setFirstDayOfWeek(UCalendarDaysOfWeek value);

    void setMinimalDaysInFirstWeek(uint8_t value);

    int32_t get(UCalendarDateFields field,
                UErrorCode& status) const;

    void set(UCalendarDateFields field,
             int32_t value);

    virtual void add(UCalendarDateFields field,
                     int32_t amount,
                     UErrorCode& status);

    static Calendar* createInstance(UErrorCode& success);

    static Calendar* createInstance(const Locale& aLocale,
                                    UErrorCode& success);
};

} // namespace icu

#endif // INCLUDED_ICULESS_UNICODE_CALENDAR_H

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
