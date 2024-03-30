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


