#pragma once

#include "Date.h"
#include "Course.h"

struct SemesterInfo
{
	int order;
	Date start;
	Date end;
	CourseNode* course;

	SemesterInfo() {
		order = 0;
		course = nullptr;
	}
};
//void createSemester(YearNode* year);
//void addCourse(SemesterInfo*& CurSemester, CourseNode*& Head);