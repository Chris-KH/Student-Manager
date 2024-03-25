#pragma once

#include "Library.h"
#include "Date.h"
#include "User.h"

struct Score
{
    double total = -1;
    double final = -1;
    double midterm = -1;
    double bonus = -1;
};

struct StudentInfo
{
    string No = "", ID = "";
    string first_name = "", last_name = "";
    Date dob;
    bool gender = 0; // 0 là nữ, 1 là nam
    string social_id = "";
    Score score;
};

struct StudentNode 
{
    StudentInfo data;
    StudentNode* pNext;
    
    StudentNode() : pNext(nullptr) {}
};

/*
void importStudentToCourse(CourseNode*& course, ifstream& fin);

void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year);

void viewListofCourse(CourseNode* course);

void updateCourseIn4(CourseNode* head, string course_id);

void addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student);

void removeStudentFromCourse(CourseNode* head, string course_id, string student_id);

void deleteACourse(CourseNode* head, string course_id);

void createNewStudentAccount(StudentNode students, UserNode*& head);

void viewListOfStudentInClass(StudentNode* head);//choose class 

void viewListOfStudentInCourse(StudentNode* head); //choose year -> semester -> course


*/