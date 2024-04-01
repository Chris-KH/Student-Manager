#include "Data.h"


void exportData(YearNode *headYear, ofstream &fout)
{
	YearNode *curYear = headYear;
	while (curYear != NULL)
	{
		fout << "Year" << endl;
		fout << curYear->data << endl;
		SemesterInfo curSem = curYear->semester[0];

		curYear = curYear->pNext;
	}
}

void exportSemester(SemesterInfo curSem, int sem, ofstream &fout)
{
	fout << "Semester " << endl;
	fout << sem << endl;
	exportDate(curSem.start, fout);
	exportDate(curSem.end, fout);
	CourseNode *curCourse = curSem.course;
	while (curCourse != NULL)
	{
		exportCourse(curCourse, fout);
		curCourse = curCourse->pNext;
	}
}

void exportCourse(CourseNode *curCourse, ofstream &fout)
{
	fout << "Course" << endl;
	CourseInfo info = curCourse->data;
	fout << info.ID << endl;
	fout << info.course_name << endl;
	fout << info.class_name << endl;
	fout << info.teacher_name << endl;
	fout << info.credit << endl;
	fout << info.max_student << endl;
	fout << info.day_of_week << endl;
	fout << info.session << endl;
	StudentNode *curStu = curCourse->student;
	while (curStu != NULL)
	{
		exportStudent(curStu, fout);
		curStu = curStu->pNext;
	}
}

void exportStudent(StudentNode *curStu, ofstream &fo)
{
	fo << "Student" << endl;
	StudentInfo info = curStu->data;
	fo << info.No << endl;
	fo << info.ID << endl;
	fo << info.first_name << endl;
	fo << info.last_name << endl;
	exportDate(info.dob, fo);
	fo << info.gender << endl;
	fo << info.social_id << endl;
	ScoreInfo score = info.score;
	fo << score.total << " " << score.final << " " << score.midterm << " " << score.bonus << endl;
}

void importSemester(SemesterInfo &curSem, int sem, ifstream &fin, string &type)
{
	importDate(curSem.start, fin);
	importDate(curSem.end, fin);
	fin >> type;
	curSem.course = NULL;
	CourseNode *curCourse = NULL;
	while (type == "Course")
	{
		CourseNode *newCourse = new CourseNode;
		if (curCourse == NULL)
			curSem.course = newCourse;
		else
			curCourse->pNext = newCourse;
		curCourse = newCourse;
		importCourse(curCourse, fin, type);
	}
}

void importCourse(CourseNode *&curCourse, ifstream &fin, string &type)
{
	CourseInfo info = curCourse->data;
	fin >> info.ID;
	fin >> info.course_name;
	fin >> info.class_name;
	fin >> info.teacher_name;
	fin >> info.credit;
	fin >> info.max_student;
	fin >> info.day_of_week;
	fin >> info.session;
	fin >> type;
	curCourse->student = NULL;
	StudentNode *curStu = NULL;
	while (type == "Student")
	{
		StudentNode *newStu = new StudentNode;
		if (curStu == NULL)
			curCourse->student = newStu;
		else
			curStu->pNext = newStu;
		curStu = newStu;
		importStudentToClass(curStu, fin);
		fin >> type;
	}
}

void deAllocateDataYear(YearNode *headYear)
{
	YearNode *currentYear = headYear;
	while (currentYear != nullptr)
	{
		deAllocateDataSemester(currentYear);
		YearNode *temp = currentYear;
		currentYear = currentYear->pNext;
		delete temp;
	}
}

void deAllocateDataClass(ClassNode* headClass)
{
	ClassNode* currentClass = headClass;
	while (currentClass != nullptr)
	{
		deAllocateDataStudent(currentClass->student);
		ClassNode* temp = currentClass;
		currentClass = currentClass->pNext;
		delete temp;
	}
}

void deAllocateDataSemester(YearNode *headYear)
{
	YearNode *currentYear = headYear;
	for (int i = 0; i < 3; ++i)
		deAllocateDataCourse(currentYear->semester[i].course);
	delete []currentYear->semester;
}

void deAllocateDataCourse(CourseNode *headCourse)
{
	CourseNode *currentCourse = headCourse;
	while (currentCourse != nullptr)
	{
		deAllocateDataStudent(currentCourse->student);
		CourseNode *temp = currentCourse;
		currentCourse = currentCourse->pNext;
		delete temp;
	}
}
void deAllocateDataStudent(StudentNode *headStudent)
{
	StudentNode *currentStudent = headStudent;
	while (currentStudent != nullptr)
	{
		StudentNode *temp = currentStudent;
		currentStudent = currentStudent->pNext;
		delete temp;
	}
}
