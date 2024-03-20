#pragma once

void exportData(YearNode* headYear, ofstream& fo);
void exportSemester(SemesterInfo curSem, int sem, ofstream& fo);
void exportCourse(CourseNode* curCourse, ofstream& fo);
void exportStudent(StudentNode* curStu, ofstream& fo);