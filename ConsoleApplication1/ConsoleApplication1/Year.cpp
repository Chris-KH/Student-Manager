#include"Header.h"

void createASchoolYear(YearNode*& head, YearNode* tail) {
	YearNode* temp = new YearNode();
	cout << "Input your school year (2020-2021, for example): "; cin >> temp->data;
	if (tail == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->pNext = temp;
		tail = temp;
	}
}

void importSchoolYear(YearNode*& head, ifstream& fin) {
	string s;
	while (getline(fin, s)) {
		YearNode* temp = new YearNode();
		temp->data = s;
		if (head == nullptr) {
			head = temp;
		}
		else {
			temp->pNext = head;
			head = temp;
		}
	}
}

void exportSchoolYear(YearNode* head, ofstream& fout) {
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