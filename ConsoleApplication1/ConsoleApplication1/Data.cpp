#include "Data.h"

void deAllocateDataYear(YearNode*& headYear) {
	while (headYear != nullptr) {
		deAllocateDataSemester(headYear);
		YearNode *temp = headYear;
		headYear = headYear->pNext;
		delete temp;
	}
}

void deAllocateDataSemester(YearNode*& headYear) {
	YearNode *currentYear = headYear;
	for (int i = 0; i < 3; ++i)
		deAllocateDataCourse(currentYear->semester[i].course);
	delete []currentYear->semester;
}

void deAllocateDataCourse(CourseNode*& headCourse) {
	while (headCourse != nullptr) {
		deAllocateDataStudent(headCourse->student);
		CourseNode* temp = headCourse;
		headCourse = headCourse->pNext;
		delete temp;
	}
}

void deAllocateDataStudent(StudentNode*& head) {
	while (head) {
		StudentNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}

void deAlocatedClassesData(ClassNode*& head) {
	while (head) {
		deAllocateDataStudent(head->student);
		ClassNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}