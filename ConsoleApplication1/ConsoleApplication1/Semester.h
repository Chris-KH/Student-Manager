#pragma once

#include "Date.h"
#include "Course.h"

struct SemesterInfo
{
	int order;
	Date start;
	Date end;
	CourseNode* course;

	SemesterInfo() : course(nullptr) {};
};

void addCourse(SemesterInfo*& CurSemester, CourseNode*& Head);

