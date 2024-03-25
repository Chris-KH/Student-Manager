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

    ClassNode() : data(), pNext(nullptr), student(nullptr) {}
};

void addNewClass(ClassNode*& head, ClassNode*& curClass);


//void importClass(ClassNode*& head, ifstream& fin);
