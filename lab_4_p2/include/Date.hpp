#pragma once
#include <iostream>
#include <string>
#include <ctime>

enum Month
{
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

class Date;

class DateInterval
{
private:
    int year;
    int month;
    int date;
    int hour;
    int minute;
    int second;

    friend Date;
    
public:
    DateInterval();
    DateInterval(const DateInterval &object);
    DateInterval(int y, Month m, int d, int h, int min, int s);

    int getYear();
    Month getMonth();
    int getDate();
    int getHour();
    int getMinute();
    int getSecond();

    void setYear(int y);
    void setMonth(Month m);
    void setDate(int d);
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    void operator=(DateInterval left);
};

class Date
{
private:
    int year;
    int month;
    int date;
    int hour;
    int minute;
    int second;

    bool leapYear;

    int dayInMonth(int toMonth);
    void correct();

    std::string str_months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                                  "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

public:
    // Операции addYears, addMonths, addDays, addHours, addMinutes, addSeconds
    // должны возвращать новый объект «по значению», оставляя исходный объект
    // неизменным.
    Date addSecond(int s);
    Date addMinute(int m);
    Date addHour(int h);
    Date addDay(int d);
    Date addMonth(int m);
    Date addYear(int y);

    // today's time
    Date();
    Date(int y, Month m, int d, int h, int min, int s);
    Date(const Date &object);
    Date(unsigned int year, Month m, unsigned int day);
    Date(unsigned int hrs, unsigned int min, unsigned int days);

    int getYear();
    Month getMonth();
    int getDate();
    int getHour();
    int getMinute();
    int getSecond();

    void setYear(int y);
    void setMonth(Month m);
    void setDate(int d);
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    void operator=(Date left);

    DateInterval getInterval(const Date &another) const;
    Date addInterval(const DateInterval & interval) const;

    std::string formatDate(std::string format);
    std::string toString() const;
};
