#pragma once

#include "Library.h"
#include "User.h"
#include "Course.h"
#include "Date.h"

struct ScoreInfo 
{
    double total, final, midterm, other;

    ScoreInfo() : total(-1), final(-1), midterm(-1), other(-1) {}
};

struct StudentInfo
{
    string No, ID;
    string first_name, last_name;
    Date dob;
    bool gender;
    string social_id;
    ScoreInfo score;
};

struct StudentNode 
{
    StudentInfo data;
    StudentNode* pNext;
    
    StudentNode() : pNext(nullptr) {}
};

void importStudentToCourse(CourseNode*& course, ifstream& fin);

void importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year);

void viewListofCourse(CourseNode* course);

void updateCourseIn4(CourseNode* head, string course_id);

void addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student);

void removeStudentFromCourse(CourseNode* head, string course_id, string student_id);

void deleteACourse(CourseNode* head, string course_id);

void createNewStudentAccount(StudentNode students, UserNode*& head);

void viewStudentCourse(string student_id, CourseNode* head);

//void viewListOfClass(ClassNode* head); //all classes

void viewListOfStudentInClass(StudentNode* head);//choose class 

void viewListOfCourse(CourseNode* head); //choose year -> semester

void viewListOfStudentInCourse(StudentNode* head); //choose year -> semester -> course

void viewStudentScoreboard(string student_id, CourseNode* head);

void exportStudentOfCourse(CourseInfo course, ofstream& fout); //choose year -> semester -> course



void deleteAllCourse(CourseNode*& head);


void viewListOfStudentInCourse(CourseNode* head, string course_id);

void ExportListOfStudentInCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name);


void ExportScoreboard(ofstream& fout, CourseNode* head, string course_id, string sy_name);

void ViewTheScoreboardOfCourse(CourseNode* head, string course_id);

void updateStudentResult(string student_id, string course_id, CourseNode* head);


