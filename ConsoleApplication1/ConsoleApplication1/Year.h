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

void createASchoolYear(YearNode*& head, YearNode* tail);

void importSchoolYear(YearNode*& head, ifstream& fin);

void exportSchoolYear(YearNode* head, ofstream &fout);

YearNode findSchoolYear(YearNode *yearHead, int data);

void deleteSchoolYear(YearNode*& head);