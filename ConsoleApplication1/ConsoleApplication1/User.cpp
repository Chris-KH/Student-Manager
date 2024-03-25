#include"Header.h"

void importUserData(UserNode*& users, ifstream& fin) {
	UserNode* cur = nullptr;
	string s;

	while (getline(fin, s)) {
		UserNode* temp = new UserNode();
		if (cur == nullptr) {
			users = temp;
			cur = temp;
		}
		else {
			cur->pNext = temp;
			cur = temp;
		}

		getline(fin, cur->data.name);
		fin >> cur->data.username >> cur->data.password >> cur->data.is_staff >> cur->data.gender;

		string line;

		fin.ignore();
		getline(fin, line);
		stringstream ss(line);
		
		ss >> cur->data.dob.day >> cur->data.dob.month >> cur->data.dob.year;

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

void deleteUserData(UserNode*& users) {
	while (users != nullptr) {
		UserNode* temp = users;
		users = users->pNext;
		delete temp;
	}
}