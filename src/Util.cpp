#include "Util.h"

//tested fully
bool indexFound(const std::vector<unsigned int>& toDelete, unsigned int index)
{
	for(unsigned int i = 0; i < toDelete.size(); i++)
	{
		if(toDelete[i] == index)
		{
			return true;
		}
	}
	
	return false;
}
