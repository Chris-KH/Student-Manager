#include"Year.h"

void createASchoolYear(YearNode*& head, YearNode* tail) {
	string s;
	cout << "Input your school year (2020-2021, for example): "; cin >> s;
	YearNode* temp = new YearNode(s);
	if (tail == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->pNext = temp;
		tail = temp;
	}
}

void importSchoolYearData(YearNode*& head, ifstream& fin) {
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
			temp->semester[i].start.year = start.substr(6, 2);
			temp->semester[i].end.day = end.substr(0, 2);
			temp->semester[i].end.month = end.substr(0, 2);
			temp->semester[i].end.year = end.substr(0, 2);
		}
		if (head == nullptr) {
			head = temp;
		}
		else {
			temp->pNext = head;
			head = temp;
		}
	}
}

void exportSchoolYearData(YearNode* head, ofstream& fout) {
	while (head) {
		fout << head->data << "\n";
		head = head->pNext;
	}
}

YearNode* findSchoolYear(YearNode* head) {
	string year;
	cout << "Enter year: "; cin >> year;
	while (head) {
		if (head->data == year) return head;
	}
	return nullptr;
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
	int ses;
	string d1, m1, y1, d2, m2, y2;
	cout << "Input information about the semester as follows.\n";
	cout << "What semester do you want to create (1, 2 or 3)? "; cin >> ses;
	cout << "Start date: "; 
	cin.ignore();
	cin.clear();
	getline(cin, d1, '/');
	getline(cin, m1, '/');
	getline(cin, y1);
	cout << "End date: ";
	getline(cin, d2, '/');
	getline(cin, m2, '/');
	getline(cin, y2);
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