#pragma once

#include "Library.h"
#include "Semester.h"

struct YearNode
{
	int data;
	SemesterInfo* semester;

	YearNode* pNext;
	YearNode() {
		data = 0;
		pNext = nullptr;
		semester[0].order = 1;
		semester[1].order = 2;
		semester[2].order = 3;
	}
};

void createNewSchoolYear(YearNode *&Head, int &NumOfSchoolYear);

//void importSchoolYear(YearNode *&Head, ifstream &fin, int &numOfSchoolYear);
//void exportSchoolYear(YearNode *Head, ofstream &fout, int numOfSchoolYear);

//YearNode findSchoolYear(YearNode *yearHead, int data);