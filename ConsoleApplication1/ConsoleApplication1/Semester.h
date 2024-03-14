#pragma once

#include "Library.h"
#include "Date.h"
#include "Course.h"
#include "Year.h"

struct SemesterInfo
{
	int order;
	Date start;
	Date end;
	CourseNode* course;

	SemesterInfo() : course{ nullptr } {}
};

void ImportCourseToSemester(YearNode*& Head, int sem, ifstream& fin);
void ExportCourseOfSemester(YearNode*& Head, int sem, ofstream& fout);
