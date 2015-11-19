#include "JobTable.h"
#include "Util.h"
#include <sstream>
#include <iostream>

int JobTable::jobHeight=20;

JobTable::JobTable():maxTime(-1){
	color=new Color();
}

JobTable::~JobTable(){
	delete(color);
}

void JobTable::addMachine(char line[]){
	string str(line);
	vector<string> job=Util::split(str,' ');
	vector<Job> machine;

	for(int i=1;i<job.size();i++){
		if(job[i]=="")
			continue;
		vector<string> param=Util::split(job[i],',');
		machine.push_back(Job(param[0],param[1]));
	}
	table.push_back(machine);
}

int JobTable::getMaxTime(){
	if(maxTime!=-1)
		return maxTime;
	for(int i=0;i<table.size();i++){
		for(int j=0;j<table[i].size();j++){
			if(maxTime<table[i][j].endTime){
				maxTime=table[i][j].endTime;
			}
		}
	}
	return maxTime;
}

void JobTable::draw(HDC hDC){
	HPEN* Pens=new HPEN[table.size()];
	for(int i=0;i<table[0].size();i++){
		vector<int> col=color->getColor(i);
		Pens[i]=(HPEN)CreatePen(PS_SOLID,1,RGB(col[0],col[1],col[2]));
	}
	HPEN hOldPen=(HPEN)SelectObject(hDC,Pens[0]);
	for(int i=0;i<table.size();i++){
		for(int j=0;j<table[i].size();j++){
			SelectObject(hDC,Pens[j]);
			Rectangle(
				hDC,
				table[i][j].endTime-table[i][j].makeTime,
				i*jobHeight,
				table[i][j].endTime,
				i*jobHeight+jobHeight
			);
		}
	}
	for(int i=0;i<table[0].size();i++){
		DeleteObject(Pens[i]);
	}
	delete Pens;
	SelectObject(hDC,hOldPen);
}