#include "Color.h"
#include "FileReader.h"
#include "Util.h"
#include <iostream>
#include <string>

Color::Color(){
	FileReader fr("color");
	color.resize(fr.getLineNum());
	for(int i=0;i<color.size();i++){
		color[i].resize(3);
	}
	for(int i=0;i<fr.getLineNum();i++){
		string str=fr.getLine(i);
		vector<string> param=Util::split(str,',');
		for(int j=0;j<param.size();j++){
			int a=Util::stoi(param[j]);
			color[i][j]=a;
		}
	}
	length=fr.getLineNum();
}

vector<int> Color::getColor(int n){
	return color[n];
}