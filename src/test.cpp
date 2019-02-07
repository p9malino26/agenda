#include "StorageHandler.h"
#include <iostream>

using namespace organizer;

int main()
{
    StorageHandler database;
    Task task1(Date::getCurrentDate(), Date(2019 - 1900, Month::FEB, 6), 'a', WeekDay::MON, 0, 0, "Some homework");
    
    return 0;
}
