#pragma once

#include "Library.h"
#include "Year.h"

struct ClassInfo
{
    string name;
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
    ClassNode(string s) {
        data.name = s;
        student = nullptr;
        pNext = nullptr;
    }
};


void importClassData(ClassNode* &classes, ifstream &fin);
void addNewClass(ClassNode*& head, ClassNode*& curClass);
void addStudentToClass(ClassNode* classes, ifstream& fin);
void deleteClass();


//void importClass(ClassNode*& head, ifstream& fin);
