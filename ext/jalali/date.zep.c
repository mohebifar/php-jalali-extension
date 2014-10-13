
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(Jalali_Date) {

	ZEPHIR_REGISTER_CLASS(Jalali, Date, jalali, date, jalali_date_method_entry, 0);

	/**
	 * Count of days at the end of each Persian month
	 *
	 * @access protected
	 * @var array
	 */
	zend_declare_property_null(jalali_date_ce, SL("mountCounter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Reference table made by Khayam for leap years
	 *
	 * @access protected
	 * @var int
	 */
	zend_declare_property_null(jalali_date_ce, SL("khayamLeapYears"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(jalali_date_ce, SL("times"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(jalali_date_ce, SL("words"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Length of a year
	 * Calculated by Khayam is 365.2422 days (approx.);
	 * but as the years are getting shorter the new value
	 * (valid from year 1380 Per./2000 A.D.) is used instead.
	 *
	 * @access protected
	 * @var double
	 */
	zend_declare_class_constant_double(jalali_date_ce, SL("KHAYAM_YEAR"), 365.24218956 TSRMLS_CC);

	/**
	 * Recent calculations has introduced a correcting factor,
	 * which Khayam could not reach.
	 * This is used to better adjust length of each year in seconds.
	 *
	 * @access protected
	 * @var double
	 */
	zend_declare_class_constant_double(jalali_date_ce, SL("KHAYAM_YEAR_CORRECTION"), 0.00000006152 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Jalali_Date, __construct) {

	zval *_1, *_3, *_4, *_5, *_7, *_8, *_9, *_10;
	zval *_0, *_2, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 39);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 5);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 9);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 13);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 17);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 21);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 25);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 29);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 34);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 38);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 42);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 46);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 50);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 54);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 58);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 62);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 67);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 71);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 75);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 79);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 83);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 87);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 91);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 95);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 100);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 104);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 108);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 112);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 116);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 120);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 124);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("khayamLeapYears"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 16);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 62);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 93);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 124);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 155);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 186);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 216);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 246);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 276);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 306);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 336);
	zephir_array_fast_append(_2, _1);
	zephir_update_property_this(this_ptr, SL("mountCounter"), _2 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "month", 1);
	zephir_update_property_array(this_ptr, SL("words"), _3, _1 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "week", 1);
	zephir_update_property_array(this_ptr, SL("words"), _4, _1 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "number", 1);
	zephir_update_property_array(this_ptr, SL("words"), _5, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 16);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "فروردین", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "اردیبهشت", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "خرداد", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "تیر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "مرداد", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "شهریور", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "مهر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "آبان", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "آذر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دی", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بهمن", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "اسفند", 1);
	zephir_array_fast_append(_6, _1);
	zephir_update_property_array_multi(this_ptr, SL("words"), &_6 TSRMLS_CC, SL("ss"), 4, SL("month"), SL("long"));
	ZEPHIR_INIT_BNVAR(_6);
	array_init_size(_6, 16);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "فرو", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "ارد", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "خرد", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "تیر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "مر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "شهر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "مهر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "آبا", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "آذر", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دی", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "اسفـ", 1);
	zephir_array_fast_append(_6, _1);
	zephir_update_property_array_multi(this_ptr, SL("words"), &_6 TSRMLS_CC, SL("ss"), 4, SL("month"), SL("short"));
	ZEPHIR_INIT_BNVAR(_6);
	array_init_size(_6, 9);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "شنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "یکشنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دوشنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "سه‌شنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "چهارشنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "پنج‌شنبه", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "جمعه", 1);
	zephir_array_fast_append(_6, _1);
	zephir_update_property_array_multi(this_ptr, SL("words"), &_6 TSRMLS_CC, SL("ss"), 4, SL("week"), SL("long"));
	ZEPHIR_INIT_BNVAR(_6);
	array_init_size(_6, 9);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "ش", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "ی", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "د", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "س", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "چ", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "پ", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "ج", 1);
	zephir_array_fast_append(_6, _1);
	zephir_update_property_array_multi(this_ptr, SL("words"), &_6 TSRMLS_CC, SL("ss"), 4, SL("week"), SL("short"));
	ZEPHIR_INIT_BNVAR(_6);
	array_init_size(_6, 41);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "صفرم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "یکم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دوم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "سوم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "چهارم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "پنجم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "ششم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "هفتم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "هشتم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "نهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "یازدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "دوازدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "سیزدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "چهاردهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "پانزدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "شانزدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "هفدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "هجدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "نوزدهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیستم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و یکم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و دوم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و سوم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و چهارم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و پنجم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و ششم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و هفتم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و هشتم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "بیست و نهم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "سی‌ام", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "سی و یکم", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "number", 1);
	zephir_update_property_array(this_ptr, SL("words"), _1, _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "AM", 1);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "ق.ظ", 1);
	zephir_update_property_array(this_ptr, SL("words"), _7, _8 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "PM", 1);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "ب.ظ", 1);
	zephir_update_property_array(this_ptr, SL("words"), _9, _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Jalali_Date, mktime) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int _0, ZEPHIR_LAST_CALL_STATUS, _8;
	double timestamp;
	zval *hour = NULL, *minute = NULL, *second = NULL, *month = NULL, *day = NULL, *year = NULL, *_1, *_2, _3, _4 = zval_used_for_init, _5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 6, &hour, &minute, &second, &month, &day, &year);

	if (!hour) {
		hour = ZEPHIR_GLOBAL(global_null);
	}
	if (!minute) {
		minute = ZEPHIR_GLOBAL(global_null);
	}
	if (!second) {
		second = ZEPHIR_GLOBAL(global_null);
	}
	if (!month) {
		month = ZEPHIR_GLOBAL(global_null);
	}
	if (!day) {
		ZEPHIR_CPY_WRT(day, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(day);
	}
	if (!year) {
		ZEPHIR_CPY_WRT(year, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(year);
	}


	timestamp = (double) (((zephir_get_numberval(second) + (zephir_get_numberval(minute) * 60)) + ((zephir_get_numberval(hour) * 60) * 60)));
	_0 = (zephir_get_numberval(year) - 1348);
	ZEPHIR_INIT_BNVAR(year);
	ZVAL_LONG(year, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("mountCounter"), PH_NOISY_CC);
	zephir_array_fetch_long(&_2, _1, (zephir_get_numberval(month) - 1), PH_NOISY | PH_READONLY, "jalali/date.zep", 82 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	zephir_add_function(&_3, _2, day TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, ((365.24218956 * zephir_get_numberval(year))));
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(&_6, "round", &_7, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	zephir_add_function(&_4, &_3, _6 TSRMLS_CC);
	_8 = (zephir_get_numberval(&_4) - 287);
	ZEPHIR_INIT_BNVAR(day);
	ZVAL_LONG(day, _8);
	timestamp = (timestamp + (double) (zephir_get_numberval(day) * 86400));
	RETURN_MM_DOUBLE(timestamp);

}

PHP_METHOD(Jalali_Date, getJalali) {

	zend_bool _12;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, minutes, hours, months, _11;
	zval *timestamp = NULL, *seconds, *days, *years = NULL, *dayOfYear, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, _8, *_9 = NULL, *_13, *_14, *_15, *_16, *_17, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timestamp);

	ZEPHIR_SEPARATE_PARAM(timestamp);


	if (zephir_is_instance_of(timestamp, SL("DateTime") TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&timestamp, timestamp, "gettimestamp",  NULL);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(timestamp) / 60));
	ZEPHIR_CALL_FUNCTION(&_1, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(seconds);
	ZVAL_LONG(seconds, (zephir_get_numberval(timestamp) - (zephir_get_numberval(_1) * 60)));
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(timestamp) / 3600));
	ZEPHIR_CALL_FUNCTION(&_3, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, ((zephir_get_numberval(timestamp) - (zephir_get_numberval(_3) * 3600)) / 60));
	ZEPHIR_CALL_FUNCTION(&_4, "floor", &_2, &_0);
	zephir_check_call_status();
	minutes = zephir_get_intval(_4);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(timestamp) / 86400));
	ZEPHIR_CALL_FUNCTION(&_5, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, ((zephir_get_numberval(timestamp) - (zephir_get_numberval(_5) * 86400)) / 3600));
	ZEPHIR_CALL_FUNCTION(&_6, "floor", &_2, &_0);
	zephir_check_call_status();
	hours = zephir_get_intval(_6);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(timestamp) / 86400));
	ZEPHIR_CALL_FUNCTION(&_7, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(days);
	ZVAL_LONG(days, (zephir_get_numberval(_7) + 287));
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_DOUBLE(&_0, (((zephir_get_numberval(days) / 365.24218956)) - ((zephir_get_numberval(days) * 0.00000006152))));
	ZEPHIR_CALL_FUNCTION(&years, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_DOUBLE(&_0, (zephir_get_numberval(years) * 365.24218956));
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "round", &_10, &_0, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dayOfYear);
	zephir_sub_function(dayOfYear, days, _9 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(dayOfYear, 0)) {
		ZEPHIR_INIT_BNVAR(dayOfYear);
		ZVAL_LONG(dayOfYear, 366);
	}
	_11 = (zephir_get_numberval(years) + 1348);
	ZEPHIR_INIT_BNVAR(years);
	ZVAL_LONG(years, _11);
	months = 0;
	while (1) {
		_12 = months < 12;
		if (_12) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("mountCounter"), PH_NOISY_CC);
			zephir_array_fetch_long(&_14, _13, months, PH_NOISY | PH_READONLY, "jalali/date.zep", 121 TSRMLS_CC);
			_12 = ZEPHIR_GT(dayOfYear, _14);
		}
		if (!(_12)) {
			break;
		}
		months = (months + 1);
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("mountCounter"), PH_NOISY_CC);
	zephir_array_fetch_long(&_16, _15, (months - 1), PH_NOISY | PH_READONLY, "jalali/date.zep", 125 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	zephir_sub_function(_17, dayOfYear, _16 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(days);
	ZVAL_LONG(days, zephir_get_intval(_17));
	array_init_size(return_value, 9);
	zephir_array_fast_append(return_value, years);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_LONG(_18, months);
	zephir_array_fast_append(return_value, _18);
	zephir_array_fast_append(return_value, days);
	ZEPHIR_INIT_BNVAR(_18);
	ZVAL_LONG(_18, hours);
	zephir_array_fast_append(return_value, _18);
	ZEPHIR_INIT_BNVAR(_18);
	ZVAL_LONG(_18, minutes);
	zephir_array_fast_append(return_value, _18);
	zephir_array_fast_append(return_value, seconds);
	zephir_array_fast_append(return_value, dayOfYear);
	RETURN_MM();

}

/**
 * <pre>
 * <b> Day </b>
 * d: Day of month 01 to 31
 * D: A textual representation of a day ش to ج
 * j: Day of the month without leading zeros 1 to 31
 * l: (lowercase 'L') A full textual representation of the day of the week
 * N: numeric representation of the day of the week 1 to 7
 * S: Persian Presentation for the day of the month : یکم to سی و یکم
 * w: Numeric representation of the day of the week 0 to 6
 * z: The day of the year (starting from 0)
 * <b> Week </b>
 * W: week number of year
 * <b> Month </b>
 * F: A full textual representation of a month فروردین to اسفند
 * m: Numeric representation of a month, with leading zeros 01 to 12
 * M: A short textual representation of a month, فرو to اسف
 * n: Numeric representation of a month, without leading zeros 1 to 12
 * <b> Year </b>
 * L: Whether it's a leap year, 1 if it is a leap year, 0 otherwise.
 * o: Year number. This has the same value as Y
 * Y: A full numeric representation of a year, 4 digits
 * y: A two digit representation of a year
 * <b> Time </b>
 * a | A: Ante meridiem and Post meridiem
 * g: 12-hour format of an hour without leading zeros 1 to 12
 * G: 24-hour format of an hour without leading zeros 1 to 23
 * h: 12-hour format of an hour with leading zeros 01 to 12
 * H: 24-hour format of an hour with leading zeros 01 to 23
 * i: Minutes with leading zeros
 * s: Seconds with leading zeros
 * </pre>
 * @param type format
 * @return type
 */
PHP_METHOD(Jalali_Date, format) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL, *_11 = NULL, *_14 = NULL, *_20 = NULL, *_29 = NULL, *_34 = NULL, *_50 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *format = NULL, *timestamp = NULL, *date = NULL, *dayOfWeek = NULL, *_0, *_1, *patterns, *replacements, *_3, *_4, _5 = zval_used_for_init, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_13, *_15, *_16 = NULL, *_17, *_18 = NULL, *_19, *_21, *_22 = NULL, *_23 = NULL, *_24, *_25, *_26, *_27 = NULL, *_28, *_30, *_31, *_32 = NULL, *_33, *_35, *_36, *_37, *_38 = NULL, *_39, *_40 = NULL, *_41, *_42 = NULL, *_43, *_44 = NULL, *_45, *_46 = NULL, *_47, *_48 = NULL, *_49 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &format, &timestamp);

	ZEPHIR_SEPARATE_PARAM(format);
	if (!timestamp) {
		ZEPHIR_CPY_WRT(timestamp, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(timestamp);
	}


	if (Z_TYPE_P(timestamp) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&timestamp, "time", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&date, this_ptr, "getjalali", NULL, timestamp);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, date, 6, PH_NOISY | PH_READONLY, "jalali/date.zep", 175 TSRMLS_CC);
	zephir_array_fetch_long(&_1, date, 0, PH_NOISY | PH_READONLY, "jalali/date.zep", 175 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&dayOfWeek, this_ptr, "dayofweek", &_2, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(patterns);
	array_init(patterns);
	ZEPHIR_INIT_VAR(replacements);
	array_init(replacements);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "/d/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 183);
	zephir_array_fetch_long(&_4, date, 2, PH_NOISY | PH_READONLY, "jalali/date.zep", 184 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "str_pad", &_9, _4, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _8, PH_SEPARATE, "jalali/date.zep", 184);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/D/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 186);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "short", 0);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getdayinweekname", &_11, dayOfWeek, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _10, PH_SEPARATE, "jalali/date.zep", 187);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/jS/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 189);
	zephir_array_fetch_long(&_13, date, 2, PH_NOISY | PH_READONLY, "jalali/date.zep", 190 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getnumberword", &_14, _13);
	zephir_check_call_status();
	zephir_array_append(&replacements, _12, PH_SEPARATE, "jalali/date.zep", 190);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/j/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 192);
	zephir_array_fetch_long(&_15, date, 2, PH_NOISY | PH_READONLY, "jalali/date.zep", 193 TSRMLS_CC);
	zephir_array_append(&replacements, _15, PH_SEPARATE, "jalali/date.zep", 193);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/S/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 195);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "ام", 1);
	zephir_array_append(&replacements, _3, PH_SEPARATE, "jalali/date.zep", 196);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/l/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 198);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "long", 0);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getdayinweekname", &_11, dayOfWeek, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _16, PH_SEPARATE, "jalali/date.zep", 199);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/N/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 201);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, (zephir_get_numberval(dayOfWeek) + 1));
	zephir_array_append(&replacements, _3, PH_SEPARATE, "jalali/date.zep", 202);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/w/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 204);
	zephir_array_append(&replacements, dayOfWeek, PH_SEPARATE, "jalali/date.zep", 205);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/z/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 207);
	zephir_array_fetch_long(&_17, date, 6, PH_NOISY | PH_READONLY, "jalali/date.zep", 208 TSRMLS_CC);
	zephir_array_append(&replacements, _17, PH_SEPARATE, "jalali/date.zep", 208);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/F/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 216);
	zephir_array_fetch_long(&_19, date, 1, PH_NOISY | PH_READONLY, "jalali/date.zep", 217 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "long", 0);
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "getmonthname", &_20, _19, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _18, PH_SEPARATE, "jalali/date.zep", 217);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/m/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 219);
	zephir_array_fetch_long(&_21, date, 1, PH_NOISY | PH_READONLY, "jalali/date.zep", 220 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_22, "str_pad", &_9, _21, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _22, PH_SEPARATE, "jalali/date.zep", 220);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/M/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 222);
	zephir_array_fetch_long(&_24, date, 1, PH_NOISY | PH_READONLY, "jalali/date.zep", 223 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "short", 0);
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getmonthname", &_20, _24, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _23, PH_SEPARATE, "jalali/date.zep", 223);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/n/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 225);
	zephir_array_fetch_long(&_25, date, 1, PH_NOISY | PH_READONLY, "jalali/date.zep", 226 TSRMLS_CC);
	zephir_array_append(&replacements, _25, PH_SEPARATE, "jalali/date.zep", 226);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/t/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 228);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "number of days in given month", 1);
	zephir_array_append(&replacements, _3, PH_SEPARATE, "jalali/date.zep", 229);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/L/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 232);
	ZEPHIR_INIT_VAR(_26);
	zephir_array_fetch_long(&_28, date, 0, PH_NOISY | PH_READONLY, "jalali/date.zep", 233 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "isleap", &_29, _28);
	zephir_check_call_status();
	if (zephir_is_true(_27)) {
		ZEPHIR_INIT_BNVAR(_26);
		ZVAL_LONG(_26, 1);
	} else {
		ZEPHIR_INIT_BNVAR(_26);
		ZVAL_LONG(_26, 0);
	}
	zephir_array_append(&replacements, _26, PH_SEPARATE, "jalali/date.zep", 233);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/o/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 235);
	zephir_array_fetch_long(&_30, date, 0, PH_NOISY | PH_READONLY, "jalali/date.zep", 236 TSRMLS_CC);
	zephir_array_append(&replacements, _30, PH_SEPARATE, "jalali/date.zep", 236);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/Y/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 238);
	zephir_array_fetch_long(&_31, date, 0, PH_NOISY | PH_READONLY, "jalali/date.zep", 239 TSRMLS_CC);
	zephir_array_append(&replacements, _31, PH_SEPARATE, "jalali/date.zep", 239);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/y/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 241);
	zephir_array_fetch_long(&_33, date, 0, PH_NOISY | PH_READONLY, "jalali/date.zep", 242 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 100);
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "modulus", &_34, _33, _3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _32, PH_SEPARATE, "jalali/date.zep", 242);
	zephir_array_fetch_long(&_35, date, 3, PH_NOISY | PH_READONLY, "jalali/date.zep", 246 TSRMLS_CC);
	if (ZEPHIR_GT_LONG(_35, 12)) {
		ZEPHIR_INIT_BNVAR(_3);
		ZVAL_STRING(_3, "/a/", 1);
		zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 247);
		_36 = zephir_fetch_nproperty_this(this_ptr, SL("words"), PH_NOISY_CC);
		zephir_array_fetch_string(&_37, _36, SL("PM"), PH_NOISY | PH_READONLY, "jalali/date.zep", 248 TSRMLS_CC);
		zephir_array_append(&replacements, _37, PH_SEPARATE, "jalali/date.zep", 248);
	} else {
		ZEPHIR_INIT_BNVAR(_3);
		ZVAL_STRING(_3, "/a/", 1);
		zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 250);
		_36 = zephir_fetch_nproperty_this(this_ptr, SL("words"), PH_NOISY_CC);
		zephir_array_fetch_string(&_37, _36, SL("AM"), PH_NOISY | PH_READONLY, "jalali/date.zep", 251 TSRMLS_CC);
		zephir_array_append(&replacements, _37, PH_SEPARATE, "jalali/date.zep", 251);
	}
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/B/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 254);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_array_append(&replacements, _3, PH_SEPARATE, "jalali/date.zep", 255);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/g/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 257);
	zephir_array_fetch_long(&_37, date, 3, PH_NOISY | PH_READONLY, "jalali/date.zep", 258 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 12);
	ZEPHIR_CALL_METHOD(&_38, this_ptr, "modulus", &_34, _37, _3);
	zephir_check_call_status();
	zephir_array_append(&replacements, _38, PH_SEPARATE, "jalali/date.zep", 258);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/G/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 260);
	zephir_array_fetch_long(&_39, date, 3, PH_NOISY | PH_READONLY, "jalali/date.zep", 261 TSRMLS_CC);
	zephir_array_append(&replacements, _39, PH_SEPARATE, "jalali/date.zep", 261);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/h/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 263);
	zephir_array_fetch_long(&_41, date, 3, PH_NOISY | PH_READONLY, "jalali/date.zep", 264 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 12);
	ZEPHIR_CALL_METHOD(&_40, this_ptr, "modulus", &_34, _41, _3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_42, "str_pad", &_9, _40, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _42, PH_SEPARATE, "jalali/date.zep", 264);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/H/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 266);
	zephir_array_fetch_long(&_43, date, 3, PH_NOISY | PH_READONLY, "jalali/date.zep", 267 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_44, "str_pad", &_9, _43, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _44, PH_SEPARATE, "jalali/date.zep", 267);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/i/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 269);
	zephir_array_fetch_long(&_45, date, 4, PH_NOISY | PH_READONLY, "jalali/date.zep", 270 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_46, "str_pad", &_9, _45, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _46, PH_SEPARATE, "jalali/date.zep", 270);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/s/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 272);
	zephir_array_fetch_long(&_47, date, 4, PH_NOISY | PH_READONLY, "jalali/date.zep", 273 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, '0');
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_48, "str_pad", &_9, _47, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_array_append(&replacements, _48, PH_SEPARATE, "jalali/date.zep", 273);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "/u/", 1);
	zephir_array_append(&patterns, _3, PH_SEPARATE, "jalali/date.zep", 275);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_array_append(&replacements, _3, PH_SEPARATE, "jalali/date.zep", 276);
	ZEPHIR_CALL_FUNCTION(&_49, "preg_replace", &_50, patterns, replacements, format);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(format, _49);
	RETVAL_ZVAL(format, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Jalali_Date, dayOfWeek) {

	zend_bool _5;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int yearStartDay, ZEPHIR_LAST_CALL_STATUS, leapCount, _8;
	zval *dayOfYear = NULL, *year, *rasad, *count2820 = NULL, *mod2820 = NULL, *count128 = NULL, *mod128 = NULL, _0 = zval_used_for_init, *_2, *_4, *_6, *_7, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dayOfYear, &year);

	ZEPHIR_SEPARATE_PARAM(dayOfYear);


	ZEPHIR_INIT_VAR(rasad);
	ZVAL_LONG(rasad, (zephir_get_numberval(year) + 2346));
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(rasad) / 2820));
	ZEPHIR_CALL_FUNCTION(&count2820, "floor", &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2820);
	ZEPHIR_CALL_METHOD(&mod2820, this_ptr, "modulus", &_3, rasad, _2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(mod2820) / 128));
	ZEPHIR_CALL_FUNCTION(&count128, "floor", &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 128);
	ZEPHIR_CALL_METHOD(&mod128, this_ptr, "modulus", &_3, mod2820, _2);
	zephir_check_call_status();
	leapCount = 0;
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("khayamLeapYears"), PH_NOISY_CC);
		_5 = zephir_array_isset_long(_4, leapCount);
		if (_5) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("khayamLeapYears"), PH_NOISY_CC);
			zephir_array_fetch_long(&_7, _6, leapCount, PH_NOISY | PH_READONLY, "jalali/date.zep", 302 TSRMLS_CC);
			_5 = ZEPHIR_GT(mod128, _7);
		}
		if (!(_5)) {
			break;
		}
		leapCount = (leapCount + 1);
	}
	yearStartDay = ((((((zephir_get_numberval(count2820) + 1)) * 3) + (zephir_get_numberval(count128) * 5)) + zephir_get_numberval(mod128)) + leapCount);
	if (ZEPHIR_GT_LONG(dayOfYear, 0)) {
		_8 = (zephir_get_numberval(dayOfYear) - 1);
		ZEPHIR_INIT_NVAR(dayOfYear);
		ZVAL_LONG(dayOfYear, _8);
	}
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, (yearStartDay + zephir_get_numberval(dayOfYear)));
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 7);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "modulus", &_3, _2, _9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Jalali_Date, isLeap) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int rasad, ZEPHIR_LAST_CALL_STATUS;
	zval *year, *yrNam = NULL, *_0 = NULL, *_1, *_2, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &year);



	rasad = (zephir_get_numberval(year) + 2346);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, rasad);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2820);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "modulus", &_3, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 128);
	ZEPHIR_CALL_METHOD(&yrNam, this_ptr, "modulus", &_3, _0, _1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("khayamLeapYears"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "array_search", &_6, yrNam, _4);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(_5));

}

PHP_METHOD(Jalali_Date, modulus) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int aa, bb, ZEPHIR_LAST_CALL_STATUS;
	zval *a, *b, c, _0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	aa = zephir_get_intval(a);
	bb = zephir_get_intval(b);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (aa / bb));
	ZEPHIR_CALL_FUNCTION(&_1, "floor", &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(c);
	ZVAL_LONG(&c, (aa - (zephir_get_numberval(_1) * bb)));
	RETURN_LCTOR(c);

}

PHP_METHOD(Jalali_Date, getMonthName) {

	zval *month, *type = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &month, &type);

	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "long", 1);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("words"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("month"), PH_NOISY | PH_READONLY, "jalali/date.zep", 333 TSRMLS_CC);
	zephir_array_fetch(&_2, _1, type, PH_NOISY | PH_READONLY, "jalali/date.zep", 333 TSRMLS_CC);
	zephir_array_fetch_long(&_3, _2, (zephir_get_numberval(month) - 1), PH_NOISY | PH_READONLY, "jalali/date.zep", 333 TSRMLS_CC);
	RETURN_CTOR(_3);

}

PHP_METHOD(Jalali_Date, getDayInWeekName) {

	zval *day, *type = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &day, &type);

	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "long", 1);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("words"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("week"), PH_NOISY | PH_READONLY, "jalali/date.zep", 337 TSRMLS_CC);
	zephir_array_fetch(&_2, _1, type, PH_NOISY | PH_READONLY, "jalali/date.zep", 337 TSRMLS_CC);
	zephir_array_fetch(&_3, _2, day, PH_NOISY | PH_READONLY, "jalali/date.zep", 337 TSRMLS_CC);
	RETURN_CTOR(_3);

}

PHP_METHOD(Jalali_Date, getNumberWord) {

	zval *number, *_0, *_1, *_2;

	zephir_fetch_params(0, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("words"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("number"), PH_NOISY | PH_READONLY, "jalali/date.zep", 341 TSRMLS_CC);
	zephir_array_fetch(&_2, _1, number, PH_NOISY | PH_READONLY, "jalali/date.zep", 341 TSRMLS_CC);
	RETURN_CTORW(_2);

}

