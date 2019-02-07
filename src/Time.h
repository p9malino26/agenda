/*
 * Time.h
 *
 *  Created on: 16 Sep 2017
 *      Author: theCodeSpewer
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>

using namespace std;

namespace organizer
{

    enum class Month {JAN = 0, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    //typedef DayName Day;
    typedef int         Year_t;
    typedef Month       Month_t;
    typedef int         Day_t; // will be an nth day in a month, not a week day with a name

    class Time
    {
        static time_t t;
        static tm* timePtr;
    public:
        static void update(); // has to be called manually
        
        static Year_t getCurrentYear(); //stay
        static Month_t getCurrentMonth();//stay
        static Day_t getCurrentDay();
        
    };

}

#endif /* TIME_H_ */
