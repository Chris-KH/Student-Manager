#include"Student.h"

void importStudentToClass(StudentNode*& head, ifstream& fin) {
	string s;
	StudentNode* tail = nullptr;
	while (getline(fin, s)) {
		StudentNode* temp = new StudentNode();
		stringstream ss(s);
		getline(ss, temp->data.No, ',');
		getline(ss, temp->data.ID, ',');
		getline(ss, temp->data.last_name, ',');
		getline(ss, temp->data.first_name, ',');
		getline(ss, temp->data.gender, ',');
		string a;
		getline(ss, a, ',');
		stringstream dob_str(a);
		getline(dob_str, temp->data.dob.day, '/');
		getline(dob_str, temp->data.dob.month, '/');
		getline(dob_str, temp->data.dob.year);
		getline(ss, temp->data.social_id);
		if (tail == nullptr) {
			head = temp;
		}
		else {
			tail->pNext = temp;
		}
		tail = temp;
	}
}

void exportStudentInClass(StudentNode* head, ofstream& fout) {
	while (head) {
		fout << head->data.No << ",";
		fout << head->data.ID << ",";
		fout << head->data.last_name << ",";
		fout << head->data.first_name << ",";
		fout << head->data.gender << ",";
		fout << head->data.dob.day << "/" << head->data.dob.month << "/" << head->data.dob.year << ",";
		fout << head->data.social_id << "\n";
		head = head->pNext;
	}
}