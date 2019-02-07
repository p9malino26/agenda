#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "Date.h"
#include <iostream>
#include <map>
/**
 * @todo write docs
 */

namespace organizer
{
    //N.B. if WeekNumberType is 255, it means that the task is not set for a particular lesson
    typedef char WeekType;
    //we are using enum above for the day
    typedef uint8_t LessonNumberType; // e.g. period 1, 2 ,3, ...
    typedef uint16_t TimeOfDayType;
    
    class Timetable;
    
    struct Lesson
    {
        std::string      subject_name; // capped at 20 characters
        std::string      teacher_name; // capped at 20 characters
        std::string      room_name;      // capped at 10
        TimeOfDayType    start_time;      // number of minutes past midnight
        TimeOfDayType    end_time;
        
        Lesson(){}
        
        Lesson( //main ctor
            std::string      _subject_name,
            std::string      _teacher_name,
            std::string      _room_name,  
            TimeOfDayType    _start_time, 
            TimeOfDayType    _end_time
        )
            :subject_name(_subject_name),
             teacher_name(_teacher_name),
             room_name   (_room_name   ),
             start_time  (_start_time  ),
             end_time    (_end_time    )
        {}
        
        
        Lesson(const Lesson& other) // copy ctor
            :subject_name(other.subject_name),
             teacher_name(other.teacher_name),
             room_name   (other.room_name   ),
             start_time  (other.start_time  ),
             end_time    (other.end_time    )
        {
            std::cout << "Copied!\n";
        }
    };
    
    struct LessonReference // may be deprecated
    {
        //structure for lesson composite key        
        WeekType         week;
        WeekDay          day;
        LessonNumberType lesson_number;
        
        LessonReference(
            WeekType         _week,
            WeekDay          _day,
            LessonNumberType _lesson_number
            
        )
        :   week            (_week),
            day             (_day),
            lesson_number   (_lesson_number)
        
        {}
    };
    
    class Timetable
    {
        
        typedef std::map<LessonNumberType, Lesson> PeriodToLesson;
        typedef std::map<WeekDay, PeriodToLesson>  DayToPeriod;
        typedef std::map<WeekType, DayToPeriod>    WeekToDay;
        
        //WeekToDay m_data;
        WeekToDay m_data;
    public:
        
        Timetable(){}
        
        inline DayToPeriod& operator[](WeekType weekNum)
        {
            return m_data[weekNum];
        }
        
    
    };
    
    
}
#endif // TIMETABLE_H
