/*
 * Date.h
 *
 *  Created on: 15 Sep 2017
 *      Author: theCodeSpewer
 */

#ifndef DATE_H_
#define DATE_H_

#include "Time.h"

#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <sstream>

using namespace std;

namespace organizer
{

    enum class WeekDay {MON = 0, TUE, WED, THU, FRI, SAT, SUN};
    typedef WeekDay     WeekDay_t;
    
    //year is stored as number of years since 1900!
    struct Date
    {
        //specific object methods
        Date(Year_t year, Month_t month, Day_t day)
            :year(year), month(month), day(day)
        {}
        Date() {} //black constructor
        /*unsigned short getYear() const;
        uint8_t getMonth() const;
        uint8_t getDay()const;*/
        WeekDay_t getWeekday() const; // will return the enum form of day // throws
        
        string getDateString() const;
        string getShortDate() const;

        static Date getCurrentDate();

        //general static methods

        bool good() const;

        //overloaded operators
        

        
        bool operator>(const Date& other) const;
        bool operator==(const Date& other) const;

        bool operator>=(const Date& other) const;
        
        bool operator<(const Date& other) const;
        bool operator<=(const Date& other) const;
        //members
        Year_t year;
        Month_t month;
        Day_t day;
        //methods
    };

    string getStringWeekday(WeekDay_t day);
    string getStringMonth(Month_t month);
    
    


    std::ostream& operator<<(std::ostream& os, const Date& date);

    class InvalidDateOperationException: public exception
    {	public:
            InvalidDateOperationException(const char* message)
                :message(message)
            {}
            virtual const char* what() const throw()
            {
                return message;
            }
        private:
            const char* message;

    };

}

#endif /* DATE_H_ */
