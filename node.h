#pragma once
#include<vector>

class node
{
public:
	double x = 0, y = 0;
	int nodeid;
	node(double x, double y,int id);
	void ready();
	void process(double delta = 0.0);
	void draw();
	node() = delete;
};

