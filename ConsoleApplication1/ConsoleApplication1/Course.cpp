#include "Course.h"

void viewListOfCourse(CourseNode* head)
{
    CourseNode* cur = head;
    int cnt = 0;
    cout << "List of courses: " << endl;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << " - " << cur->data.class_name << "\n";
        cur = cur->pNext;
    }
}

void viewListOfStudentInCourse(CourseNode* head) {
    string course_id;
    CourseNode* curCourse = head;
    viewListOfCourse(head);
    int order;
    cout << "Please choose a number corresponding to the course: ";
    cin >> order;

    int cnt = 0;
    while (curCourse)
    {
        ++cnt;
        if (cnt == order)
        {
            StudentNode* curStudent = curCourse->student;
            if (!curStudent)
            {
                cout << "This course has no student.\n";
                return;
            }
            cout << "Students in course: " << curCourse->data.course_name << " - " << curCourse->data.ID << " - " << curCourse->data.class_name << ":\n";
            int cnt = 0;
            while (curStudent)
            {
                cout << ++cnt << " " << curStudent->data.ID << " " << curStudent->data.first_name << " " << curStudent->data.last_name << "\n";
                curStudent = curStudent->pNext;
            }
            return;
        }
        curCourse = curCourse->pNext;
    }
    if (order > cnt)
        cout << "This semester does not have this course.\n";
}

void removeStudentFromCourse(CourseNode*& head) {
    string s;
    cout << "Input student ID: " << endl;
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

void  viewStudentCourse(string student_id, CourseNode* head)
{
    cout << "List of courses in this semester: " << endl;
    CourseNode* curCourse = head;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(student_id, curCourse);
        if (curStu != nullptr)
            cout << curCourse->data.course_name << " - " << curCourse->data.ID << endl;
        curCourse = curCourse->pNext;
    }

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

void updateCourseIn4(CourseNode*& curCourse) {
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

void addStudentToCourse(CourseNode*& curCourse)
{
    StudentNode* newStu = new StudentNode;

    cout << "Please input student information" << endl;
    cout << "Student ID: ";
    getline(cin, newStu->data.ID);

    cout << "Last name: ";
    getline(cin, newStu->data.last_name);

    cout << "First name: ";
    getline(cin, newStu->data.first_name);

    cout << "Gender: ";
    getline(cin, newStu->data.gender);

    cout << "DOB: ";
    string dob;
    getline(cin, dob);
    stringstream ss(dob);
    getline(ss, newStu->data.dob.day, '/');
    getline(ss, newStu->data.dob.month, '/');
    getline(ss, newStu->data.dob.year, ',');

    cout << "Social ID: ";
    getline(cin, newStu->data.social_id);

    StudentNode* curStu = curCourse->student;
    if (curStu == nullptr)
    {
        curStu = newStu;
        newStu->data.No = 1;
    }
    else {

        while (curStu->pNext != nullptr)
            curStu = curStu->pNext;
        newStu->data.No = curStu->data.No + 1;
        curStu->pNext = newStu;
    }
}

void viewTheScoreboardOfCourse(CourseNode* course)
//mặc định đã biết course nào
{
    StudentNode* curStu = course->student;
    while (curStu != nullptr)
    {
        cout << curStu->data.No;
        cout << "Student name: " << curStu->data.first_name << " " << curStu->data.last_name << endl;
        cout << "Student ID: " << curStu->data.ID << endl;
        cout << "Score" << endl;
        cout << "    Total: " << curStu->data.score.total << endl;
        cout << "    Final: " << curStu->data.score.final << endl;
        cout << "    Midterm: " << curStu->data.score.midterm << endl;
        cout << "    Bonus: " << curStu->data.score.bonus << endl;

        curStu = curStu->pNext;
    }
}

/*
void exportListofStudentinCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name)
{
    CourseNode *curCourse = head;
    while (curCourse)
    {
        if(curCourse->data.ID == course_id && curCourse->data.course_name == sy_name)
        {
            fout << curCourse->student->data.dob << ",";
            fout << curCourse->student->data.first_name<< ",";
            fout << curCourse->student->data.gender << ",";
            fout << curCourse->student->data.ID << ",";
            fout << curCourse->student->data.last_name << ",";
            fout << curCourse->student->data.score << ",";
            fout << curCourse->student->data.social_id << "\n";
        }
        curCourse = curCourse->pNext;
    }
}


void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year)
{
    CourseNode *curCourse = head;
    while (curCourse != nullptr)
    {
        if(!semester || !year)
        {
            cout << "Error! Please make sure to choose the right data\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            importScoreboard(fin, head, semester, year);
        }
        else
        {
            fin >> curCourse->student->data.score;
            curCourse = curCourse->pNext;
        }
    }
}

*/