#pragma once

#include "Semester.h"

struct ClassInfo
{
    string name;
};

struct ClassNode
{
    ClassInfo data;
    StudentNode* student;
    ClassNode* pNext;

    ClassNode() {
        student = nullptr;
        pNext = nullptr;
    }
    ClassNode(string s) {
        data.name = s;
        student = nullptr;
        pNext = nullptr;
    }
};

void importClassData(ClassNode*& classes, ClassNode* tail, ifstream& fin);

void exportClassData(ClassNode* classes, ofstream& fout);

string askClassName();

ClassNode* findClass(ClassNode* head, string name);

void viewScoreboardofClass(ClassNode*& head);
