#pragma once

#include "Library.h"
#include "Date.h"
#include "Student.h"
#include "Semester.h"
#include "Class.h"

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


    CourseInfo() : max_student{ 50 } {}
};

struct CourseNode
{
    CourseInfo data;
    StudentNode* student;
    CourseNode* pNext;

    CourseNode() : student(),pNext(nullptr) {}
    ~CourseNode()
    {
        delete pNext;
    }
};

void addCourse(SemesterInfo*& CurSemester, CourseNode*& Head);

void importScoreboard(ifstream& fin, CourseNode*& courses);

void viewTheScoreboardOfCourse(CourseNode* courses);

//void updateStudentResult(StudentNode *Student);

//void viewTheScoreboardOfClass(ClassNode* headClass, CourseNode* headCourse);

//StudentNode* findStudentABC(int id);

//void ViewStudentScoreBoard(StudentNode* Student);

//void viewStudentScoreboard(string student_id, CourseNode* courses);