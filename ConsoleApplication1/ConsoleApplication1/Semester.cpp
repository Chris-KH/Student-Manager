#include"Semester.h"

/*CourseNode* findCourse(SemesterInfo* head) {
    string s;
    cout << "Input course ID: "; cin >> s;
    CourseNode* curCourse = head->course;
    while (curCourse) {
        if (curCourse->data.ID == s) return curCourse;
        curCourse = curCourse->pNext;
    }
    return nullptr;
}*/


void deleteACourse(SemesterInfo*& head) {
    CourseNode* curCourse = findCourse(head->course);
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

