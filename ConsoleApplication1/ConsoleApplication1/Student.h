#pragma once

#include "User.h"

struct ScoreInfo
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
    string gender = ""; // 0 là nữ, 1 là nam
    string social_id = "";
    ScoreInfo score;
};

struct StudentNode
{
    StudentInfo data;
    StudentNode *pNext;

    StudentNode()
    {
        pNext = nullptr;
    }
};

void importStudentToClass(StudentNode *&head, ifstream &fin);

void exportStudentInClass(StudentNode *head, ofstream &fout);

/*
void importStudentToCourse(CourseNode*& course, ifstream& fin);

void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year);

void viewListofCourse(CourseNode* course);

void updateCourseIn4(CourseNode* head, string course_id);

void addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student);

void deleteACourse(CourseNode* head, string course_id);

void createNewStudentAccount(StudentNode students, UserNode*& head);

void viewListOfStudentInClass(StudentNode* head);//choose class

void viewListOfStudentInCourse(StudentNode* head); //choose year -> semester -> course


*/