#include "Course.h"

/*void removeStudentFromCourse(CourseNode *head, string course_id, string student_id)
{
    CourseNode *currrentCourse = head;
    if (course_id == "")
    {
        viewListofCourse(head);
        cout << "Please choose a course!, example: CS162 (type in CS162)\n"
             << "Your choice: ";
        cin.get(course_id, 1000, '\n');
        cin.ignore();
    }
    while (currrentCourse != nullptr)
    {
        if (currrentCourse->data.ID == course_id)
        {
            viewListOfStudentInCourse(head, course_id);
            cout << "Please choose a student to remove that student from this course, example: 20125001 (type in 23125001)\n"
                 << "Your choice: ";
            cin.get(student_id, 1000, '\n');
            cin.ignore();
            StudentNode *currentStudent = currrentCourse->student, *previousCurrentStudent = nullptr;
            while (currentStudent != nullptr)
            {
                if (currentStudent->data.ID == student_id)
                {
                    previousCurrentStudent->pNext = currentStudent->pNext;
                    StudentNode *tempStudent = currentStudent;
                    currentStudent = currentStudent->pNext;
                    delete tempStudent;
                }
                else
                {
                    previousCurrentStudent = currentStudent;
                    currentStudent = currentStudent->pNext;
                }
            }
        }
        else
            currrentCourse = currrentCourse->pNext;
    }
}
*/
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
