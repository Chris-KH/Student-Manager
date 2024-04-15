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
    int No = 0;
    string ID = "";
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

void importStudentToClass(StudentNode*& head, ifstream& fin);

void exportStudent(StudentNode *head, ofstream &fout);

void createNewUsers(UserNode*& tailUser, StudentNode* head);

void updateAStudentResult(StudentNode* &head);