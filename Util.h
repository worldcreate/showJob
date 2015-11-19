#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Util{
public:
	static vector<string> split(const string&,char);
	static int stoi(const string&);
};

#endif