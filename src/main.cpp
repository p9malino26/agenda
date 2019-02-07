//============================================================================
// Name        : agenda
// Author      : Patryk Malinowski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Date.h"
#include "Event.h"
#include "Time.h"


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string temp;

void addEvents()
{
	bool enteringEvents = 1;
	// the loop below will enter multiple events
	do //while enteringEvents 
	{
		bool enteringEvent = 1;
		//the loop below will enter a single event and check if it is valid.
        
        Agenda::Event event;
        do
		{
			//both of these will then be put into a file
			bool enteringDate = 1;
			Agenda::Date date;
            
			do
			{
				short tempYear = 0, tempMonth = 0, tempDay = 0;

				cout << "Please enter the year of the event. Leave blank for this year (" << (Time::getCurrentYear() + 1900) << ").\n>";
				getline(cin, temp);
				cout << endl;
				if (!(stringstream(temp) >> tempYear))
				{
					cout << "You have chosen the current year (" << (Time::getCurrentYear() + 1900) << ")." << endl;
					tempYear = Time::getCurrentYear();
				}
				else
				{
					//when the user has entered the year
					tempYear -= 1900;
				}

				temp.clear();

				cout << "Please enter the month number of the event (1-12). Leave blank for this month (" << Agenda::Date::getStringMonthFromNum(Time::getCurrentMonth()) << ").\n>";
				getline(cin, temp);
				cout << endl;
				if (!(stringstream(temp) >> tempMonth))
				{
					cout << "You have chosen the current month (" << Agenda::Date::getStringMonthFromNum(Time::getCurrentMonth()) << ")." << endl;
					tempMonth = Time::getCurrentMonth();
				}
				else
				{
					tempMonth -= 1;
				}

				temp.clear();

				cout << "Please enter the day number of the event. Leave blank for the first day.\n>";
				getline(cin, temp);
				cout << endl;
				if (!(stringstream(temp) >> tempDay))
				{
					cout << "You have chosen the first day." << endl;
					tempDay = 0;
				}
				else
				{
					tempDay -= 1;
				}
				//try to instantiate the date
				try
				{
					date = Agenda::Date(tempYear, tempMonth, tempDay);
					//this block of code will run if the date is valid.
					cout << "The date that you have entered is " << date.getDateString() << endl;
					cout << "Are you happy with the date (y/n)\n>";
					temp.clear();
					//temp is now the answer for the question above
					cin >> temp;
					if (temp == "y")
					{
						event.date = date;
						enteringDate = 0;
					}
				}
				catch(Agenda::InvalidDateException& e)
				{
					cout << "The date that you have entered is not valid.";
				}

			}while(enteringDate);


			//after the date has been entered
			//enter the subject of the event
			cout << "Enter the subject of the event\n>";
			getline(cin, event.subject);

			//ask user to enter the information of the event
			cout << "Enter the information of the event\n>";
			getline(cin, event.information);

			cout << "Here is the information about the event that you have entered: " << endl;
			cout << event.getInfo() << endl;
			cout << "Are you happy with the event that you have entered (y/n)\n>";
			temp.clear();
			//temp is now the answer for the question above
			cin >> temp;
			if (temp == "y")
			{
				//put the event into the file
				enteringEvents = 0;
			}
			//else
			// if the event has been confirmed to have been entered
			//

		}while(enteringEvent);
	}while(enteringEvents );







}
void removeEvents();
void seeEvents();

int main()
{
	string option;
	do
	{
		cout << "Press \'a\' if you want to add an event.\n"
				"Press \'b\' if you want to remove events.\n"
				"Press \'c\' if you want to see current events.\n"
				"Press any other letter if you want to quit the program." << endl;

		cout << ">";
		getline(cin, option);
		cout << endl;

		if(option == "a")
		{
			addEvents();
		}
		else if(option == "b")
		{
			removeEvents();
		}
		else if(option == "c")
		{
			seeEvents();
		}

	}while(option == "a" || option == "b" || option == "c");

	return 0;
	
}
