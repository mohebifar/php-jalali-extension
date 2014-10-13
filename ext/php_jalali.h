
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_JALALI_H
#define PHP_JALALI_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_JALALI_NAME        "phpjalali"
#define PHP_JALALI_VERSION     "0.0.1"
#define PHP_JALALI_EXTNAME     "jalali"
#define PHP_JALALI_AUTHOR      ""
#define PHP_JALALI_ZEPVERSION  "0.5.2a"
#define PHP_JALALI_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(jalali)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(jalali)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(jalali)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(jalali_globals_id, zend_jalali_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (jalali_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_jalali_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(jalali_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(jalali_globals)
#endif

#define zephir_globals_def jalali_globals
#define zend_zephir_globals_def zend_jalali_globals

extern zend_module_entry jalali_module_entry;
#define phpext_jalali_ptr &jalali_module_entry

#endif
