#pragma once

#include "Library.h"
#include "Year.h"

struct ClassInfo
{
    string name = "";
};

struct ClassNode
{
    ClassInfo data;
    StudentInfo* student;
    ClassNode* pNext;

    ClassNode() {
        student = nullptr;
        pNext = nullptr;
    }
};

void addNewClass(ClassNode*& head, ClassNode*& curClass);


//void importClass(ClassNode*& head, ifstream& fin);
