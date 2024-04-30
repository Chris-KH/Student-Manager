#include "Class.h"

void importClassData(ClassNode*& classes, ClassNode* tail, ifstream& fin) {
	string s;
	while (getline(fin, s)) {
		ClassNode* temp = new ClassNode(s);
		if (classes == nullptr) {
			classes = temp;
		}
		else {
			tail->pNext = temp;
		}
		tail = temp;
	}
}

void exportClassData(ClassNode* classes, ofstream& fout) {
	ClassNode* cur = classes;
	while (cur) {
		if (cur != classes) fout << "\n";
		fout << cur->data.name;
		cur = cur->pNext;
	}
}

ClassNode* findClass(ClassNode* head, string name) {
	ClassNode* cur = head;
	while (cur != nullptr)
	{
		if (cur->data.name == name)
			return cur;
		cur = cur->pNext;
	}
	return nullptr;
}

StudentNode* findAStudentInClass(string s, ClassNode* curClass)
{
	StudentNode* curStu = curClass->student;
	while (curStu)
	{
		if (curStu->data.ID == s)
			return curStu;
		curStu = curStu->pNext;
	}
	return nullptr;
}

ClassNode* chooseClass(ClassNode* head, int cnt)
{
	int opt;
	cout << ">>Your choice (1->" << cnt << "): ";
	cin >> opt;
	ClassNode* curClass = head;
	int count = 0;
	while (curClass != nullptr)
	{
		++count; 
		if (count == opt)
			return curClass;
		curClass = curClass->pNext;
	}
	return nullptr;
}

string askClassName()
{
	string name;
	cout << "Input class name: ";
	cin.ignore();
	getline(cin, name);
	return name;
}


void viewScoreboardofClass(ClassNode*& headClass) {
	ofstream fout;
	ClassNode *cur = headClass;
	findClass(cur,askClassName());
	if(cur != nullptr) exportStudent(cur->student, fout);
	else {
		cout << "No appropriate class. Please find the right class \n";
		viewScoreboardofClass(headClass);
	}
}