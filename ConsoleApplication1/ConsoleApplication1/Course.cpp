#include "Course.h"

void viewListOfCourse(CourseNode* head)
{
	CourseNode* cur = head;
	int cnt = 0;
	while (cur != nullptr)
	{
		cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << endl;
		cur = cur->pNext;
	}
}