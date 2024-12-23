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
    StudentNode* student;
    CourseNode* pNext;

    CourseNode() {
        student = nullptr;
        pNext = nullptr;
    }
};



void removeStudentFromCourse(CourseNode*& head);

void viewListOfCourse(CourseNode* head);

void viewListOfStudentInCourse(CourseNode* head);

void viewTheScoreboardOfCourse(CourseNode* course);

StudentNode* findStudentInACourse(string s, CourseNode* curCourse);

void printCourseIn4(CourseNode* curCourse);

void viewStudentCourse(string student_id, CourseNode* head);

void viewStudentScoreboard(string student_id, CourseNode* head);

CourseNode* findCourse(CourseNode* head);

StudentNode* chooseStudentInACourse(CourseNode* curCourse);

