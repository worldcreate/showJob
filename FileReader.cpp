#include "FileReader.h"

FileReader::FileReader(char filename[]){
	fp=fopen(filename,"r");

	char str[1024];
	while((fgets(str,256,fp))!=NULL){
		string s(str);
		line.push_back(s);
	}
}

FileReader::~FileReader(){
	fclose(fp);
}

int FileReader::getLineNum(){
	return line.size();
}

string FileReader::getLine(int n){
	return line[n];
}