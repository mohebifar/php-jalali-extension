<?php

include_once "../php/Date.php";

// Create an instance
$jdate = new \Jalali\Date();

// Call date method to format time
echo $jdate->date('Y m d');
