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


void importClassData(ClassNode* &classes, ifstream &fin);

void exportClassData(ClassNode* classes, ofstream& fout);

void addStudent2Class(ClassNode* classes, ifstream& fin);

ClassNode* findClass(ClassNode* head);

void deleteClasses(ClassNode*& head);

void viewAListOfClasses(ClassNode* head);

void viewListOfStudentInClass(ClassNode* head);

