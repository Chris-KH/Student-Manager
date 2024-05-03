#include "Year.h"

void importCourseToSemester(YearNode *head, ifstream &fin, bool &ok2)
{
	for (int i = 0; i < 3; i++)
	{
		if (head->semester[i].created == false)
			continue;
		fin.open("DataFile/" + head->data + "-Semester" + char('1' + i) + ".csv");
		if (fin.is_open())
		{
			SemesterInfo *cur = (head->semester + i);
			string line;
			CourseNode *tail = nullptr;
			while (getline(fin, line))
			{
				CourseNode *temp = new CourseNode();
				stringstream ss(line);
				getline(ss, temp->data.course_name, ',');
				getline(ss, temp->data.class_name, ',');
				getline(ss, temp->data.ID, ',');
				getline(ss, temp->data.teacher_name, ',');
				getline(ss, temp->data.day_of_week, ',');

				/*ifstream fin;
				fin.open("DataFile/" + temp->data.class_name+".csv");
				if (fin.is_open())
					importStudentToClass(temp->student, fin);
				else cout << "Unable to import student to the course in file" << "DataFile / " + temp->data.class_name+".csv" << endl;
				fin.close();*/

				string s;
				getline(ss, s, ',');
				temp->data.session = s[0] - '0';

				getline(ss, s, ',');
				temp->data.credit = 0;
				for (int j = 0; j < (int)s.length(); j++)
				{
					temp->data.credit *= 10;
					temp->data.credit += s[j] - '0';
				}

				getline(ss, s, ',');
				temp->data.max_student = 0;
				for (int j = 0; j < (int)s.length(); j++)
				{
					temp->data.max_student *= 10;
					temp->data.max_student += s[j] - '0';
				}
				if (tail == nullptr)
				{
					cur->course = temp;
				}
				else
				{
					tail->pNext = temp;
				}
				tail = temp;
			}
			fin.close();
		}
		else
		{
			ok2 = true;
		}
	}
}

void exportCourseToSemester(YearNode *head, SemesterInfo *&curSes, ofstream &fout)
{
	fout.open("DataFile/" + head->data + "-Semester" + char('0' + curSes->order) + ".csv");
	if (fout.is_open())
	{
		CourseNode* curCourse = curSes->course;
		while (curCourse != nullptr)
		{
			if (curCourse != curSes->course)
				fout << "\n";
			fout << curCourse->data.course_name << ",";
			fout << curCourse->data.class_name << ",";
			fout << curCourse->data.ID << ",";
			fout << curCourse->data.teacher_name << ",";
			fout << curCourse->data.day_of_week << ",";
			fout << curCourse->data.session << ",";
			fout << curCourse->data.credit << ",";
			fout << curCourse->data.max_student << ",";
			curCourse = curCourse->pNext;
		}
		fout.close();
	}
}

void importSchoolYearData(YearNode *&head, YearNode *&tail, ifstream &fin)
{
	string s;
	while (getline(fin, s))
	{
		YearNode *temp = new YearNode(s);
		for (int i = 0; i < 3; i++)
		{
			string a;
			getline(fin, a);
			stringstream ss(a);
			string created, start, end;
			getline(ss, created, ' ');
			temp->semester[i].created = (created == "1");
			if (created == "0")
				continue;
			getline(ss, start, ' ');
			getline(ss, end);
			temp->semester[i].start.day = start.substr(0, 2);
			temp->semester[i].start.month = start.substr(3, 2);
			temp->semester[i].start.year = start.substr(6, 4);
			temp->semester[i].end.day = end.substr(0, 2);
			temp->semester[i].end.month = end.substr(3, 2);
			temp->semester[i].end.year = end.substr(6, 4);
			temp->semester[i].order = i + 1;
		}
		if (tail == nullptr)
		{
			head = temp;
		}
		else
		{
			tail->pNext = temp;
		}
		tail = temp;
	}
}

void addNewClass(YearNode *&head, ofstream &fout)
{
	cout << "Choose year: " << endl;
	string year;
	YearNode* cur = head;
	int cnt = 0;
	while (cur)
	{
		cout << ++cnt << ". " << cur->data << "\n";
		cur = cur->pNext;
	}
	cout << ">>";
	YearNode *curYear = findSchoolYear(head,cnt);
	if (curYear == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again" << ANSI_WHITE << "\n";
		curYear = findSchoolYear(head, cnt);
	}
	string name;
	cout << "Input name of class: ";
	cin >> name;
	ClassNode *tailClass = curYear->classes;
	while (tailClass)
	{
		if (tailClass->data.name == name)
		{
			cout << ANSI_RED << "This class is created before.\n";
			return;
		}
		if (tailClass->pNext == nullptr)
			break;
		tailClass = tailClass->pNext;
	}
	fout.open("DataFile/" + curYear->data + "Classes.txt");
	if (fout.is_open())
	{
		ClassNode *temp = new ClassNode(name);

		if (tailClass == nullptr)
			curYear->classes = temp;
		else
			tailClass->pNext = temp;

		exportClassData(curYear->classes, fout);
		cout << ANSI_GREEN << "Class is added successfully.\n";

		fout.close();
	}
	else
		cout << ANSI_RED << "Add class failed.\n";
}

void createASchoolYear(YearNode *&head, YearNode *&tail)
{
	string s;
	cout << "Input your school year (format yyyy-yyyy, for example): ";
	cin >> s;
	YearNode *cur = head;
	while (cur)
	{
		if (cur->data == s)
		{
			cout << ANSI_RED << "This year is created before.\n";
			return;
		}
		cur = cur->pNext;
	}

	YearNode *temp = new YearNode(s);

	for (int i = 0; i < 3; i++)
	{
		temp->semester[i].created = 0;
	}
	if (tail == nullptr)
	{
		head = temp;
	}
	else
		tail->pNext = temp;
	tail = temp;
	ofstream fout;
	fout.open("DataFile/" + temp->data + "Classes.txt", ios::trunc);
	fout.close();
	cout << ANSI_GREEN << "Create school year successfully.\n";
}

void exportSchoolYearData(YearNode *head, ofstream &fout)
{
	
	YearNode *cur = head;
	while (cur)
	{
		if (cur != head)
			fout << "\n";
		fout << cur->data << "\n";
		for (int i = 0; i < 3; i++)
		{
			fout << cur->semester[i].created;
			if (cur->semester[i].created)
			{
				fout << " " << cur->semester[i].start.day << "/" << cur->semester[i].start.month << "/" << cur->semester[i].start.year << " ";
				fout << cur->semester[i].end.day << "/" << cur->semester[i].end.month << "/" << cur->semester[i].end.year;
			}
			if (i != 2)
				fout << "\n";
		}

		cur = cur->pNext;
	}
	fout.close();
}

void addCourse(YearNode *curYear, SemesterInfo *&curSes)
{
	CourseNode *curCourse = curSes->course;
	CourseNode *newcourse = new CourseNode();
	if (curCourse == nullptr)
	{
		curSes->course = newcourse;
		curCourse = newcourse;
	}
	else
	{
		while (curCourse->pNext)
			curCourse = curCourse->pNext;
		curCourse->pNext = newcourse;
		curCourse = curCourse->pNext;
	}
	cout << "Course name: ";
	cin.ignore();
	getline(cin, curCourse->data.course_name);

	cout << "Class name: ";
	getline(cin, curCourse->data.class_name);

	ClassNode *curClass = findClass(curYear->classes, curCourse->data.class_name);
	while (curClass == nullptr)
	{
		cout << ANSI_RED << "This class does not exist.\n" << ANSI_WHITE;
		curClass = findClass(curYear->classes, askClassName());
	}

	ifstream fin;
	fin.open("DataFile/" + curCourse->data.class_name + ".csv");
	if (fin.is_open())
	{
		importStudentToClass(curCourse->student, fin);
		fin.close();
	}
	
	cout << "Course ID: ";
	cin >> curCourse->data.ID;
	cin.ignore();

	cout << "Teacher name: ";
	getline(cin, curCourse->data.teacher_name);

	cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): ";
	cin >> curCourse->data.day_of_week;

	cout << "Session: \n";
	cout << "1. S1(07:30)\n";
	cout << "2. S2(09:30)\n";
	cout << "3. S3(13:30)\n";
	cout << "4. S4(15:30)\n";
	cout << "Press a number (1-4) to choose: ";
	cin >> curCourse->data.session;

	cout << "Number of credits: ";
	cin >> curCourse->data.credit;

	cout << "The maximum number of students in the course: ";
	cin >> curCourse->data.max_student;

	ofstream fout;
	exportCourseToSemester(curYear, curSes, fout);
	
	/*fout << endl;
	fout << curCourse->data.course_name << ",";
	fout << curCourse->data.class_name << ",";
	fout << curCourse->data.ID << ",";
	fout << curCourse->data.teacher_name << ",";
	fout << curCourse->data.day_of_week << ",";
	fout << curCourse->data.session << ",";
	fout << curCourse->data.credit << ",";
	fout << curCourse->data.max_student;
	*/
	ofstream fout2;
	fout2.open("DataFile/Courses/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv");
	exportStudent(curCourse->student, fout2);

	fout.close();
	fout2.close();
	cout << ANSI_GREEN << "The course is added successfully" << endl;
}

YearNode *findSchoolYear(YearNode *head, int total)
{
	int n, cnt;
	cnt = 0;
	cout << "Your choice (1->" << total << "): ";
	cin >> n;
	if (n > total)
		return nullptr;
	while (head)
	{
		cnt++;
		if (n == cnt)
			return head;
		head = head->pNext;
	}
	return nullptr;
}

void addNewStudentToClass(UserNode *&tailUser, YearNode *head, ifstream &fin)
{
	if (head == nullptr)
	{
		cout << ANSI_RED << "Haven't created any school year" << endl;
		return;
	}
	cout << "Choose year: " << endl;
	string year;
	YearNode* cur = head;
	int cnt = 0;
	while (cur)
	{
		cout << ++cnt << ". " << cur->data << "\n";
		cur = cur->pNext;
	}
	cout << ">>Your choice (1->" << cnt << "): ";
	YearNode *curYear = findSchoolYear(head, cnt);
	while (curYear == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		curYear = findSchoolYear(head, cnt);
	}
	
	cout << "List of classes in school year " << curYear->data << endl;
	cnt = 0;
	ClassNode* temp = curYear->classes;
	while (temp != nullptr)
	{
		cout << ++cnt << ". " << temp->data.name << " " << endl;
		temp = temp->pNext;
	}
	ClassNode* curClass = chooseClass(curYear->classes,cnt);
	while (curClass == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		curClass = chooseClass(curYear->classes,cnt);
	}
	StudentNode *curStudent = curClass->student;
	if (curStudent != nullptr)
	{
		cout << ANSI_RED << "Students is already added to this class.\n";
		return;
	}
	fin.open("InputFile/" + curClass->data.name + ".csv");
	if (fin.is_open())
	{
		importStudentToClass(curClass->student, fin);
		ofstream fout;
		fout.open("DataFile/" + curClass->data.name + ".csv");
		exportStudent(curClass->student, fout);
		createNewUsers(tailUser, curClass->student);
		cout << ANSI_GREEN << "Student is added successfully.\n";
		fin.close();
		fout.close();
	}
	else
		cout << ANSI_RED << "Add student failed.\n";
}

void viewListOfStudentInClass(YearNode *head)
{
	if (head == nullptr)
	{
		cout << ANSI_RED << "Haven't created any school year" << endl;
		return;
	}
	cout << "Choose year: " << endl;
	string year;
	YearNode* curYear = head;
	int cnt = 0;
	while (curYear)
	{
		cout << ++cnt << ". " << curYear->data << "\n";
		curYear = curYear->pNext;
	}
	cout << ">>";
	curYear = findSchoolYear(head,cnt);
	while (curYear == nullptr)
	{
		cout << "Wrong option. Try again.\n";
		curYear = findSchoolYear(head,cnt);
	}

	cout << "List of classes in school year " << curYear->data << endl;
	cnt = 0;
	ClassNode *temp = curYear->classes;
	if (temp == nullptr)
	{
		cout << ANSI_RED << "Haven't created any class in this school year" << endl;
		return;
	}
	while (temp != nullptr)
	{
		cout << ++cnt << ". " << temp->data.name << " " << endl;
		temp = temp->pNext;
	}
	ClassNode* curClass = chooseClass(curYear->classes, cnt);
	while (curClass == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		curClass = chooseClass(curYear->classes, cnt);
	}
	StudentNode *cur = curClass->student;
	if (cur == nullptr)
	{
		cout << ANSI_RED << "There is no student in class " << curClass->data.name << ".\n";
		return;
	}
	cout << "List of student in class " << curClass->data.name << ":\n";
	while (cur)
	{
		printStudentIn4(cur);
		cout << "------------------------" << endl;
		cur = cur->pNext;
	}
}

void viewAListOfClasses(YearNode *head)
{
	if (head == nullptr)
	{
		cout << ANSI_RED << "Haven't created any school year" << endl;
		return;
	}
	cout << "Choose year: " << endl;
	string year;
	YearNode* curYear = head;
	int cnt = 0;
	while (curYear)
	{
		cout << ++cnt << ". " << curYear->data << "\n";
		curYear = curYear->pNext;
	}
	cout << ">>Your choice (1->" << cnt << "): ";
	YearNode* temp = findSchoolYear(head, cnt);
	while (temp == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		temp = findSchoolYear(head, cnt);
	}

	cout << "List of classes in " << temp->data << ":\n";
	ClassNode *cur = temp->classes;
	if (cur == nullptr)
	{
		cout << ANSI_RED << "Haven't created any class in this year." << endl;
	}
	else
	{
		int cnt = 0;
		while (cur)
		{
			cout << ++cnt << ". " << cur->data.name << "\n";
			cur = cur->pNext;
		}
	}
}

void viewAllClasses(YearNode* head)
{
	YearNode* curYear = head;
	while (curYear)
	{
		cout << "List of classes in " << curYear->data << ":\n";
		ClassNode* curClass = curYear->classes;
		if (curClass == nullptr)
		{
			cout << ANSI_RED << "Haven't created any class in this year." << endl << ANSI_WHITE;
		}
		else
		{
			int cnt = 0;
			while (curClass)
			{
				cout << ++cnt << ". " << curClass->data.name << "\n";
				curClass = curClass->pNext;
			}
		}
		curYear = curYear->pNext;
	}
}


SemesterInfo *createSemester(YearNode *head)
{
	if (head == nullptr)
	{
		cout << ANSI_RED << "Haven't created any school year.\n";
		return nullptr;
	}
	YearNode* cur = head;
	int cnt = 0;
	while (cur)
	{
		cout << ++cnt << ". " << cur->data << "\n";
		cur = cur->pNext;
	}
	YearNode *temp = findSchoolYear(head, cnt);
	if (temp == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		temp=findSchoolYear(head,cnt);
	}
	string s;
	int ses;
	string d1, m1, y1, d2, m2, y2;
	cout << "Input information about the semester as follows.\n";
	cout << "What semester do you want to create (1, 2 or 3)? ";
	cin >> ses;
	if (ses != 1 && ses != 2 && ses != 3)
	{
		cout << ANSI_RED << "This semester does not exit.\n";
		return nullptr;
	}
	else if (temp->semester[ses - 1].created == true)
	{
		cout << ANSI_RED << "This semester is created before.\n";
		return nullptr;
	}
	cout << "Date (format dd/mm/yy, for example: 01/01/2021)" << endl;
	cout << "Start date: ";
	cin >> s;
	stringstream ss(s);
	getline(ss, d1, '/');
	getline(ss, m1, '/');
	getline(ss, y1);
	cout << "End date: ";
	cin >> s;
	stringstream aa(s);
	getline(aa, d2, '/');
	getline(aa, m2, '/');
	getline(aa, y2);
	SemesterInfo a;
	temp->semester[ses - 1].created = 1;
	temp->semester[ses - 1].order = ses;
	temp->semester[ses - 1].start.day = d1;
	temp->semester[ses - 1].start.month = m1;
	temp->semester[ses - 1].start.year = y1;
	temp->semester[ses - 1].end.day = d2;
	temp->semester[ses - 1].end.month = m2;
	temp->semester[ses - 1].end.year = y2;
	ofstream fout;
	fout.open("DataFile/" + temp->data + "-Semester" + to_string(ses) + ".csv");
	fout.close();
	cout << ANSI_GREEN << "Create semester successfully.\n";
	return &temp->semester[ses - 1];
}

StudentNode* findAStudentInSystem(string s, YearNode* headYear)
{
	YearNode* cur = headYear;
	while (cur != nullptr)
	{
		ClassNode* curClass = cur->classes;
		while (curClass!=nullptr)
		{
			StudentNode* temp = findAStudentInClass(s, curClass);
			if (temp != nullptr)
				return temp;
			curClass = curClass->pNext;
		}
		cur = cur->pNext;
	}
	return nullptr;
}
void addStudentToCourse(YearNode*& headYear, CourseNode*& curCourse)
{
	string s;
	cout << "Please input student ID: ";
	cin.ignore();
	getline(cin, s);

	if (findStudentInACourse(s, curCourse) != nullptr)
	{
		cout << ANSI_RED << "This student has been added to the course." << endl;
		return;
	}
	else
	{
		StudentNode* temp = findAStudentInSystem(s, headYear);
		if (temp == nullptr)
		{
			cout << ANSI_RED << "This student ID doesn't exist in the system." << endl;
			return;
		}
		cout << ">>Student information: " << endl;
		printStudentIn4(temp);
		cout << "Please input '1' if you want to add/ '0' if you don't." << endl;
		int opt;
		cout << ">>Your choice: ";
		cin >> opt;
		if (opt == 1)
		{
			StudentNode* newStu = new StudentNode;
			newStu->data = temp->data;
			newStu->pNext = nullptr;
			StudentNode* curStu = curCourse->student;
			if (curStu == nullptr)
			{
				curCourse->student = newStu;
				newStu->data.No = 1;
			}
			else
			{
				while (curStu->pNext)
					curStu = curStu->pNext;
				newStu->data.No = curStu->data.No + 1;
				curStu->pNext = newStu;
			}
			cout << ANSI_GREEN << "The new student is added successfully to the course.\n";
		}
		else cout << ANSI_RED << "You didn't add new student to the course" << endl;

	}
}

SemesterInfo *chooseASemester(YearNode *head, YearNode *&temp)
{
	if (head == nullptr)
	{
		cout << ANSI_RED << "Haven't created any school year yet" << endl;
		return nullptr;
	}
	YearNode* cur = head;
	int cnt = 0;
	cout << "Choose school year" << endl;
	while (cur)
	{
		cout << ++cnt << ". " << cur->data << "\n";
		cur = cur->pNext;
	}
	YearNode* curYear = findSchoolYear(head, cnt);
	if (curYear == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		curYear = findSchoolYear(head, cnt);
	}
	temp = curYear;
	int ses;
	cout << "Choose semester (1->3): ";
	cin >> ses;
	while (ses != 1 && ses != 2 && ses != 3)
	{
		cout << "Invalid semester. Try again.\n";
		cout << "Choose semester (1->3): ";
		cin >> ses;
	}
	if (curYear->semester[ses - 1].created == false)
	{
		cout << ANSI_RED << "This semester has not been created yet.\n" << ANSI_WHITE;
		cout << "Please choose other semester.\n";
		return nullptr;
	}
	return &curYear->semester[ses - 1];
}

void deleteACourse(YearNode* head, SemesterInfo*& curSes, ofstream& fout)
{
	CourseNode* curCourse = findCourse(curSes->course);
	if (curCourse == nullptr)
	{
		cout << ANSI_RED << "This course does not exist in this semester.\n";
		return;
	}
	
	//delete files
	string path = "DataFile/Courses/" + head->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv";
	char* filename = new char[path.size() + 1];
	copy(path.begin(), path.end(), filename);
	filename[path.size()] = '\0';
	int result = remove(filename);
	delete[] filename;

	//delete pointer
	if (curCourse == curSes->course)
	{
		CourseNode* temp = curSes->course;
		curSes->course = curSes->course->pNext;
		delete temp;
		cout << ANSI_GREEN << "Delete course successfully.\n" << ANSI_WHITE;
	}
	else
	{
		CourseNode* prev = nullptr;
		CourseNode* cur = curSes->course;
		while (cur)
		{
			if (cur == curCourse)
			{
				CourseNode* temp = cur;
				prev->pNext = cur->pNext;
				delete temp;
				cout << ANSI_GREEN << "Delete course successfully.\n" << ANSI_WHITE;
				break;
			}
			prev = cur;
			cur = cur->pNext;
		}
	}
	if (result == 0)
		cout << ANSI_GREEN << "Delete related files successfully" << endl;
	else cout << ANSI_RED << "Fail to delete related files" << endl;
	
	exportCourseToSemester(head, curSes, fout);

}

double calculateGPA(YearNode* head, StudentNode* stu)
{
	int cnt = 0;
	double GPA = 0;
	YearNode* curYear = head;
	while (curYear)
	{
		for (int ses = 0; ses < 3; ++ses)
		{
			CourseNode* curCourse = curYear->semester[ses].course;
			while (curCourse)
			{
				StudentNode* curStu = findStudentInACourse(stu->data.ID, curCourse);
				if (curStu)
				{
					GPA += 1.0 * curStu->data.score.final;
					++cnt;
				}
				curCourse = curCourse->pNext;
			}
		}
		curYear = curYear->pNext;
	}
	return GPA / (1.0 * cnt);
}
void viewScoreboardofClass(YearNode* head, YearNode* curYear, int ses, int cnt)
{
	ofstream fout;
	ClassNode*& headClass = curYear->classes;
	ClassNode* curClass = chooseClass(headClass, cnt);
	while (curClass == nullptr)
	{
		cout << ANSI_RED << "Wrong option. Try again.\n" << ANSI_WHITE;
		curClass = chooseClass(headClass, cnt);
	}
	StudentNode* stu = curClass->student;
	cout << "Scoreboard of class " << curClass->data.name << " - Semester " << ses + 1 << " - " << curYear->data << endl;
	while (stu)
	{
		int cnt = 0;
		double GPAses = 0;
		cout << stu->data.No << ".";
		cout << "  Student name: " << stu->data.first_name << " " << stu->data.last_name << endl;
		cout << "    Student ID: " << stu->data.ID << endl;
		cout << "    Score" << endl;
		cout << "    >>Final mark of courses "<< endl;
		CourseNode* curCourse = curYear->semester[ses].course;
		while (curCourse)
		{
			StudentNode* curStu = findStudentInACourse(stu->data.ID, curCourse);

			if (curStu)
			{
				++cnt;
				cout << "      " << cnt << ". " << curCourse->data.ID << " - " << curCourse->data.course_name << ": " << curStu->data.score.final << endl;
				GPAses += 1.0 * curStu->data.score.final;
			}
			curCourse = curCourse->pNext;
		}
		GPAses = GPAses / (1.0 * cnt);
		cout << "      >>GPA in this semester: " << fixed << setprecision(3) << GPAses << endl;
		cout << "    >>Overall GPA: " << fixed << setprecision(3) << calculateGPA(head, stu) << endl;
		stu = stu->pNext;
	}
}