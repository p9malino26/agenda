#ifndef STORAGEHANDLER_H
#define STORAGEHANDLER_H

/**
 * @todo write docs
 */

#include <string>
#include <list>
#include <vector>

#include "Date.h"
#include "Timetable.h"
#include "Task.h"
#include "Note.h"

namespace organizer
{
    
    typedef std::list<Task> 	TaskContainer;
    typedef std::vector<Note> 	NoteContainer;

    class StorageHandler
    {
        TaskContainer m_tasks;
        Timetable     m_timetable;
        NoteContainer m_notes;

    public:
        void import_from_files(const std::string& taskFileName, 
                           const std::string& timetableFileName, 
                           const std::string& notesFileName);

        void add_note(const Note& note);// sorted
        void add_task(const Task& task);
		Timetable& get_timetable() { return m_timetable;}
		
		
    private:    
        void importTasks(const std::string& taskFileName); 
    };
	
	static bool compareTasksByDate(const Task& first, const Task& second)
	{
		return (first.due_date < second.due_date);
	}
}
#endif // STORAGEHANDLER_H
