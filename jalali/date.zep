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
     * Count of days at the end of each Persian month
     *
     * @access protected
     * @var array
     */
    protected mountCounter = [
        0, 31, 62, 93, 124, 155,
        186, 216, 246, 276, 306, 336
    ];

    public function mktime(year, month, day, hour=0, minute=0, second=0)
    {
        float timestamp;

        let timestamp = second + minute * 60 + hour * 60 * 60;
        let year = year - 1348;
        let day = this->mountCounter[month - 1] + day + round(( self::KHAYAM_YEAR * year), 0) - 287;
        let timestamp = timestamp + day * 86400;

        return timestamp;
    }

}
