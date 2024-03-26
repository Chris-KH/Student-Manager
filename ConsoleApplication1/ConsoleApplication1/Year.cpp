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
	cout << "What semester do you want to create? "; cin >> ses;
	cout << ""
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