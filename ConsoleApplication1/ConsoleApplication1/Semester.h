#pragma once

#include "Course.h"

struct SemesterInfo {
	bool created;
	Date start;
	Date end;
	CourseNode* course;
	SemesterInfo() {
		created = false;
		course = nullptr;
	}
};  

void addCourse(SemesterInfo* curSes, CourseNode*& curCourse);