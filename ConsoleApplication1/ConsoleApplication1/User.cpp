#include"User.h"

void importUserData(UserNode*& headUser, UserNode*& tailUser, ifstream& fin) {
	UserNode* cur = nullptr;
	string s;

	while (getline(fin, s)) {
		UserNode* temp = new UserNode();
		if (cur == nullptr) {
			headUser = temp;
			cur = temp;
		}
		else {
			cur->pNext = temp;
			cur = temp;
		}

		getline(fin, cur->data.name);
		fin >> cur->data.username >> cur->data.password >> cur->data.is_staff >> cur->data.gender;
		fin.ignore();
		fin.clear();


		string line;
		getline(fin, line);
		stringstream ss(line);
		getline(ss, cur->data.dob.day, '/');
		getline(ss, cur->data.dob.month, '/');
		getline(ss, cur->data.dob.year);
	}
	tailUser = cur;
}

void exportUserData(UserNode* users, ofstream& fout) {
	UserNode* cur = users;
	int order = 1;
	while (cur) {
		if (cur != users) fout << "\n";
		fout << order << "\n";
		fout << cur->data.name << "\n";
		fout << cur->data.username << " " << cur->data.password << " " << cur->data.is_staff << " " << cur->data.gender << "\n";
		fout << cur->data.dob.day << "/" << cur->data.dob.month << "/" << cur->data.dob.year;
		order++;
		cur = cur->pNext;
	}
}

bool login(UserNode* users, UserNode* &temp) {
	string username, password;
	cout << "Username: "; cin >> username;
	cout << "Password: "; cin >> password;
	UserNode* cur = users;
	while (cur) {
		if (cur->data.username == username && cur->data.password == password) {
			temp = cur;
			return true;
		}
		cur = cur->pNext;
	}
	return false;
}

void changePassword(UserNode*& cur) {
	string password, new_pass, new_pass2;
	while (true) {
		cout << "Please enter your current password: "; cin >> password;
		cout << "Enter new password: "; cin >> new_pass;
		cout << "Re-enter new password: "; cin >> new_pass2;
		if (password != cur->data.password) {
			cout << "Your current password is wrong. Please try again.\n";
		}
		else if (new_pass != new_pass2) {
			cout << "Something wrong, make sure your passwords match. Please try again.\n";
		}
		else {
			cur->data.password = new_pass;
			cout << "Your password has been changed successfully.\n";
			break;
		}
	}
}

void viewProfileInfo(UserNode* user) {
	cout << "Name: " << user->data.name << "\n";
	cout << "Date of birth: " << user->data.dob.day << "/" << user->data.dob.month << "/" << user->data.dob.year << "\n";
	cout << "Gender: " << user->data.gender << "\n";
}

void deleteUserData(UserNode*& users) {
	while (users != nullptr) {
		UserNode* temp = users;
		users = users->pNext;
		delete temp;
	}
}