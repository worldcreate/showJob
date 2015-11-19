#ifndef _JOB_H_
#define _JOB_H_

#include "Util.h"
#include <string>

using namespace std;

class Job{
public:
	Job(const string& end,const string& make){
		endTime=Util::stoi(end);
		makeTime=Util::stoi(make);
	}
	int makeTime;
	int endTime;
};

#endif