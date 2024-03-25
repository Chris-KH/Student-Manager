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

void createNewSchoolYear(YearNode*& Head, int& NumOfSchoolYear);

void createASchoolYear(YearNode*& head, YearNode* tail);

void importSchoolYear(YearNode*& Head, ifstream& fin);

void exportSchoolYear(YearNode *Head, ofstream &fout, int numOfSchoolYear);

YearNode findSchoolYear(YearNode *yearHead, int data);