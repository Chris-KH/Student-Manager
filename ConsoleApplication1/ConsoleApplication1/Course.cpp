﻿#include "Course.h"

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
        cout << ANSI_RED << "Haven't created any course in this semester" << endl;
        return nullptr;
    }
    CourseNode* cur = head;
    int cnt = 0;
    cout << "Choose course: " << endl;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << " - " << cur->data.class_name << "\n";
        cur = cur->pNext;
    }
    
    int order;
    cout << "Your choice (1->" << cnt << "): ";
    cin >> order;
    while (!(1<=order && order<=cnt))
    {
        cout << ANSI_RED << "Wrong input. Try again.\n" << ANSI_WHITE;
        cout << "Your choice (1->" << cnt << "): ";
        cin >> order;
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
            cout << ANSI_RED << "This course has no student.\n";
            return;
        }
        cout << "Students in course " << curCourse->data.course_name << " - " << curCourse->data.ID << " - " << curCourse->data.class_name << ":\n";
        int temp = 0;
        while (curStudent) {
            cout << "NO " << ++temp << "\n";
            cout << "Student ID: " << curStudent->data.ID << "\n";
            cout << "Student name: " << curStudent->data.last_name << " " << curStudent->data.first_name << "\n";
            cout << "Gender: " << curStudent->data.gender << "\n";
            cout << "DOB: " << curStudent->data.dob.day << "/" << curStudent->data.dob.month << "/" << curStudent->data.dob.year << "\n";
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
        cout << ANSI_RED << "This student is not in the course.\n";
        return;
    }
    StudentNode* headStudent = head->student;
    if (curStudent == head->student) {
        StudentNode* temp = curStudent;
        head->student = head->student->pNext;
        delete temp;
        cout << ANSI_GREEN << "Delete student successfully.\n";
        return;
    }
    StudentNode* prev = headStudent;
    StudentNode* cur = headStudent->pNext;
    while (cur) {
        if (cur == curStudent) {
            StudentNode* temp = cur;
            prev->pNext = cur->pNext;
            delete temp;
            cout << ANSI_GREEN << "Delete student successfully.\n";
            return;
        }
        prev = prev->pNext;
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

StudentNode* chooseStudentInACourse(CourseNode* curCourse)
{
    StudentNode* curStu = curCourse->student;
    int cnt = 0;
    cout << "List of student in the course " << endl;
    while (curStu != nullptr)
    {
        ++cnt;
        cout << cnt << ". " << curStu->data.ID << " - " << curStu->data.last_name <<" "<< curStu->data.first_name << endl;
        curStu = curStu->pNext;
    }

    cout << "Please choose a student to update his/her result" << endl;
    cout << "Your choice (1->" << cnt << "): ";
    int opt;
    cin >> opt;
    if (!(1<=opt && opt<=cnt))
    {
        cout << "Wrong option. Try again." << endl;
        cout << "Your choice (1->" << cnt << "): ";
        cin >> opt;
    }
    cnt = 0;
    curStu = curCourse->student;
    while (curStu != nullptr)
    {
        ++cnt;
        if (cnt == opt)
            return curStu;
        curStu = curStu->pNext;
    }
    return nullptr;
}
void  viewStudentCourse(string student_id, CourseNode* head) {
    int cnt = 0;
    CourseNode* curCourse = head;
    bool ok = true;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(student_id, curCourse);
        if (curStu != nullptr) {
            if (ok) {
                cout << ">>List of courses in this semester: \n";
                ok = false;
            }
            ++cnt;
            cout <<"    "<<cnt << ". " << curCourse->data.course_name << " - " << curCourse->data.ID << "\n";
        }
        curCourse = curCourse->pNext;
    }
    if (ok) cout << ANSI_RED << "No course in this semester.\n";
}

void  viewStudentScoreboard(string student_id, CourseNode* head)
{
    int cnt = 0;
    bool ok = true;
    CourseNode* curCourse = head;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(student_id, curCourse);
        if (curStu != nullptr)
        {
            if (ok)
            {
                cout << "The scoreboard of student ID " << student_id << ": " << endl;
                ok = false;
            }
            ++cnt;
            StudentNode* curStu = curCourse->student;
            cout << cnt<<". " << curCourse->data.course_name << " - " << curCourse->data.ID << endl;
            cout << "      *Total: " << curStu->data.score.total << endl;
            cout << "      *Final: " << curStu->data.score.final << endl;
            cout << "      *Midterm: " << curStu->data.score.midterm << endl;
            cout << "      *Bonus: " << curStu->data.score.bonus << endl;
        }
        curCourse = curCourse->pNext;
    }
    if (ok) cout << ANSI_RED << "No scoreboard in this semester.\n";
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

void viewTheScoreboardOfCourse(CourseNode* course)
{
    StudentNode* curStu = course->student;
    if (curStu != nullptr)
    {
        if (curStu->data.score.total == -1)
        {
            cout << "The scoreboard of the course has not been imported" << endl;
            return;
        }
    }
    cout << "Scoreboard of course " << course->data.course_name << " " << course->data.ID << endl;
    while (curStu != nullptr)
    {
        cout << curStu->data.No << ".";
        cout << "  >>Student name: " << curStu->data.last_name << " " << curStu->data.first_name << endl;
        cout << "    >>Student ID: " << curStu->data.ID << endl;
        cout << "    >>Score" << endl;
        cout << "       *Total: " << fixed << setprecision(1) << curStu->data.score.total << endl;
        cout << "       *Final: " << fixed << setprecision(1) << curStu->data.score.final << endl;
        cout << "       *Midterm: " << fixed << setprecision(1) << curStu->data.score.midterm << endl;
        cout << "       *Bonus: " << fixed << setprecision(1) << curStu->data.score.bonus << endl;
        curStu = curStu->pNext;
    }
}
