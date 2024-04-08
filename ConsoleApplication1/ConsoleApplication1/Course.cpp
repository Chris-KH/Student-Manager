#include "Course.h"

void viewListOfCourse(CourseNode *head)
{
    CourseNode *cur = head;
    int cnt = 0;
    while (cur != nullptr)
    {
        cout << ++cnt << ". " << cur->data.course_name << " - " << cur->data.ID << " - " << cur->data.class_name << "\n";
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

void removeStudentFromCourse(CourseNode*& head) {
    StudentNode* curStudent = findStudentInACourse(head);
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

StudentNode* findStudentInACourse(CourseNode* curCourse) {
    string s;
    cout << "Input student ID: "; cin >> s;
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
//giả sử đã biết được semester -> biết headCourse. Cách để chọn semester như thế nào sẽ code sau 
{
    cout << "List of courses " << endl;
    CourseNode* curCourse = head;
    while (curCourse != nullptr)
    {
        StudentNode* curStu = findStudentInACourse(curCourse);
        if (curStu != nullptr)
            cout << curCourse->data.course_name << " - " << curCourse->data.ID << endl;
        curCourse = curCourse->pNext;
    }

}

void  viewStudentScoreboard(string student_id, CourseNode* head)
//giả sử đã biết được semester -> biết headCourse. Cách để chọn semester như thế nào sẽ code sau 
{
    cout << "The scoreboard of student ID " << student_id << endl;
    CourseNode* curCourse = head;
    while (curCourse != nullptr)
    {
        StudentNode *curStu = findStudentInACourse(curCourse);
        if (curStu!=nullptr)
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

void addStudentToCourse(CourseNode* &curCourse)
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

void exportListofStudentinCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name)
{
    CourseNode *curCourse = head;
    while (fout)
    {
        if(curCourse->data.ID == course_id && curCourse->data.course_name == sy_name) cout << curCourse->student;
        curCourse = curCourse->pNext;
    }
}