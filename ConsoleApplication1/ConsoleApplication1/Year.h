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

void importCourseToSemester(YearNode* head, ifstream& fin, bool& ok2);

void exportCourseToSemester(YearNode* head, SemesterInfo*& curSes, ofstream& fout);

void importSchoolYearData(YearNode*& head, YearNode*& tail, ifstream& fin);

void exportSchoolYearData(YearNode* head, ofstream &fout);

void createASchoolYear(YearNode*& head, YearNode*& tail);

void addNewClass(YearNode*& head, ofstream& fout);

YearNode* findSchoolYear(YearNode *head);

void addNewStudentToClass(UserNode *&tailUser, YearNode* head, ifstream& fin);

void viewListOfStudentInClass(YearNode* head);

void viewAListOfClasses(YearNode* head);

void viewAllClasses(YearNode* head);

SemesterInfo* createSemester(YearNode* head);

SemesterInfo* chooseASemester(YearNode* head, YearNode*& temp);

void addCourse(YearNode* curYear, SemesterInfo*& curSes, ofstream& fout);

void deleteACourse(YearNode* head, SemesterInfo*& curSes, ofstream& fout);