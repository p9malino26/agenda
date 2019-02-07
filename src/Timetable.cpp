#include "Timetable.h"



namespace organizer
{
    void Timetable::doSomething()
    {
        std::cout << m_data['a'][ WeekDay::MON][3].subject_name << std::endl;
    }

}
