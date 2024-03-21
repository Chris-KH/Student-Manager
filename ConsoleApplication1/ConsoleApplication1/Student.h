#pragma once

#include "Library.h"
#include "Date.h"
#include "User.h"

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

void createNewStudentAccount(StudentNode students, UserNode*& head);

void viewListOfStudentInClass(StudentNode* head);//choose class 

void viewListOfStudentInCourse(StudentNode* head); //choose year -> semester -> course


