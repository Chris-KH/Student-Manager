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

<<<<<<< HEAD
void createNewSchoolYear(YearNode*& Head, int& NumOfSchoolYear);
=======
void createASchoolYear(YearNode*& Head, int& NumOfSchoolYear);

//void importSchoolYear(YearNode *&Head, ifstream &fin, int &numOfSchoolYear);

>>>>>>> cb893d0b9afa11c19c79bf9f0a7b15fa9633cada
//void exportSchoolYear(YearNode *Head, ofstream &fout, int numOfSchoolYear);
//YearNode findSchoolYear(YearNode *yearHead, int data);