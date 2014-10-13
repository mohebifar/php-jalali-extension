
extern zend_class_entry *jalali_date_ce;

ZEPHIR_INIT_CLASS(Jalali_Date);

PHP_METHOD(Jalali_Date, __construct);
PHP_METHOD(Jalali_Date, mktime);
PHP_METHOD(Jalali_Date, getJalali);
PHP_METHOD(Jalali_Date, date);
PHP_METHOD(Jalali_Date, dayOfWeek);
PHP_METHOD(Jalali_Date, isLeap);
PHP_METHOD(Jalali_Date, modulus);
PHP_METHOD(Jalali_Date, getMonthName);
PHP_METHOD(Jalali_Date, getDayInWeekName);
PHP_METHOD(Jalali_Date, getNumberWord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_mktime, 0, 0, 6)
	ZEND_ARG_INFO(0, hour)
	ZEND_ARG_INFO(0, minute)
	ZEND_ARG_INFO(0, second)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, day)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_getjalali, 0, 0, 1)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_date, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_dayofweek, 0, 0, 2)
	ZEND_ARG_INFO(0, dayOfYear)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_isleap, 0, 0, 1)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_modulus, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_getmonthname, 0, 0, 1)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_getdayinweekname, 0, 0, 1)
	ZEND_ARG_INFO(0, day)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jalali_date_getnumberword, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jalali_date_method_entry) {
	PHP_ME(Jalali_Date, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Jalali_Date, mktime, arginfo_jalali_date_mktime, ZEND_ACC_PUBLIC)
	PHP_ME(Jalali_Date, getJalali, arginfo_jalali_date_getjalali, ZEND_ACC_PUBLIC)
	PHP_ME(Jalali_Date, date, arginfo_jalali_date_date, ZEND_ACC_PUBLIC)
	PHP_ME(Jalali_Date, dayOfWeek, arginfo_jalali_date_dayofweek, ZEND_ACC_PRIVATE)
	PHP_ME(Jalali_Date, isLeap, arginfo_jalali_date_isleap, ZEND_ACC_PRIVATE)
	PHP_ME(Jalali_Date, modulus, arginfo_jalali_date_modulus, ZEND_ACC_PRIVATE)
	PHP_ME(Jalali_Date, getMonthName, arginfo_jalali_date_getmonthname, ZEND_ACC_PRIVATE)
	PHP_ME(Jalali_Date, getDayInWeekName, arginfo_jalali_date_getdayinweekname, ZEND_ACC_PRIVATE)
	PHP_ME(Jalali_Date, getNumberWord, arginfo_jalali_date_getnumberword, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
