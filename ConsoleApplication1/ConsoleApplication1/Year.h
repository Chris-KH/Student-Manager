#pragma once

#include "Class.h"

struct YearNode
{
	string data;
	SemesterInfo* semester;
	ClassNode* classes;
	YearNode* pNext;
	YearNode(string s) {
		data = s;
		pNext = nullptr;
		classes = nullptr;
		semester = new SemesterInfo[3]();
	}
	YearNode() {
		pNext = nullptr;
		classes = nullptr;
		semester = new SemesterInfo[3]();
	}
};

void createASchoolYear(YearNode*& head, YearNode* tail);

void importSchoolYearData(YearNode*& head, ifstream& fin);

void exportSchoolYearData(YearNode* head, ofstream &fout);

void addNewClass(YearNode*& head);

YearNode* findSchoolYear(YearNode *head);

void viewAListOfClasses(YearNode* head);

void createSemester(YearNode* head);

void deleteSemester(YearNode* head);

void deleteSchoolYear(YearNode*& head);