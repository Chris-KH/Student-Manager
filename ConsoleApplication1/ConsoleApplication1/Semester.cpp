#include"Semester.h"

void addCourse(SemesterInfo* &curSes, CourseNode*& curCourse)
{
    CourseNode* newcourse = new CourseNode;
    if (curSes->course == nullptr)
    {
        curSes->course = newcourse;
        curCourse = newcourse;
    }
    else
    {
        curCourse->pNext = newcourse;
        curCourse = curCourse->pNext;
    }

	cout << "Course id: " << endl;
    cin >> curCourse->data.ID;
    
    cout << "Course name: " << endl;
    cin.ignore();
    getline(cin, curCourse->data.course_name);

    cout << "Class name: " << endl;
    cin.ignore();
    getline(cin, curCourse->data.class_name);

    cout << "Teacher name: " << endl;
    getline(cin, curCourse->data.teacher_name);
    
    cout << "Number of credits: " << endl;
    cin>>curCourse->data.credit;
    
    cout << "The maximum number of students in the course: " << endl;
    cin >> curCourse->data.max_student;
    
    cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): " << endl;
    cin >> curCourse->data.day_of_week;
    
    cout << "Session: " << endl;
    cout << "1. S1(07:30)" << endl;
    cout << "2. S2(09:30)" << endl;
    cout << "3. S3(13:30)" << endl;
    cout << "4. S4(15:30)" << endl;
    cout << "Press a number (1-4) to choose" << endl;
    cin >> curCourse->data.session;
}

