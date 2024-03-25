#pragma once

#include "Library.h"
#include "Date.h"
#include "Student.h"

struct CourseInfo
{
    string course_id;
    string course_name;
    string class_name;
    string teacher_name;
    int num_of_credit;
    int max_student;
    string day_of_week;
    int session;


    CourseInfo() {
        course_id = "";
        course_name = "";
        class_name = "";
        teacher_name = "";
        num_of_credit = 4;
        max_student = 50;
        day_of_week = "";
        session = 0;
    }
};

struct CourseNode
{
    CourseInfo data;
    StudentNode* student;
    CourseNode* pNext;

    CourseNode() : student(nullptr),pNext(nullptr) {}
};


void importScoreboard(ifstream& fin, CourseNode*& courses);

void viewTheScoreboardOfCourse(CourseNode* courses);

//void updateStudentResult(StudentNode *Student);

//void viewTheScoreboardOfClass(ClassNode* headClass, CourseNode* headCourse);

//StudentNode* findStudentABC(int id);

//void ViewStudentScoreBoard(StudentNode* Student);

//void viewStudentScoreboard(string student_id, CourseNode* courses);

/*
void importStudentToCourse(CourseNode*& course, ifstream& fin);

void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year);

void viewListofCourse(CourseNode* course);

void updateCourseIn4(CourseNode* head, string course_id);

void addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student);

void removeStudentFromCourse(CourseNode* head, string course_id, string student_id);

void deleteACourse(CourseNode* head, string course_id);

void viewListOfCourse(CourseNode* head); //choose year -> semester

void exportStudentOfCourse(CourseInfo course, ofstream& fout); //choose year -> semester -> course

void deleteAllCourse(CourseNode*& head);

void viewListOfStudentInCourse(CourseNode* head, string course_id);

void ExportListOfStudentInCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name);

void ExportScoreboard(ofstream& fout, CourseNode* head, string course_id, string sy_name);

void ViewTheScoreboardOfCourse(CourseNode* head, string course_id);

void updateStudentResult(string student_id, string course_id, CourseNode* head);

void viewStudentCourse(string student_id, CourseNode* head);

void viewStudentScoreboard(string student_id, CourseNode* head);
*/