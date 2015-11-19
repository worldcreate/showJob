#ifndef _JOBTABLE_H_
#define _JOBTABLE_H_

#include "Job.h"
#include "Color.h"
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class JobTable{
public:
	static int jobHeight;
	JobTable();
	~JobTable();
	void addMachine(char[]);
	void draw(HDC);
	int getMaxTime();
private:
	vector<vector<Job> > table;
	int maxTime;
	Color *color;
};

#endif