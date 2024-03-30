#include"Year.h"

void importSchoolYearData(YearNode*& head, YearNode*& tail, ifstream& fin) {
	fin.open("DataFile/SchoolYear.txt");
	if (fin.is_open() == false) {
		cout << "Unable to load data.\n";
		exit(1);
	}

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
		}
		if (tail == nullptr) {
			head = temp;
		}
		else {
			tail->pNext = temp;
		}
		tail = temp;
	}
	fin.close();
}

void addNewClass(YearNode*& head) {
	YearNode* cur = findSchoolYear(head);
	string name;
	cout << "Input name of class: "; cin >> name;
	ClassNode* headClass = cur->classes;
	while (headClass) {
		if (headClass->data.name == name) {
			cout << "This class is created before.\n";
			return;
		}
		headClass = headClass->pNext;
	}
	ClassNode* temp = new ClassNode(name);
	if (cur->classes == nullptr) {
		cur->classes = temp;
	}
	else {
		temp->pNext = cur->classes;
		cur->classes = temp;
	}
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
	cout << "Create school year successfully.\n";
}

void exportSchoolYearData(YearNode* head, ofstream& fout) {
	YearNode* cur = head;
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

YearNode* findSchoolYear(YearNode* head) {
	string year;
	cout << "Enter year: "; cin >> year;
	while (head) {
		if (head->data == year) return head;
		head = head->pNext;
	}
	return nullptr;
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
	cout << "List of class in " << temp->data << ":\n";
	ClassNode* cur = temp->classes;
	while (cur) {
		cout << cur->data.name << "\n";
		cur = cur->pNext;
	}
}

void createSemester(YearNode* head) {
	if (head == nullptr) {
		cout << "Year data is empty.\n";
		return;
	}
	YearNode* temp = findSchoolYear(head);
	while (temp == nullptr) {
		cout << "This year does not exist, try again.\n";
		temp = findSchoolYear(head);
	}
	string s;
	int ses;
	string d1, m1, y1, d2, m2, y2;
	cout << "Input information about the semester as follows.\n";
	cout << "What semester do you want to create (1, 2 or 3)? "; cin >> ses;
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
	if (ses == 1 || ses == 2 || ses == 3) {
		if (temp->semester[ses - 1].created == false) {
			SemesterInfo a;
			a.start.day = y1;
			a.start.month = m1;
			a.start.year = y1;
			a.end.day = d2;
			a.end.month = m2;
			a.end.year = y2;
			temp->semester[ses - 1] = a;
		}
		else cout << "This semester is created before.\n";
	}
	else cout << "This semester does not exist.\n";
}

void deleteSemester(YearNode* head) {
	while (head) {
		delete[] head->semester;
		head = head->pNext;
	}
}

void deleteSchoolYear(YearNode*& head) {
	while (head) {
		YearNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}
