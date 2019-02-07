/*
 * Event.cpp
 *
 *  Created on: 17 Sep 2017
 *      Author: theCodeSpewer
 */
#include "Event.h"


/*Event::Event(string data)
{
    unsigned short tempYear;
    uint8_t tempMonth, tempDay;
    stringstream dataStream(data);
    string nodeBuffer;
    getline(dataStream, nodeBuffer, ',');
    //stringstream(nodeBuffer) >> this->date.year;
    stringstream(nodeBuffer) >> tempYear;
    getline(dataStream, nodeBuffer, ',');
    stringstream(nodeBuffer) >> tempMonth;
    getline(dataStream, nodeBuffer, ',');
    stringstream(nodeBuffer) >> tempDay;
    getline(dataStream, this->subject, ',');
    getline(dataStream, this->information, ',');
    this->date = Date(tempYear, tempMonth, tempDay);
}*/

Task::Task(const Date& date, const string& _subject, const string& _information)
    :date(date)
{
	strcpy(subject, _subject.c_str());
	strcpy(information, _information.c_str());
}

Task::Task()
{

}

Task::Task(const Date& date, const char* _subject, const char* _information)
	:date(date)
{
	strcpy(subject, _subject);
	strcpy(information, _information);
}


string Task::getInfo() const
{
    stringstream infoBuf;
	infoBuf << "Date of event: " << this->date.getDateString() << "\n"
	 	<< "Subject of event: " << this->subject << "\n"
		<< "Information of event: " << this->information;

    return infoBuf.str();
}

void Task::printInfo() const
{
	std::cout << "Date of event: " << this->date.getDateString() << "\n"
	<< "Subject of event: " << this->subject << "\n"
	<< "Information of event: " << this->information << std::endl;
}





