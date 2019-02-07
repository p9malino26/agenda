#ifndef TASK_H
#define TASK_H

#include <iostream>

#include "Date.h"
#include "Timetable.h"


namespace organizer // NC: lowercase for namespaces
{
    struct TaskAttribTags
    {
        bool selected; //we might add more
    };
    
    struct Task
    {        
        Date 				set_date;    // NC: underscores for widely-used or global variables
        Date 				due_date;
        /*WeekType			due_week;
        WeekDay				due_day;
		LessonNumberType 	due_lesson;*/ // replaced by lesson reference
        LessonReference     due_lesson;
        bool 			    done;        // whether its done or not
        std::string 	    description; // may be capped at 64 characters
        
        TaskAttribTags 	    attrib_tags;

        Task(
            const Date& 			 _set_date,   
            const Date& 			 _due_date,
            const LessonReference&   _due_lesson,
            bool 			         _done,
            const std::string&   	 _description
        
        ):set_date      ( _set_date   ),
          due_date      ( _due_date   ),
          due_lesson    ( _due_lesson ),
          done          ( _done ),
          description   ( _description )
        {}


    };
    

}
#endif // TASK_H

