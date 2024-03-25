#pragma once

#include "Library.h"
#include "Semester.h"

struct YearInfo
{
	int year;
};

struct YearNode
{
	int data;
	SemesterInfo* semester;

	YearNode() {
		semester = new SemesterInfo[3];
		semester[0].order = 1;
		semester[1].order = 2;
		semester[2].order = 3;
	}

	YearNode *pNext;

	~YearNode()
	{
		delete[] semester;
	}
};

//void createNewSchoolYear(YearNode *&Head, int &NumOfSchoolYear);

//void importSchoolYear(YearNode *&Head, ifstream &fin, int &numOfSchoolYear);
//void exportSchoolYear(YearNode *Head, ofstream &fout, int numOfSchoolYear);

//YearNode findSchoolYear(YearNode *yearHead, int data);