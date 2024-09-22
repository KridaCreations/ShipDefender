#include "nodecounter.h"

int nodecounter::getNewId()
{
	if (this->emptyids.size() > 0)
	{
		int result = this->emptyids.back();
		this->emptyids.pop_back();
		return result;
	}
	else
	{
		this->counter++;
		return this->counter;
	}
}
void nodecounter::removeId(int id)
{
	this->emptyids.push_back(id);
}