#include"Header.h"

void importUserData(UserNode*& users, ifstream& fin) {
	UserNode* cur = nullptr;
	string s;

	while (getline(fin, s)) {
		UserNode* temp = new UserNode();
		if (users == nullptr) {
			users = temp;
			cur = temp;
		}
		else {
			cur->pNext = temp;
			cur = temp;
		}

		fin >> cur->data.username >> cur->data.password >> cur->data.is_staff;

		getline(fin, cur->data.name);

		string line;
		getline(fin, line);
		stringstream ss(line);
		
		ss >> cur->data.dob.day >> cur->data.dob.month >> cur->data.dob.year;

		fin >> cur->data.gender;
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