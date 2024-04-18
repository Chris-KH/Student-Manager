#include "Student.h"

void importStudentToClass(StudentNode *&head, ifstream &fin)
{
	string s;
	StudentNode *tail = nullptr;
	while (getline(fin, s))
	{
		StudentNode *temp = new StudentNode();
		stringstream ss(s);
		string No;
		getline(ss, No, ',');
		temp->data.No = stoi(No);
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

void exportStudent(StudentNode *head, ofstream &fout)
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

void importScoreboard(StudentNode* &head, ifstream &fin)
{
	string s;
	StudentNode* tail = nullptr;
	while (getline(fin, s))
	{
		StudentNode* temp = new StudentNode();
		stringstream ss(s);
		string No;
		getline(ss, No, ',');
		temp->data.No = stoi(No);
		getline(ss, temp->data.ID, ',');
		getline(ss, temp->data.last_name, ',');
		getline(ss, temp->data.first_name, ',');
		getline(ss, temp->data.gender, ',');
		getline(ss, temp->data.dob.day, '/');
		getline(ss, temp->data.dob.month, '/');
		getline(ss, temp->data.dob.year, ',');
		getline(ss, temp->data.social_id,',');

		string tmp;
		getline(ss, tmp, ',');
		temp->data.score.midterm = stod(tmp);
		getline(ss, tmp, ',');
		temp->data.score.final = stod(tmp);
		getline(ss, tmp, ',');
		temp->data.score.bonus = stod(tmp);
		getline(ss, tmp);
		temp->data.score.total = stod(tmp);
		

		if (tail == nullptr)
			head = temp;
		else
			tail->pNext = temp;
		tail = temp;
	}
}

void exportScoreboard(StudentNode* head, ostream& fout)
{
	while (head != nullptr)
	{
		fout << head->data.No << ",";
		fout << head->data.ID << ",";
		fout << head->data.last_name << ",";
		fout << head->data.first_name << ",";
		fout << head->data.gender << ",";
		fout << head->data.dob.day << "/" << head->data.dob.month << "/" << head->data.dob.year << ",";
		fout << head->data.social_id << ",";
		fout << fixed << setprecision(1) << head->data.score.midterm << "," << head->data.score.final << "," << head->data.score.bonus << "," << head->data.score.total << "\n";
		head = head->pNext;
	}
}


void createNewUsers(UserNode*& tailUser, StudentNode* head)
{
	StudentNode* temp = head;
	UserNode* headtemp=tailUser;
	while (temp != nullptr)
	{
		if (tailUser != nullptr)
		{
			UserNode* newuser = new UserNode;
			newuser->data.order = tailUser->data.order + 1;
			newuser->data.dob = temp->data.dob;
			newuser->data.gender = temp->data.gender;
			newuser->data.is_staff = 0;
			newuser->data.name = temp->data.last_name + " " + temp->data.first_name;
			newuser->data.username = temp->data.ID;
			newuser->data.password = temp->data.dob.day + temp->data.dob.month + temp->data.dob.year;
			tailUser->pNext = newuser;
			tailUser = tailUser->pNext;
		}
		else
		{
			cout << "Create new users failed." << endl;
			return;
		}
		temp = temp->pNext;
	}
	ofstream fout;
	fout.open("DataFile/Users.txt", ios::app);
	if (fout.is_open())
	{
		if (headtemp->pNext != nullptr)
		{
			fout << endl;
			exportUserData(headtemp->pNext, fout);
		}
		fout.close();
	}
	else
	{
		cout << "Create accounts for new students failed.\n";
		return;
	}
}

void updateAStudentResult(StudentNode*& curStu)
{
	cout << "Current Result" << endl;
	cout << "   Midterm: " << curStu->data.score.midterm << endl;
	cout << "   Final: " << curStu->data.score.final << endl;
	cout << "   Bonus: " << curStu->data.score.bonus << endl;
	cout << "   Total: " << curStu->data.score.total << endl;

	cout << "Update midterm mark: ";
	cin >> curStu->data.score.midterm;
	cout << "Update final mark: ";
	cin >> curStu->data.score.final;
	cout << "Update bonus: ";
	cin >> curStu->data.score.bonus;

	curStu->data.score.total = 0.3 * curStu->data.score.midterm + 0.5 * curStu->data.score.final + 0.2 * curStu->data.score.bonus;
	cout << "Updated result" << endl;
	cout << "   Midterm: " << curStu->data.score.midterm << endl;
	cout << "   Final: " << curStu->data.score.final << endl;
	cout << "   Bonus: " << curStu->data.score.bonus << endl;
	cout << "   Total: " << curStu->data.score.total << endl;
}