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

ClassNode* findClass(ClassNode* head);

void deleteClasses(ClassNode*& head);



