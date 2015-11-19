#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class FileReader{
public:
	FileReader(char []);
	~FileReader();
	int getLineNum();
	string getLine(int);
private:
	FILE *fp;
	vector<string> line;
};

#endif