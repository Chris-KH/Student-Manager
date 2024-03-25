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
	YearNode* cur = nullptr;
	string s;

	while (getline(fin, s)) {
		YearNode* temp = new YearNode();
		temp->data = s;
		if (cur == nullptr) {
			head = temp;
			cur = temp;
		}
		else {
			cur->pNext = temp;
			cur = temp;
		}
	}
}