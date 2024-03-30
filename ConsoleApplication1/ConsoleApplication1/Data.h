#pragma once

#include"Year.h"

void exportData(YearNode *headYear, ofstream &fo);
void exportSemester(SemesterInfo curSem, int sem, ofstream &fo);
void exportCourse(CourseNode *curCourse, ofstream &fo);
void exportStudent(StudentNode *curStu, ofstream &fo);
void importSemester(SemesterInfo& curSem, int sem, ifstream& fi, string& type);
void importCourse(CourseNode*& curCourse, ifstream& fi, string& type);
void deAllocateDataYear(YearNode *headYear);
void deAllocateDataSemester(YearNode *headYear);
void deAllocateDataCourse(CourseNode *headCourse);
void deAllocateDataStudent(StudentNode *headStudent);
// void deAllocateViewingManagement()