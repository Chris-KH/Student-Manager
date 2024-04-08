#include"Year.h"

void importCourseToSemester(YearNode* head, ifstream& fin, bool& ok2) {
	for (int i = 0; i < 3; i++) {
		if (head->semester[i].created == false) continue;
		fin.open("DataFile/" + head->data + "-Semester" + char('1' + i) + ".csv");
		if (fin.is_open()) {
			SemesterInfo* cur = (head->semester + i);
			string line;
			CourseNode* tail = nullptr;
			while (getline(fin, line)) {
				CourseNode* temp = new CourseNode();
				stringstream ss(line);
				getline(ss, temp->data.course_name, ',');
				getline(ss, temp->data.class_name, ',');
				getline(ss, temp->data.ID, ',');
				getline(ss, temp->data.teacher_name, ',');
				getline(ss, temp->data.day_of_week, ',');

				string s;

				getline(ss, s, ',');
				temp->data.session = s[0] - '0';

				getline(ss, s, ',');
				temp->data.credit = 0;
				for (int j = 0; j < (int)s.length(); j++) {
					temp->data.credit *= 10;
					temp->data.credit += s[j] - '0';
				}

				getline(ss, s, ',');
				temp->data.max_student = 0;
				for (int j = 0; j < (int)s.length(); j++) {
					temp->data.max_student *= 10;
					temp->data.max_student += s[j] - '0';
				}
				if (tail == nullptr) {
					cur->course = temp;
				}
				else {
					tail->pNext = temp;
				}
				tail = temp;
			}
			fin.close();
		}
		else {
			ok2 = true;
		}
	}
}

void importSchoolYearData(YearNode*& head, YearNode*& tail, ifstream& fin) {
	string s;
	while (getline(fin, s)) {
		YearNode* temp = new YearNode(s);
		for (int i = 0; i < 3; i++) {
			string a;
			getline(fin, a);
			stringstream ss(a);
			string created, start, end;
			getline(ss, created, ' ');
			temp->semester[i].created = (created == "1");
			if (created == "0") continue;
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
		if (tail == nullptr) {
			head = temp;
		}
		else {
			tail->pNext = temp;
		}
		tail = temp;
	}
}

void addNewClass(YearNode*& head, ofstream& fout) {
	YearNode* curYear = findSchoolYear(head);
	if (curYear == nullptr) {
		cout << "This year does not exist.\n";
		return;
	}
	string name;
	cout << "Input name of class: "; cin >> name;
	ClassNode* tailClass = curYear->classes;
	while (tailClass) {
		if (tailClass->data.name == name) {
			cout << "This class is created before.\n";
			return;
		}
		if (tailClass->pNext == nullptr) break;
		tailClass = tailClass->pNext;
	}
	fout.open("DataFile/" + curYear->data + "Classes.txt");
	if (fout.is_open()) {
		ClassNode* temp = new ClassNode(name);

		if (tailClass == nullptr) curYear->classes = temp;
		else tailClass->pNext = temp;

		exportClassData(curYear->classes, fout);
		cout << "Class is added.\n";

		fout.close();
	}
	else cout << "Add class failed.\n";
}

void createASchoolYear(YearNode*& head, YearNode*& tail) {
	string s;
	cout << "Input your school year (format yyyy-yyyy, for example): "; cin >> s;
	YearNode* cur = head;
	while (cur) {
		if (cur->data == s) {
			cout << "This year is created before.\n";
			return;
		}
		cur = cur->pNext;
	}

	YearNode* temp = new YearNode(s);

	for (int i = 0; i < 3; i++) {
		temp->semester[i].created = 0;
	}
	if (tail == nullptr) {
		head = temp;
	}
	else tail->pNext = temp;
	tail = temp;
	ofstream fout2;
	fout2.open("DataFile/" + temp->data + "Classes.txt");
	fout2.close();
	cout << "Create school year successfully.\n";
}

void exportSchoolYearData(YearNode* head, ofstream& fout) {
	YearNode* cur = head;
	ofstream fout2;
	while (cur) {
		if (cur != head) fout << "\n";
		fout << cur->data << "\n";
		for (int i = 0; i < 3; i++) {
			fout << cur->semester[i].created;
			if (cur->semester[i].created) {
				fout << " " << cur->semester[i].start.day << "/" << cur->semester[i].start.month << "/" << cur->semester[i].start.year << " ";
				fout << cur->semester[i].end.day << "/" << cur->semester[i].end.month << "/" << cur->semester[i].end.year;
			}
			if (i != 2) fout << "\n";
		}
		
		cur = cur->pNext;
	}
}

void addCourse(YearNode* curYear, SemesterInfo*& curSes, ofstream& fout)
{
	fout.open("DataFile/" + curYear->data + "-Semester" + char('0' + curSes->order) + ".csv", ios::app);
	CourseNode* curCourse = curSes->course;
	CourseNode* newcourse = new CourseNode;
	if (curCourse == nullptr)
		curCourse = newcourse;
	else
	{
		while (curCourse->pNext != nullptr)
			curCourse = curCourse->pNext;
		curCourse->pNext = newcourse;
		curCourse = curCourse->pNext;
	}

	cout << "Course name: \n";
	cin.ignore();
	getline(cin, curCourse->data.course_name);
	
	cout << "Class name: \n";
	getline(cin, curCourse->data.class_name);

	cout << "Course ID: \n";
	cin >> curCourse->data.ID;
	cin.ignore();

	cout << "Teacher name: \n";
	getline(cin, curCourse->data.teacher_name);

	cout << "Day of the week (MON / TUE / WED / THU / FRI / SAT): \n";
	cin >> curCourse->data.day_of_week;

	cout << "Session: \n";
	cout << "1. S1(07:30)\n";
	cout << "2. S2(09:30)\n";
	cout << "3. S3(13:30)\n";
	cout << "4. S4(15:30)\n";
	cout << "Press a number (1-4) to choose: \n";
	cin >> curCourse->data.session;

	cout << "Number of credits: \n";
	cin >> curCourse->data.credit;

	cout << "The maximum number of students in the course: \n";
	cin >> curCourse->data.max_student;
	fout << endl;
	fout << curCourse->data.course_name << ",";
	fout << curCourse->data.class_name << ",";
	fout << curCourse->data.ID << ",";
	fout << curCourse->data.teacher_name << ",";
	fout << curCourse->data.day_of_week << ",";
	fout << curCourse->data.session << ",";
	fout << curCourse->data.credit << ",";
	fout << curCourse->data.max_student;
	fout.close();
}

YearNode* findSchoolYear(YearNode* head) {
	string year;
	cout << "Enter year (yyyy-yyyy): "; cin >> year;
	cin.ignore();
	while (head) {
		if (head->data == year) return head;
		head = head->pNext;
	}
	return nullptr;
}

void addNewStudentToClass(UserNode *&tailUser, YearNode* head, ifstream& fin) {
	YearNode* curYear = findSchoolYear(head);
	if (curYear == nullptr) {
		cout << "This year does not exist.\n";
		return;
	}
	ClassNode* curClass = findClass(curYear->classes);
	if (curClass == nullptr) {
		cout << "This class does not exist.\n";
		return;
	}
	StudentNode* curStudent = curClass->student;
	if (curStudent != nullptr) {
		cout << "Student is already added to this class.\n";
		return;
	}
	fin.open("DataFile/" + curClass->data.name + ".csv");
	if (fin.is_open()) {
		importStudentToClass(curClass->student, fin);
		
		createNewUsers(tailUser, curClass->student);
		cout << "Student is added successfully.\n";
		fin.close();
	}
	else cout << "Add student failed.\n";
}


void viewListOfStudentInClass(YearNode* head) {
	YearNode* curYear = findSchoolYear(head);
	while (curYear == nullptr) {
		cout << "This year does not exist. Try again.\n";
		curYear = findSchoolYear(head);
	}
	ClassNode* temp = curYear->classes;
	ClassNode* curClass = findClass(temp);
	while (curClass == nullptr) {
		cout << "This class does not exist.\n";
		curClass = findClass(temp);
	}
	StudentNode* cur = curClass->student;
	if (cur == nullptr) {
		cout << "There is no student in class " << curClass->data.name << ".\n";
		return;
	}
	cout << "List of student in class " << curClass->data.name << ":\n";
	while (cur) {
		cout << cur->data.No << "\n";
		cout << "Student ID: " << cur->data.ID << "\n";
		cout << "Last name: " << cur->data.last_name << "\n";
		cout << "First name: " << cur->data.first_name << "\n";
		cout << "Gender: " << cur->data.gender << "\n";
		cout << "Data of birth: " << cur->data.dob.day << "/" << cur->data.dob.month << "/" << cur->data.dob.year << "\n";
		cout << "Social ID: " << cur->data.social_id << "\n";
		cur = cur->pNext;
	}
}

void viewAListOfClasses(YearNode* head) {
	YearNode* temp = findSchoolYear(head);
	if (temp == nullptr) {
		cout << "This year does not exist.\n";
		return;
	}
	cout << "List of classes in " << temp->data << ":\n";
	ClassNode* cur = temp->classes;
	while (cur) {
		cout << cur->data.name << "\n";
		cur = cur->pNext;
	}
}

void viewAllClasses(YearNode* head) {
	YearNode* curYear = head;
	while (curYear) {
		cout << "List of classes in " << curYear->data << ":\n";
		ClassNode* curClass = curYear->classes;
		while (curClass) {
			cout << curClass->data.name << "\n";
			curClass = curClass->pNext;
		} 
		curYear = curYear->pNext;
	}
}

SemesterInfo* createSemester(YearNode* head) {
	if (head == nullptr) {
		cout << "Year data is empty.\n";
		return nullptr;
	}
	YearNode* temp = findSchoolYear(head);
	if (temp == nullptr) {
		cout << "This year does not exist. Create school year before creating semester.\n";
		return nullptr; 
	}
	string s;
	int ses;
	string d1, m1, y1, d2, m2, y2;
	cout << "Input information about the semester as follows.\n";
	cout << "What semester do you want to create (1, 2 or 3)? "; cin >> ses;
	if (ses != 1 && ses != 2 && ses != 3) {
		cout << "This semester does not exit.\n";
		return nullptr;
	}
	else if (temp->semester[ses - 1].created == true) {
		cout << "This semester is created before.\n";
		return nullptr;
	}
	cout << "Start date: "; cin >> s;
	stringstream ss(s);
	getline(ss, d1, '/');
	getline(ss, m1, '/');
	getline(ss, y1);
	cout << "End date: "; cin >> s;
	stringstream aa(s);
	getline(aa, d2, '/');
	getline(aa, m2, '/');
	getline(aa, y2);
	SemesterInfo a;
	a.created = 1;
	a.start.day = d1;
	a.start.month = m1;
	a.start.year = y1;
	a.end.day = d2;
	a.end.month = m2;
	a.end.year = y2;
	temp->semester[ses - 1] = a;
	ofstream fout;
	fout.open("DataFile/" + temp->data + "-Semester" + to_string(ses) + ".csv");
	fout.close();
	cout << "Create semester successfully.\n";
	return &temp->semester[ses - 1];
}

SemesterInfo* chooseASemester(YearNode* head, YearNode*& temp) {
	YearNode* curYear = findSchoolYear(head);
	if (curYear == nullptr) {
		cout << "This school year does not exist.\n";
		cout << "Please choose an existed year to enter the semester.\n";
		return nullptr;
	}
	temp = curYear;
	int ses;
	cout << "Choose semester: "; cin >> ses;
	while (ses != 1 && ses != 2 && ses != 3) {
		cout << "Invalid semester.\n";
		cout << "Choose semester: "; cin >> ses;
	}
	if (curYear->semester[ses - 1].created == false) {
		cout << "This semester has not been created yet.\n";
		createSemester(head);
	}
	return &curYear->semester[ses - 1];
}

bool checkCurSes(YearNode* curYear, SemesterInfo* curSes)
{
	if (curYear && curSes)
		return true;
	cout << "Please choose current semester first" << endl;
	return false;
}
