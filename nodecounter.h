#pragma once
#include <vector>

static class nodecounter
{
public:
	int counter = 0;
	std::vector<int>emptyids;

	int getNewId();
	void removeId(int id);
};

