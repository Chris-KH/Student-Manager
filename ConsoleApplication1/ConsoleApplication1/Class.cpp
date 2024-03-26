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

void addStudentToClass(ClassNode* classes, ifstream& fin) {
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
		}
	}
}

ClassNode* findClass(ClassNode*& head, string name) {
	ClassNode* cur = head;
	while (cur != nullptr)
	{
		if (cur->data.name == name)
			return cur;
	}
	return nullptr;
}

void addNewClass(ClassNode*& head, ClassNode*& curClass) {
	string name="";
	cout << "Input class name: ";
	cin >> name;
	ClassNode* newClass = new ClassNode;
	newClass->data.name = name;
	if (head == nullptr)
		head = newClass;
	else curClass->pNext = newClass;
	curClass = newClass;
}

void add1stYearStudents2Class(ClassNode *&head)
{
	string name = "";
	cout << "Input class name: ";
	cin >> name;
	
	ClassNode* curClass = findClass(head, name);

	ifstream fin;
	fin.open("name.csv");
	while (!fin.eof())
	{
		int order;
		fin >> order;

		fin >> curClass->student->ID;
		fin >> curClass->student->first_name;
		fin >> curClass->student->last_name;
		string gender;
		fin >> gender;
		curClass->student->gender = gender;

		string dob = "";
		fin >> dob;
		curClass->student->dob.day = dob[0] + dob[1];
		curClass->student->dob.month = dob[2]+dob[3];
		curClass->student->dob.year = dob[4]+dob[5]+dob[6]+dob[7];

		fin >> curClass->student->social_id;
	}
}

