#pragma once

#include "Library.h"
#include "Student.h"

struct ClassInfo
{
    string name;
};

struct ClassNode
{
    ClassInfo data;
    StudentInfo* student;
    ClassNode* pNext;

    ClassNode() : data(), pNext(nullptr) {}
    ~ClassNode()
    {
        delete pNext;
    }
};

void addNewClass(ClassNode*& head);

void importClass(ClassNode*& head, ifstream& fin);
