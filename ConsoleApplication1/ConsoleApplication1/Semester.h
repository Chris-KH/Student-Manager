#pragma once

#include "Course.h"

struct SemesterInfo {
	int order;
	bool created;
	Date start;
	Date end;
	CourseNode* course;
	SemesterInfo() {
		order = 0;
		created = false;
		course = nullptr;
	}
};  

void addCourse(SemesterInfo* &curSes, CourseNode*& curCourse);

CourseNode* findCourse(SemesterInfo* head);