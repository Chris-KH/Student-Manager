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

void deleteSchoolYear(YearNode*& head) {
	while (head) {
		YearNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}