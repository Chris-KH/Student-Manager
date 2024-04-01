#include "Course.h"

void viewListOfCourse(CourseNode *head)
{
    CourseNode *cur = head;
    int cnt = 0;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << endl;
        cur = cur->pNext;
    }
}
void viewListOfStudentInCourse(CourseNode *head, string course_id)
{
    CourseNode *currrentCourse = head;
    if (course_id == "")
    {
        viewListOfCourse(head);
        cout << "Please choose a course!, example: CS162 (type in CS162)\n"
             << "Your choice: ";
        getline(cin, course_id);
        cin.ignore();
    }
    while (currrentCourse != nullptr)
    {
        if (currrentCourse->data.ID == course_id)
        {
            StudentNode *currentStudent = currrentCourse->student;
            while (currentStudent != nullptr)
            {
                cout << currentStudent->data.ID << " " << currentStudent->data.first_name << " " << currentStudent->data.last_name << "\n";
                currentStudent = currentStudent->pNext;
            }
        }
        else
            currrentCourse = currrentCourse->pNext;
    }
}
void removeStudentFromCourse(CourseNode *head, string course_id, string student_id)
{
    CourseNode *currrentCourse = head;
    if (course_id == "")
    {
        viewListOfCourse(head);
        cout << "Please choose a course!, example: CS162 (type in CS162)\n"
             << "Your choice: ";
        getline(cin, course_id);
        cin.ignore();
    }
    while (currrentCourse != nullptr)
    {
        if (currrentCourse->data.ID == course_id)
        {
            viewListOfStudentInCourse(head, course_id);
            cout << "Please choose a student to remove that student from this course, example: 20125001 (type in 23125001)\n"
                 << "Your choice: ";
            getline(cin, student_id);
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
