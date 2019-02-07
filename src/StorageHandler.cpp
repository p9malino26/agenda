#include "StorageHandler.h"

namespace organizer
{
    void StorageHandler::importFromFiles(const std::string& taskFileName, 
                                  const std::string& timetableFileName, 
                                  const std::string& notesFileName)
    {
        //worry about that later 
    }
	
	void StorageHandler::add_task(const Task& task)
	{
		m_tasks.emplace(std::lower_bound(m_tasks.begin(), m_tasks.end(), task), task, compareTasksByDate);
	}
}
