#include "Header.h"

ClassNode* findClass(ClassNode*& head, string name)
{
	ClassNode* cur = head;
	while (cur != nullptr)
	{
		if (cur->data.name == name)
			return cur;
	}
	return nullptr;
}

void addNewClass(ClassNode*& head, ClassNode*& curClass)
{
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

	ifstream fi;
	fi.open("name.csv");
	while (!fi.eof())
	{
		int order;
		fi >> order;

		fi >> curClass->student->ID;
		fi >> curClass->student->first_name;
		fi >> curClass->student->last_name;
		string gen = "";
		fi >> gen;
		if (gen == "Male")
			curClass->student->gender = 1;
		else curClass->student->gender = 0;

		string dob = "";
		fi >> dob;
		curClass->student->dob.day = dob[0] + dob[1];
		curClass->student->dob.month = dob[2]+dob[3];
		curClass->student->dob.year = dob[4]+dob[5]+dob[6]+dob[7];

		fi >> curClass->student->social_id;
	}
}