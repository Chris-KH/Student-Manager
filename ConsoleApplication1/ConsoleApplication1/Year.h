#pragma once

#include "Library.h"
#include "Semester.h"

struct YearNode
{
	string data;
	SemesterInfo* semester;

	YearNode* pNext;
	YearNode(string s) {
		data = s;
		pNext = nullptr;
		semester = new SemesterInfo[3];
	}
	YearNode() {
		pNext = nullptr;
		semester = new SemesterInfo[3];
	}
};

void createASchoolYear(YearNode*& head, YearNode* tail);

void importSchoolYearData(YearNode*& head, ifstream& fin);

void exportSchoolYearData(YearNode* head, ofstream &fout);

YearNode findSchoolYear(YearNode *yearHead, int data);

void deleteSchoolYear(YearNode*& head);