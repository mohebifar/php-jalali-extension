namespace Jalali;

class Date
{
    /**
     * Length of a year
     * Calculated by Khayam is 365.2422 days (approx.);
     * but as the years are getting shorter the new value
     * (valid from year 1380 Per./2000 A.D.) is used instead.
     *
     * @access protected
     * @var double
     */
    const KHAYAM_YEAR = 365.24218956;

    /**
     * Recent calculations has introduced a correcting factor,
     * which Khayam could not reach.
     * This is used to better adjust length of each year in seconds.
     *
     * @access protected
     * @var double
     */
    const KHAYAM_YEAR_CORRECTION = 0.00000006152;

    /**
     * Count of days at the end of each Persian month
     *
     * @access protected
     * @var array
     */
    protected mountCounter = [
        0, 31, 62, 93, 124, 155,
        186, 216, 246, 276, 306, 336
    ];

    /**
     * Reference table made by Khayam for leap years
     *
     * @access protected
     * @var int
     */
    protected khayamLeapYears = [
        5, 9, 13, 17, 21, 25, 29,
        34, 38, 42, 46, 50, 54, 58, 62,
        67, 71, 75, 79, 83, 87, 91, 95,
        100, 104, 108, 112, 116, 120, 124, 0
    ];

    protected static times;

    protected words;

    public function __construct() {
        let this->words["month"] = [];
        let this->words["week"] = [];
        let this->words["number"] = [];

        let this->words["month"]["long"] = ["فروردین", "اردیبهشت", "خرداد", "تیر", "مرداد", "شهریور", "مهر", "آبان", "آذر", "دی", "بهمن", "اسفند"];
        let this->words["month"]["short"] = ["فرو", "ارد", "خرد", "تیر", "مر", "شهر", "مهر", "آبا", "آذر", "دی", "بهم", "اسفـ"];

        let this->words["week"]["long"] = ["شنبه", "یکشنبه", "دوشنبه", "سه‌شنبه", "چهارشنبه", "پنج‌شنبه", "جمعه"];
        let this->words["week"]["short"] = ["ش", "ی", "د", "س", "چ", "پ", "ج"];

        let this->words["number"] = [
           "صفرم", "یکم", "دوم", "سوم", "چهارم", "پنجم", "ششم", "هفتم", "هشتم", "نهم", "دهم",
           "یازدهم", "دوازدهم", "سیزدهم", "چهاردهم", "پانزدهم", "شانزدهم", "هفدهم", "هجدهم", "نوزدهم", "بیستم",
           "بیست و یکم", "بیست و دوم", "بیست و سوم", "بیست و چهارم", "بیست و پنجم", "بیست و ششم", "بیست و هفتم", "بیست و هشتم", "بیست و نهم",
           "سی‌ام", "سی و یکم"
        ];

        let this->words["AM"] = "ق.ظ";
        let this->words["PM"] = "ب.ظ";
    }

    public function mktime(hour=null, minute=null, second=null, month=null, day=null, year=null)
    {
        float timestamp;

        let timestamp = second + minute * 60 + hour * 60 * 60;
        let year = year - 1348;
        let day = this->mountCounter[month - 1] + day + round(( self::KHAYAM_YEAR * year), 0) - 287;
        let timestamp = timestamp + day * 86400;

        return timestamp;
    }


    public function getJalali(timestamp) {

        if(timestamp instanceof \DateTime) {
            let timestamp = timestamp->getTimestamp();
        }

        var seconds;
        var minutes;
        var hours;
        var days;
        var years;
        var months;
        var dayOfYear;

        // Modulu Operator
        // $a - floor($a/$b) * $b

        let seconds = timestamp - floor(timestamp/60) * 60;
        let minutes = (int) floor((timestamp - floor(timestamp/3600) * 3600) / 60);
        let hours = (int) floor((timestamp - floor(timestamp/86400) * 86400) / 3600);

        let days = floor(timestamp / 86400) + 287;
        let years = floor((days / self::KHAYAM_YEAR) - (days * self::KHAYAM_YEAR_CORRECTION));
        let dayOfYear = days - round(years * self::KHAYAM_YEAR, 0);

        if (dayOfYear == 0) {
            let dayOfYear = 366;
        }

        let years = years + 1348;
        let months = 0;

        while months < 12 && dayOfYear > this->mountCounter[months] {
            let months = months + 1;
        }

        let days = (int) (dayOfYear - this->mountCounter[months - 1]);

        return [years, months, days, hours, minutes, seconds, dayOfYear];
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
    public function format(format, timestamp = null)
    {
        if(timestamp == null) {
            let timestamp = time();
        }

        var date;
        let date = this->getJalali(timestamp);

        var dayOfWeek;
        let dayOfWeek = this->dayOfWeek(date[6], date[0]);

        var patterns;
        let patterns = [];
        var replacements;
        let replacements = [];

        // Day
        let patterns[] = "/d/";
        let replacements[] = str_pad(date[2], 2, '0', STR_PAD_LEFT);

        let patterns[] = "/D/";
        let replacements[] = this->getDayInWeekName(dayOfWeek, "short");

        let patterns[] = "/jS/";
        let replacements[] = this->getNumberWord(date[2]);

        let patterns[] = "/j/";
        let replacements[] = date[2];

        let patterns[] = "/S/";
        let replacements[] = "ام";

        let patterns[] = "/l/";
        let replacements[] = this->getDayInWeekName(dayOfWeek, "long");

        let patterns[] = "/N/";
        let replacements[] = dayOfWeek + 1;

        let patterns[] = "/w/";
        let replacements[] = dayOfWeek;

        let patterns[] = "/z/";
        let replacements[] = date[6];

        // Week
        // let patterns[] = "/w/";
        // let replacements[] = "nth week of year";

        // Month

        let patterns[] = "/F/";
        let replacements[] = this->getMonthName(date[1], "long");

        let patterns[] = "/m/";
        let replacements[] = str_pad(date[1], 2, '0', STR_PAD_LEFT);

        let patterns[] = "/M/";
        let replacements[] = this->getMonthName(date[1], "short");

        let patterns[] = "/n/";
        let replacements[] = date[1];

        let patterns[] = "/t/";
        let replacements[] = "number of days in given month";

        // Year
        let patterns[] = "/L/";
        let replacements[] = this->isLeap(date[0]) ? 1 : 0;

        let patterns[] = "/o/";
        let replacements[] = date[0];

        let patterns[] = "/Y/";
        let replacements[] = date[0];

        let patterns[] = "/y/";
        let replacements[] = this->modulus(date[0], 100);


        // Time
        if(date[3] > 12) {
            let patterns[] = "/a/";
            let replacements[] = this->words["PM"];
        } else {
            let patterns[] = "/a/";
            let replacements[] = this->words["AM"];
        }

        let patterns[] = "/B/";
        let replacements[] = 0;

        let patterns[] = "/g/";
        let replacements[] = this->modulus(date[3], 12);

        let patterns[] = "/G/";
        let replacements[] = date[3];

        let patterns[] = "/h/";
        let replacements[] = str_pad(this->modulus(date[3], 12), 2, '0', STR_PAD_LEFT);

        let patterns[] = "/H/";
        let replacements[] = str_pad(date[3], 2, '0', STR_PAD_LEFT);

        let patterns[] = "/i/";
        let replacements[] = str_pad(date[4], 2, '0', STR_PAD_LEFT);

        let patterns[] = "/s/";
        let replacements[] = str_pad(date[4], 2, '0', STR_PAD_LEFT);

        let patterns[] = "/u/";
        let replacements[] = 0;

        let format = preg_replace(patterns, replacements, format);

        return format;
    }


    private function dayOfWeek(dayOfYear, year)
    {
        var rasad;
        var count2820;
        var mod2820;
        var count128;
        var mod128;
        int yearStartDay;

        let rasad = year + 2346;

        let count2820 = floor(rasad / 2820);
        let mod2820 = this->modulus(rasad, 2820);
        let count128 = floor(mod2820 / 128);
        let mod128 = this->modulus(mod2820, 128);

        int leapCount;
        let leapCount = 0;
        while (isset(this->khayamLeapYears[leapCount]) && mod128 > this->khayamLeapYears[leapCount]) {
            let leapCount = leapCount + 1;
        }

        let yearStartDay = (count2820 + 1) * 3 + count128 * 5 + mod128 + leapCount;
        if (dayOfYear > 0) {
            let dayOfYear = dayOfYear - 1;
        }

        return this->modulus(yearStartDay + dayOfYear, 7);
    }

    private function isLeap(year) {
        var yrNam;
        int rasad;
        let rasad = year + 2346;
        let yrNam = this->modulus(this->modulus(rasad, 2820), 128);
        return (boolean) array_search(yrNam, this->khayamLeapYears);
    }

    private function modulus(a, b) {
        int aa;
        let aa = (int) a;
        int bb;
        let bb = (int) b;
        var c;
        let c = aa - floor(aa/bb) * bb;
        return c;
    }

    private function getMonthName(month, type = "long") {
        return this->words["month"][type][month - 1];
    }

    private function getDayInWeekName(day, type = "long") {
        return this->words["week"][type][day];
    }

    private function getNumberWord(number) {
        return this->words["number"][number];
    }

}
