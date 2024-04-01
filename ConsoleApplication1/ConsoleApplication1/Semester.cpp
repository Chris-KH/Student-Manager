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

    cout << "Course ID: \n";
    cin >> curCourse->data.ID;

    cout << "Course name: \n";
    cin.ignore();
    getline(cin, curCourse->data.course_name);

    cout << "Class name: \n";
    cin.ignore();
    getline(cin, curCourse->data.class_name);

    cout << "Teacher name: \n";
    getline(cin, curCourse->data.teacher_name);

    cout << "Number of credits: \n";
    cin >> curCourse->data.credit;

    cout << "The maximum number of students in the course: \n";

    cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): \n";
    cin >> curCourse->data.day_of_week;

    cout << "Session: \n";
    cout << "1. S1(07:30)\n";
    cout << "2. S2(09:30)\n";
    cout << "3. S3(13:30)\n";
    cout << "4. S4(15:30)\n";
    cout << "Press a number (1-4) to choose: \n";
    cin >> curCourse->data.session;
}

CourseNode* findCourse(SemesterInfo* head) {
    string s;
    cout << "Input course ID: "; cin >> s;
    CourseNode* curCourse = head->course;
    while (curCourse) {
        if (curCourse->data.ID == s) return curCourse;
        curCourse = curCourse->pNext;
    }
    return nullptr;
}

void deleteACourse(SemesterInfo*& head) {
    CourseNode* curCourse = findCourse(head);
    if (curCourse == nullptr) {
        cout << "This course does not exist in this semester.\n";
        return;
    }
    CourseNode* headCourse = head->course;
    if (curCourse == headCourse) {
        CourseNode* temp = headCourse;
        head->course = head->course->pNext;
        cout << "Delete course successfully.\n";
        delete temp;
    }
    CourseNode* prev = headCourse;
    CourseNode* cur = headCourse->pNext;
    while (cur) {
        if (cur == curCourse) {
            CourseNode* temp = cur;
            prev->pNext = cur->pNext;
            delete temp;
            cout << "Delete course successfully.\n";
            return;
        }
        cur = cur->pNext;
    }
}