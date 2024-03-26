#include "Class.h"

void importClassesData(ClassNode*& classes, ifstream& fin) {
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

void exportClassesData(ClassNode* classes, ofstream& fout) {
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
	}
	return nullptr;
}

void addNewClass(ClassNode*& head, ClassNode*& tail) {
	string name;
	cout << "Input class name: "; cin >> name;
	ClassNode* newClass = new ClassNode(name);
	if (head == nullptr) head = newClass;
	else tail->pNext = newClass;
	tail = newClass;
}

void deleteClasses(ClassNode*& head) {
	while (head) {
		ClassNode* temp = head;
		head = head->pNext;
		delete temp;
	}
}