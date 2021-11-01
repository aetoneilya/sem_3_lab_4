#include "Date.hpp"

// Constructor

Date::Date()
{
    std::time_t t = std::time(0); // get time now
    std::tm *now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon;
    date = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
}

Date::Date(int y, Month m, int d, int h, int min, int s)
{
    year = y;
    month = m;
    date = d;
    hour = h;
    minute = min;
    second = s;
    correct();
}

Date::Date(const Date &object)
{
    year = object.year;
    month = object.month;
    date = object.date;
    hour = object.hour;
    minute = object.minute;
    second = object.second;
    correct();
}

Date::Date(unsigned int y, Month m, unsigned int d)
{
    year = y;
    month = m;
    date = d;
    hour = 0;
    minute = 0;
    second = 0;
    correct();
}

Date::Date(unsigned int hrs, unsigned int min, unsigned int days)
{
    std::time_t t = std::time(0); // get time now
    std::tm *now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon;
    date = days;
    hour = hrs;
    minute = min;
    second = now->tm_sec;
    correct();
}

// DayInMonth

int Date::dayInMonth(int toMonth)
{
    int daysInMonth[12] = {31, 28 + leapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month + toMonth];
}

// Adds

Date Date::addSecond(int s)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.second += s;
    res.correct();

    return res;
}

Date Date::addMinute(int m)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.minute += m;
    res.correct();

    return res;
}

Date Date::addHour(int h)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.hour += h;
    res.correct();

    return res;
}

Date Date::addDay(int d)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.date += d;
    res.correct();

    return res;
}

Date Date::addMonth(int m)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.month += m;
    res.correct();

    return res;
}

Date Date::addYear(int y)
{
    Date res(year, Month(month), date, hour, minute, second);
    res.year += y;
    res.correct();

    return res;
}

// Correct

void Date::correct()
{
    while (second < 0 || second >= 60 ||
           minute < 0 || minute >= 60 ||
           hour < 0 || hour >= 24 ||
           date < 0 || date > dayInMonth(0) ||
           month < 0 || month > 12 ||
           year < 0 || year > 9999)
    {
        if (second < 0)
        {
            second += 60;
            minute -= 1;
        }
        else if (second >= 60)
        {
            minute += second / 60;
            second = second % 60;
        }

        if (minute < 0)
        {
            minute += 60;
            hour -= 1;
        }
        else if (minute >= 60)
        {
            hour += minute / 60;
            minute = minute % 60;
        }

        if (hour < 0)
        {
            hour += 24;
            date -= 1;
        }
        else if (hour >= 24)
        {
            date += hour / 24;
            hour = hour % 24;
        }

        if (date < 0)
        {
            month -= 1;
            date += dayInMonth(-1);
        }
        else if (date > dayInMonth(0))
        {
            month += 1;
            date = date % dayInMonth(0);
        }

        if (month < 0)
        {
            year -= 1;
            month += 12;
        }
        else if (month > 12)
        {
            year += 1;
            month = month % 12;
        }

        if (year < 0)
        {
            second = 0;
            minute = 0;
            hour = 0;
            date = 0;
            month = 0;
            year = 0;
        }
        else if (year > 9999)
        {
            second = 59;
            minute = 59;
            hour = 23;
            date = 31;
            month = 12;
            year = 9999;
        }
        leapYear = (year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0);
    }
}

// String formaters

std::string Date::toString() const
{
    std::string res = "";
    res += std::to_string(year) + " ";
    res += std::to_string(month + 1) + " ";
    res += std::to_string(date) + " ";

    res += std::to_string(hour) + ":";
    res += std::to_string(minute) + ":";
    res += std::to_string(second);

    return res;
}

std::string Date::formatDate(std::string format)
{
    if (format.empty())
        return format;

    std::string keyWords[7] = {"YYYY", "MMM", "MM", "DD", "hh", "mm", "ss"};
    std::string replace[7] = {
        std::to_string(year), std::to_string(month + 1), std::to_string(month),
        std::to_string(date), std::to_string(hour), std::to_string(minute),
        std::to_string(second)};

    for (int i = 0; i < 7; i++)
    {
        size_t start_pos = 0;
        while ((start_pos = format.find(keyWords[i], start_pos)) != std::string::npos)
        {
            if (keyWords[i] == "MMM")
            {
                format.replace(start_pos, keyWords[i].length(), str_months[month]);
                start_pos += str_months[month].length();
            }
            else
            {
                format.replace(start_pos, keyWords[i].length(), replace[i]);
                start_pos += keyWords[i].length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            }
        }
    }
    return format;
}

// Gets

int Date::getYear()
{
    return year;
}

Month Date::getMonth()
{
    Month res = Month(month);
    return res;
}

int Date::getDate()
{
    return date;
}

int Date::getHour()
{
    return hour;
}

int Date::getMinute()
{
    return minute;
}

int Date::getSecond()
{
    return second;
}

// Sets

void Date::setYear(int y)
{
    year = y;
    correct();
}

void Date::setMonth(Month m)
{
    month = m;
    correct();
}

void Date::setDate(int d)
{
    date = d;
    correct();
}

void Date::setHour(int h)
{
    hour = h;
    correct();
}

void Date::setMinute(int m)
{
    minute = m;
    correct();
}

void Date::setSecond(int s)
{
    second = s;
    correct();
}

// operators

void Date::operator=(Date left)
{
    year = left.year;
    month = left.month;
    date = left.date;
    hour = left.hour;
    minute = left.minute;
    second = left.second;
}

// Date Interval Class

// Constructors

DateInterval::DateInterval()
{
    year = 0;
    month = Month::JAN;
    date = 0;
    hour = 0;
    minute = 0;
    second = 0;
}

DateInterval::DateInterval(int y, Month m, int d, int h, int min, int s)
{
    year = y;
    month = m;
    date = d;
    hour = h;
    minute = min;
    second = s;
}

DateInterval::DateInterval(const DateInterval &object)
{
    year = object.year;
    month = object.month;
    date = object.date;
    hour = object.hour;
    minute = object.minute;
    second = object.second;
}

// Gets

int DateInterval::getYear()
{
    return year;
}

Month DateInterval::getMonth()
{
    Month res = Month(month);
    return res;
}

int DateInterval::getDate()
{
    return date;
}

int DateInterval::getHour()
{
    return hour;
}

int DateInterval::getMinute()
{
    return minute;
}

int DateInterval::getSecond()
{
    return second;
}

// Sets

void DateInterval::setYear(int y)
{
    year = y;
}

void DateInterval::setMonth(Month m)
{
    month = m;
}

void DateInterval::setDate(int d)
{
    date = d;
}

void DateInterval::setHour(int h)
{
    hour = h;
}

void DateInterval::setMinute(int m)
{
    minute = m;
}

void DateInterval::setSecond(int s)
{
    second = s;
}

// Operator

void DateInterval::operator=(DateInterval left)
{
    year = left.year;
    month = left.month;
    date = left.date;
    hour = left.hour;
    minute = left.minute;
    second = left.second;
}

// Interval

DateInterval Date::getInterval(const Date &another) const
{
    DateInterval res(another.year - year, Month(another.month - month), another.date - date,
                     another.hour - hour, another.minute - minute, another.second - second);

    return res;
}

Date Date::addInterval(const DateInterval &interval) const
{
    Date res(year + interval.year, Month(month + interval.month), date + interval.date,
             hour + interval.hour, minute + interval.minute, second + interval.second);

    return res;
}