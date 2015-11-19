#ifndef _COLOR_H_
#define _COLOR_H_

#include <windows.h>
#include <vector>

using namespace std;

class Color{
public:
	Color();
	vector<int> getColor(int);
	int length;
private:
	vector<vector<int> > color;
};

#endif