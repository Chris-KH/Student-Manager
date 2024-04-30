#include "Course.h"

void viewListOfCourse(CourseNode* head)
{
    CourseNode* cur = head;
    int cnt = 0;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << " - " << cur->data.class_name << "\n";
        cur = cur->pNext;
    }
}

CourseNode* findCourse(CourseNode *head) {
    if (head == nullptr)
    {
        cout << "Haven't created any course in this semester" << endl;
        return nullptr;
    }
    CourseNode* cur = head;
    int cnt = 0;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << " - " << cur->data.class_name << "\n";
        cur = cur->pNext;
    }
    
    int order;
    cout << "Please choose a number (1->" << cnt << ") corresponding to the course : ";
    cin >> order;
    if (order > cnt)
    {
        cout << "Wrong input.\n";
        return nullptr;
    }
    CourseNode* curCourse = head;
    cnt = 0;
    while (curCourse)
    {
        ++cnt;
        if (cnt == order)
            return curCourse;
        curCourse = curCourse->pNext;
    }
    return nullptr;
}

void viewListOfStudentInCourse(CourseNode* head) {
    CourseNode* curCourse = findCourse(head);
    if (curCourse)
    {
        StudentNode* curStudent = curCourse->student;
        if (!curStudent) {
            cout << "This course has no student.\n";
            return;
        }
        cout << "Students in course " << curCourse->data.course_name << " - " << curCourse->data.ID << " - " << curCourse->data.class_name << ":\n";
        int temp = 0;
        while (curStudent) {
            cout << "NO " << ++temp << "\n";
            cout << "Student ID: " << curStudent->data.ID << "\n";
            cout << "Student name: " << curStudent->data.last_name << " " << curStudent->data.first_name << "\n";
            cout << "----------------------------------------\n";
            curStudent = curStudent->pNext;
        }
        return;
    }
}

void removeStudentFromCourse(CourseNode*& head) {
    string s;
    cout << "Input student ID: ";
    cin >> s;
    StudentNode* curStudent = findStudentInACourse(s, head);
    if (curStudent == nullptr) {
        cout << "This student is not in the course.\n";
        return;
    }
    StudentNode* headStudent = head->student;
    if (curStudent == head->student) {
        StudentNode* temp = curStudent;
        head->student = head->student->pNext;
        delete temp;
        cout << "Delete student successfully.\n";
        return;
    }
    StudentNode* prev = headStudent;
    StudentNode* cur = headStudent->pNext;
    while (cur) {
        if (cur == curStudent) {
            StudentNode* temp = cur;
            prev->pNext = cur->pNext;
            delete temp;
            cout << "Delete student successfully.\n";
            return;
        }
        cur = cur->pNext;
    }
}


StudentNode* findStudentInACourse(string s, CourseNode* curCourse) 
{
    StudentNode* curStu = curCourse->student;
    while (curStu != nullptr)
    {
        if (curStu->data.ID == s)
            return curStu;
        curStu = curStu->pNext;
    }
    return nullptr;
}

void  viewStudentCourse(string student_id, CourseNode* head) {
    CourseNode* curCourse = head;
    bool ok = true;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(student_id, curCourse);
        if (curStu != nullptr) {
            if (ok) {
                cout << "List of courses in this semester: \n";
                ok = false;
            }
            cout << curCourse->data.course_name << " - " << curCourse->data.ID << "\n";
        }
        curCourse = curCourse->pNext;
    }
    if (ok) cout << "No course in this semester.\n";
}

void  viewStudentScoreboard(string student_id, CourseNode* head)
{
    cout << "The scoreboard of student ID " << student_id <<": "<< endl;
    CourseNode* curCourse = head;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(student_id, curCourse);
        if (curStu != nullptr)
        {
            StudentNode* curStu = curCourse->student;
            cout << "Course " << curCourse->data.course_name << " - " << curCourse->data.ID << endl;
            cout << "Total: " << curStu->data.score.total << endl;
            cout << "Final: " << curStu->data.score.final << endl;
            cout << "Midterm: " << curStu->data.score.midterm << endl;
            cout << "Bonus: " << curStu->data.score.bonus << endl;
        }
        curCourse = curCourse->pNext;
    }
}

void printCourseIn4(CourseNode* curCourse)
{
    cout << "Course ID : ";
    cout << curCourse->data.ID;
    cout << endl;

    cout << "Course name: ";
    cout << curCourse->data.course_name;
    cout << endl;

    cout << "Class name: ";
    cout << curCourse->data.class_name;
    cout << endl;

    cout << "Teacher name: ";
    cout << curCourse->data.teacher_name;
    cout << endl;

    cout << "Number of credits: ";
    cout << curCourse->data.credit;
    cout << endl;

    cout << "The maximum number of students in the course: ";
    cout << curCourse->data.max_student;
    cout << endl;

    cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): ";
    cout << curCourse->data.day_of_week;
    cout << endl;

    cout << "Session: ";
    switch (curCourse->data.session)
    {
    case 1:
        cout << "S1(07:30)\n";
        break;
    case 2:
        cout << "S2(09:30)\n";
        break;
    case 3:
        cout << "S3(13:30)\n";
        break;
    case 4:
        cout << "S4(15:30)\n";
        break;
    }
}
void updateCourseIn4(CourseNode*& curCourse) {

    cout << ">>Current information" << endl;
    printCourseIn4(curCourse);

    cout << ">>Updating information of the course '" << curCourse->data.course_name << " - " << curCourse->data.ID << " " << curCourse->data.class_name << "'" << endl;

    cout << "Course ID : ";
    cin.ignore();
    getline(cin, curCourse->data.ID);

    cout << "Course name: ";
    cin.ignore();
    getline(cin, curCourse->data.course_name);

    cout << "Class name: ";
    getline(cin, curCourse->data.class_name);

    cout << "Teacher name: ";
    getline(cin, curCourse->data.teacher_name);

    cout << "Number of credits: ";
    cin >> curCourse->data.credit;

    cout << "The maximum number of students in the course: ";
    cin >> curCourse->data.max_student;

    cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): ";
    cin >> curCourse->data.day_of_week;

    cout << "Session: \n";
    cout << "1. S1(07:30)\n";
    cout << "2. S2(09:30)\n";
    cout << "3. S3(13:30)\n";
    cout << "4. S4(15:30)\n";
    cout << "Press a number (1-4) to choose: ";
    cin >> curCourse->data.session;
    cout << "Course infomation is updated successfully";
}

void viewTheScoreboardOfCourse(CourseNode* course)
{
    
    cout << "Scoreboard of course " << course->data.course_name << " " << course->data.ID << endl;
    StudentNode* curStu = course->student;
    while (curStu != nullptr)
    {
        cout << curStu->data.No << endl;
        cout << "Student name: " << curStu->data.first_name << " " << curStu->data.last_name << endl;
        cout << "Student ID: " << curStu->data.ID << endl;
        if (curStu->data.score.total == -1)
        {
            cout << "Still not imported" << endl;
        }
        else
        {
            cout << "Score" << endl;
            cout << "    Total: " << fixed << setprecision(1) << curStu->data.score.total << endl;
            cout << "    Final: " << fixed << setprecision(1) << curStu->data.score.final << endl;
            cout << "    Midterm: " << fixed << setprecision(1) << curStu->data.score.midterm << endl;
            cout << "    Bonus: " << fixed << setprecision(1) << curStu->data.score.bonus << endl;
        }
        curStu = curStu->pNext;
    }
}
