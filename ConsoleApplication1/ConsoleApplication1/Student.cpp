#include "Student.h"

void importStudentToClass(StudentNode *&head, ifstream &fin)
{
	string s;
	StudentNode *tail = nullptr;
	while (getline(fin, s))
	{
		StudentNode *temp = new StudentNode();
		cin >> temp->data.No;
		stringstream ss(s);
		getline(ss, temp->data.ID, ',');
		getline(ss, temp->data.last_name, ',');
		getline(ss, temp->data.first_name, ',');
		getline(ss, temp->data.gender, ',');
		getline(ss, temp->data.dob.day, '/');
		getline(ss, temp->data.dob.month, '/');
		getline(ss, temp->data.dob.year, ',');
		getline(ss, temp->data.social_id);
		
		if (tail == nullptr)
			head = temp;
		else
			tail->pNext = temp;
		tail = temp;
	}
}

void exportStudentInClass(StudentNode *head, ofstream &fout)
{
	while (head)
	{
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

void createNewUsers(UserNode*& tailUser, StudentNode* head)
{
	StudentNode* temp = head;
	while (temp != nullptr)
	{
		if (tailUser != nullptr)
		{
			UserNode* newuser = new UserNode;
			newuser->data.dob = temp->data.dob;
			newuser->data.gender = temp->data.gender;
			newuser->data.is_staff = 0;
			newuser->data.name = temp->data.last_name + " " + temp->data.first_name;
			newuser->data.username = temp->data.ID;
			newuser->data.password = temp->data.dob.day + temp->data.dob.month + temp->data.dob.year;
			tailUser->pNext = newuser;
			tailUser = tailUser->pNext;
		}
		temp = temp->pNext;
	}
}
/*void updateAStudentResult(StudentNode* &head)
{
	while (head != nullptr)
	{
		ifstream fin;
		StudentNode *cur = head;
		StudentInfo *curStu = cur->data;
		StudentNode *old = cur->data;
		updateAStudentResult
	}
	return;
}*/