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
    StudentNode* student;
    ClassNode* pNext;

    ClassNode() {
        pNext = nullptr;
    }
    ClassNode(string s) {
        data.name = s;
        pNext = nullptr;
    }
};


void importClassesData(ClassNode* &classes, ifstream &fin);
void exportClassesData(ClassNode* classes, ofstream& fout);
void addStudent2Class(ClassNode* classes, ifstream& fin);
ClassNode* findClass(ClassNode* head);
void addNewClass(ClassNode*& head, ClassNode*& curClass);
void deleteClasses(ClassNode* &head);


//void importClass(ClassNode*& head, ifstream& fin);
