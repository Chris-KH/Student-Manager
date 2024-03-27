#include "Class.h"

void importClassData(ClassNode*& classes, ifstream& fin) {
	string s;
	while (getline(fin, s)) {
		ClassNode* temp = new ClassNode(s);
		if (classes == nullptr) {
			classes = temp;
		}
		else {
			temp->pNext = classes;
			classes = temp;
		}
	}
}

void exportClassData(ClassNode* classes, ofstream& fout) {
	while (classes) {
		fout << classes->data.name << '\n';
		classes = classes->pNext;
	}
}

void addStudent2Class(ClassNode* classes, ifstream& fin) {
	while (classes) {
		fin.open(classes->data.name + ".csv");
		if (fin.is_open()) {
			StudentNode* tail = nullptr;
			string data;
			while (getline(fin, data)) {
				tail = new StudentNode();
				if (classes->student == nullptr) {
					classes->student = tail;
				}
				stringstream ss(data);
				getline(ss, tail->data.No, ',');
				getline(ss, tail->data.ID, ',');
				getline(ss, tail->data.last_name, ',');
				getline(ss, tail->data.first_name, ',');
				getline(ss, tail->data.gender, '/');
				getline(ss, tail->data.dob.day, '/');
				getline(ss, tail->data.dob.month, '/');
				getline(ss, tail->data.dob.year, ',');
				getline(ss, tail->data.social_id, ',');
				tail = tail->pNext;
			}
			fin.close();
		}
		else {
			cout << "File is not open. Check your program on class.cpp.\n";
			break;
		}
	}
}

ClassNode* findClass(ClassNode* head) {
	string name;
	cout << "Input class name: "; cin >> name;
	ClassNode* cur = head;
	while (cur != nullptr)
	{
		if (cur->data.name == name)
			return cur;
		cur = cur->pNext;
	}
	return nullptr;
}


void deleteClasses(ClassNode*& head) {
	while (head) {
		ClassNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}

void viewAListOfClasses(ClassNode* head) {
	cout << "List of classes: \n";
	while (head) {
		cout << "    " << head->data.name << "\n";
		head = head->pNext;
	}
}

void viewListOfStudentInClass(ClassNode* head) {
	string s;
	cout << "Enter class name: "; cin >> s;
	while (head->data.name != s) head = head->pNext;
	if (head) {
		StudentNode* cur = head->student;
		cout << "List of student in class " << s << ":\n";
		while (cur) {
			cout << cur->data.No << "\n";
			cout << "Student ID: " << cur->data.ID << "\n";
			cout << "First name: " << cur->data.first_name << "\n";
			cout << "Last name: " << cur->data.last_name << "\n";
			cout << "Gender: " << cur->data.gender << "\n";
			cout << "Data of birth: " << cur->data.dob.day << "/" << cur->data.dob.month << "/" << cur->data.dob.year << "\n";
			cout << "Social ID: " << cur->data.social_id << "\n";
			cur = cur->pNext;
		}
	}
	else {
		cout << "This class does not exist.\n";
	}
}