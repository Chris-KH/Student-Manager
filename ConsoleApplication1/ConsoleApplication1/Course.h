#pragma once

#include "Student.h"

struct CourseInfo
{
    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int credit;
    int max_student;
    string day_of_week;
    int session;

    CourseInfo()
    {
        ID = "";
        course_name = "";
        class_name = "";
        teacher_name = "";
        credit = 4;
        max_student = 50;
        day_of_week = "";
        session = 0;
    }
};

struct CourseNode
{
    CourseInfo data;
    StudentNode *student;
    CourseNode *pNext;

    CourseNode() {
        student = nullptr;
        pNext = nullptr;
    }
};

void importScoreboard(ifstream &fin, CourseNode *&courses);

void viewTheScoreboardOfCourse(CourseNode *courses);

void removeStudentFromCourse(CourseNode *head, string course_id, string student_id);

void viewListOfCourse(CourseNode* head);

void viewListOfStudentInCourse(CourseNode* head, string course_id);

StudentNode* findStudentInACourse(string student_id, CourseNode* curCourse);
//choose year -> semester

void updateCourseIn4(CourseNode* head, string course_id);

// void updateStudentResult(StudentNode *Student);

// void viewTheScoreboardOfClass(ClassNode* headClass, CourseNode* headCourse);

// StudentNode* findStudentABC(int id);

// void ViewStudentScoreBoard(StudentNode* Student);

// void viewStudentScoreboard(string student_id, CourseNode* courses);

// void removeStudentFromCourse(CourseNode* head, string course_id, string student_id);

/*
void importStudentToCourse(CourseNode*& course, ifstream& fin);

void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year);

void viewListofCourse(CourseNode* course);

void addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student);

void deleteACourse(CourseNode* head, string course_id);

void exportStudentOfCourse(CourseInfo course, ofstream& fout); //choose year -> semester -> course

void deleteAllCourse(CourseNode*& head);

void ExportListOfStudentInCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name);

void ExportScoreboard(ofstream& fout, CourseNode* head, string course_id, string sy_name);

void ViewTheScoreboardOfCourse(CourseNode* head, string course_id);

void updateStudentResult(string student_id, string course_id, CourseNode* head);

void viewStudentCourse(string student_id, CourseNode* head);

void viewStudentScoreboard(string student_id, CourseNode* head);
*/