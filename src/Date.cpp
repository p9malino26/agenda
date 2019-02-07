/*
 * Date.cpp
 *
 *  Created on: 15 Sep 2017
 *      Author: theCodeSpewer
 */

#include "Date.h"
#include "Timetable.h"
#include "Time.h"

using namespace std;

namespace organizer
{

    bool Date::good() const // sorted2
    {
        /*
        * Please note:
        * The code used inside the body of this function was inspired by the code found in:
        * http://www.zedwood.com/article/cpp-checkdate-function-date-validation
        */
        //gregorian dates started in 1582
        if (!(1582 <= (this->year + 1900))) //comment these 2 lines out if it bothers you
            return false;
        if (!(1 <= (int(this->month) + 1) && (int(this->month) + 1) <= 12))
            return false;
        if (!(1 <= (this->day + 1) && (this->day + 1) <= 31))
            return false;
        if (((this->day + 1) == 31)
                && ((int(this->month) + 1) == 2 || (int(this->month) + 1) == 4
                        || (int(this->month) + 1) == 6 || (int(this->month) + 1) == 9
                        || (int(this->month) + 1) == 11))
            return false;
        if (((this->day + 1) == 30) && ((int(this->month) + 1) == 2))
            return false;
        if (((int(this->month) + 1) == 2) && ((this->day + 1) == 29)
                && ((this->year + 1900) % 4 != 0))
            return false;
        if (((int(this->month) + 1) == 2) && ((this->day + 1) == 29)
                && ((this->year + 1900) % 400 == 0))
            return true;
        if (((int(this->month) + 1) == 2) && ((this->day + 1) == 29)
                && ((this->year + 1900) % 100 == 0))
            return false;
        if (((int(this->month) + 1) == 2) && ((this->day + 1) == 29)
                && ((this->year + 1900) % 4 == 0))
            return true;

        return true;
    }

    //to implement

    WeekDay_t Date::getWeekday() const // throws
    {
        /*
        * Please Note:
        *
        * Some of the code below was inspired by the code found in the website below:
        * https://stackoverflow.com/questions/11972368/c-get-which-day-by-input-date
        *
        */
        if (!this->good())
        {
            throw InvalidDateOperationException("Attempt to get weekday from invalid date.");
        }
        tm timeStruct = { };
        timeStruct.tm_year = this->year;
        timeStruct.tm_mon = int(this->month);
        timeStruct.tm_mday = this->day;
        timeStruct.tm_hour = 12;    //  To avoid any doubts about summer time, etc.
        mktime(&timeStruct);
        return WeekDay_t(timeStruct.tm_wday);
    }

    Date Date::getCurrentDate()
    {
        Time::update();
        return Date {Time::getCurrentYear(), Time::getCurrentMonth(), Time::getCurrentDay()};
    }


    string getStringWeekday(WeekDay_t dayNum)
    {
        switch (dayNum) {
        case WeekDay::MON:
            return string("Monday");
            break;
        case WeekDay::TUE:
            return string("Tuesday");
            break;
        case WeekDay::WED:
            return string("Wednesday");
            break;
        case WeekDay::THU:
            return string("Thursday");
            break;
        case WeekDay::FRI:
            return string("Friday");
            break;
        case WeekDay::SAT:
            return string("Saturday");
            break;
        case WeekDay::SUN:
            return string("Sunday");
            break;
        default:
            return string("Error");
        }
    }

    string getStringMonth(Month_t month)
    {
        switch (month) {
        case Month::JAN:
            return string("January");
            break;
        case Month::FEB:
            return string("February");
            break;
        case Month::MAR:
            return string("March");
            break;
        case Month::APR:
            return string("April");
            break;
        case Month::MAY:
            return string("May");
            break;
        case Month::JUN:
            return string("June");
            break;
        case Month::JUL:
            return string("July");
            break;
        case Month::AUG:
            return string("August");
            break;
        case Month::SEP:
            return string("September");
            break;
        case Month::OCT:
            return string("October");
            break;
        case Month::NOV:
            return string("November");
            break;
        case Month::DEC:
            return string("December");
            break;
        default:
            return string("Error");
        }
    }

    string Date::getDateString() const
    {

        stringstream dateStringBuffer;

        dateStringBuffer << getStringWeekday(getWeekday()) << " " << (day + 1) << " " 
            << getStringMonth(month) << " " << (this->year + 1900);

        return dateStringBuffer.str();
    }
    
    
    string Date::getShortDate() const
    {
        stringstream returnBuffer;
        returnBuffer << (this->day + 1) << '/' << (int(this->month) + 1 )<< '/' << (this->year + 1900);
        return returnBuffer.str();
    }


    bool Date::operator>(const Date& other) const
    {
        if(this->year > other.year) return true;
        else if(this->year < other.year) return false;
        else //the years are equal
        {
            //we look at the months
            if(this->month > other.month) return true;
            else if(this->month < other.month) return false;
            else //both years and months are equal
            {
                //we look at the days
                if(this->day > other.day) return true;
                else return false;
            }
        }
    }

    bool Date::operator==(const Date& other) const
    {
        return this->day == other.day && this->month == other.month && this->year == other.year;
    }

    bool Date::operator>=(const Date& other) const
    {
        return this->operator>(other) || this->operator==(other);
    }

    bool Date::operator<(const Date& other) const
    {
        return !(*this >= other);
    }

    bool Date::operator<=(const Date& other) const
    {
        return !(*this > other);
    }

    std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        os << (date.day + 1) << '/' << (int(date.month) + 1) << '/' << (date.year + 1900);
        return os;
    }

}
