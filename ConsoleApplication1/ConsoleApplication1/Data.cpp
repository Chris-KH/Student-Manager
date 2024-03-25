#include "Header.h"

void exportData(YearNode *headYear, ofstream &fo)
{
	YearNode *curYear = headYear;
	while (curYear != NULL)
	{
		fo << "Year" << endl;
		fo << curYear->data << endl;
		SemesterInfo curSem = curYear->semester[0];

		curYear = curYear->pNext;
	}
}

void exportSemester(SemesterInfo curSem, int sem, ofstream &fo)
{
	fo << "Semester " << endl;
	fo << sem << endl;
	exportDate(curSem.start, fo);
	exportDate(curSem.end, fo);
	CourseNode *curCourse = curSem.course;
	while (curCourse != NULL)
	{
		exportCourse(curCourse, fo);
		curCourse = curCourse->pNext;
	}
}

void exportCourse(CourseNode *curCourse, ofstream &fo)
{
	fo << "Course" << endl;
	CourseInfo info = curCourse->data;
	fo << info.course_id << endl;
	fo << info.course_name << endl;
	fo << info.class_name << endl;
	fo << info.teacher_name << endl;
	fo << info.num_of_credit << endl;
	fo << info.max_student << endl;
	fo << info.day_of_week << endl;
	fo << info.session << endl;
	StudentNode *curStu = curCourse->student;
	while (curStu != NULL)
	{
		exportStudent(curStu, fo);
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
	fo << score.total << " " << score.final << " " << score.midterm << " " << score.other << endl;
}

void importYear(YearNode *&headYear, ifstream &fi)
{
	string type;
	fi >> type;
	YearNode *curYear = NULL;
	while (type == "Year")
	{
		YearNode *newYear = new YearNode;
		fi >> curYear->data;
		if (curYear == NULL)
			headYear = newYear;
		else
			curYear->pNext = newYear;
		curYear = newYear;
		fi >> type;
		while (type == "Semester")
		{
			int sem;
			fi >> sem;
			SemesterInfo curSe = curYear->semester[sem];
			importSemester(curSe, sem, fi, type);
		}
	}
}

void importSemester(SemesterInfo &curSem, int sem, ifstream &fi, string &type)
{
	importDate(curSem.start, fi);
	importDate(curSem.end, fi);
	fi >> type;
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
		importCourse(curCourse, fi, type);
	}
}

void importCourse(CourseNode *&curCourse, ifstream &fi, string &type)
{
	CourseInfo info = curCourse->data;
	fi >> info.course_id;
	fi >> info.course_name;
	fi >> info.class_name;
	fi >> info.teacher_name;
	fi >> info.num_of_credit;
	fi >> info.max_student;
	fi >> info.day_of_week;
	fi >> info.session;
	fi >> type;
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
		importStudent(curStu, fi);
		fi >> type;
	}
}

void importStudent(StudentNode *&curStu, ifstream &fi)
{
	StudentInfo info = curStu->data;
	fi >> info.No;
	fi >> info.ID;
	fi >> info.first_name;
	fi >> info.last_name;
	importDate(info.dob, fi);
	fi >> info.gender;
	fi >> info.social_id;
	ScoreInfo score = info.score;
	fi >> score.total >> score.final >> score.midterm >> score.other;
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
