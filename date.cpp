#include "date.h"
#include <iostream>

bool Date::isLeapYear(unsigned int year)
{
    if(year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
        //https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
}

void Date::setYear(unsigned int year)
{
    this->year = year;

    if(isLeapYear(unsigned int year))
    {
        days_of_month[1] = 29;
    }
    else 
    {
        days_of_month[1] = 28;
    }
}

void Date::setMonth(unsigned int month)
{
    if(month > 12 || month == 0) // month cant be more than 12 or 0
    {
        //validateMonth();
        month = 1;
    }
    this->month = month;
}

void Date::setDay(unsigned int day)
{
    if(day > days_of_month[month-1] || days == 0)
    {
        day = 1;
        //validateDay();
    }
    this->day = day;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

bool Date::operator<=(const Date& other) const 
{
    return year<other.year || year==other.year && month<other.month || year==other.year && month==other.month && day<=other.day;
}

unsigned int Date::getDay() const
{
    return day;
}

unsigned int Date::getMonth() const
{
    return month;
}

unsigned int Date::getYear() const
{
    return year;
}