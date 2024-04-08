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

void deleteACourse(SemesterInfo*& head);

CourseNode* findCourse(SemesterInfo* head);

