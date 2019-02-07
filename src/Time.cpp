/*
 * Time.cpp
 *
 *  Created on: 16 Sep 2017
 *      Author: theCodeSpewer
 */
#include "Time.h"
#include "Date.h"

#include <ctime>

namespace organizer
{

    time_t Time::t = time(NULL);
    tm* Time::timePtr = localtime(&t);

    void Time::update()
    {
        t = time(NULL);
        timePtr = localtime(&t);
    }
	/*
	 * Please note:
	 *
	 * The two lines of code below were inspired by the code found in the website below:
	 * http://www.cplusplus.com/forum/beginner/32329/
	 */


	Year_t Time::getCurrentYear()
	{
		return timePtr->tm_year;
	}
	
	Month_t Time::getCurrentMonth()
	{
		return Month_t( timePtr->tm_mon);
	}
	
	Day_t Time::getCurrentDay()
	{
		return Day_t( timePtr->tm_mday - 1);
	}
    
}




