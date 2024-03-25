#pragma once

#include "Library.h"
#include "Semester.h"

struct YearNode
{
	string data;
	SemesterInfo* semester;

	YearNode* pNext;
	YearNode() {
		data = "";
		pNext = nullptr;
		semester = new SemesterInfo[3];
	}
};

void createASchoolYear(YearNode*& Head, int& NumOfSchoolYear);

//void importSchoolYear(YearNode *&Head, ifstream &fin, int &numOfSchoolYear);

//void exportSchoolYear(YearNode *Head, ofstream &fout, int numOfSchoolYear);

//YearNode findSchoolYear(YearNode *yearHead, int data);