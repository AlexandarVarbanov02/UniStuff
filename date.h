#pragma once

class Date {
    unsigned int day; //cant be less than 0
    unsigned int month;
    unsigned int year;

    days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //each month has that many days

public:
    
    Date(unsigned int day, unsigned int month, unsigned int year) {
        setYear(year); //set year and check if leap
        setMonth(month); //regardless of year always 12 months
        setDay(day); // months have different number of days
    }

    bool isLeapYear();

    unsigned int getDay() const;

    unsigned int getMonth() const;

    unsigned int getYear() const; 

    void setDay(unsigned int day);

    void setMonth(unsigned int month);
    
    void setYear(unsigned int year);

    //bool validateMonth(unsigned int month);


    bool operator<=(const Date& other); //check if first date is before second date

}

