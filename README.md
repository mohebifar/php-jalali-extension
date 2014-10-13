PHP Jalali Extension
====================
Jalali extension is a php extension written in C which allows you to format a timestamp by *Hejri Date Format* or get the timestamp by giving *Hejri Dates*.

This is simply **as fast as** `date()` and `mktime()` functions.

Installation
==========
Copy the `build/jalali.so` into the php extensions directory. Then add this line into the `php.ini` :

    extension=jalali.so

Done !

## PHP Version ##
If you are running php on a windows machine when developing or **you cannot install the extension for some reason**, You can include the **php version** which exists in `php` directory. **It uses the extension if it existed** otherwise It defines the same class in php context.

How to use
=========
Create an object of `\Jalali\Date`.


	$jDate = new \Jalali\Date();

You can format the date by calling `$jDate::date`. The function covers all of the native `date()` function literals.

	$jDate->date("l jS F Y");
	// Output: دوشنبه بیست و یکم مهر 1393

And Also You can get the timestamp of a date time.

	$jDate->mktime(15, 45, 0, 7, 21, 1393);

Benchmark
=========
As you know calculating Hejri Date from a timestamp includes of a lot of addition, subtraction, multiplication, and division, so it increases cpu cycles.

This is the fastest class ever known in php to do that !

We compare the extension with [sallar/jDateTime](https://github.com/sallar/jDateTime) so that we do the same `date("Y m d l s f")` action with both classes 100,000 times.

I ran the script on an ubuntu 14.04 machine with php5.5 installed and enabled opcache.

	$phpJDate = new jDateTime();
	$extJDate = new \Jalali\Date();
	
	$phpTime = 0;
	$extTime = 0;
	
	$time = time();
	for($i = 0; $i < 100000; $i++) {
	    $start = microtime(true);
	    $phpJDate->date("Y m d l s f");
	    $phpTime += microtime(true) - $start;
	
	    $start = microtime(true);
	    $extJDate->date("Y m d l s f");
	    $extTime += microtime(true) - $start;
	}
	
	var_dump($phpTime, $extTime);
	
And the result is :

	18.459370851517 seconds for sallar/jDateTime
	5.1387049674988 seconds for mohebifar/php-jalali-extension
