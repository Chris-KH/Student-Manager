#include <iostream>

using namespace std;

#include "Header.h"

int main() {
	cout << "Welcome to course management system.\n";

	UserNode* users = nullptr;
	ifstream fin("DataFile/Users.txt");
	if (fin.is_open()) {
		importUserData(users, fin);
		fin.close();
	}
	else {
		cout << "Unable to load data user.\n";
		return 0;
	}

	UserNode* logged_in = nullptr;
	while (true) {
		if (login(users, logged_in)) {
			cout << "Logged in successfully.\n";
		}
		else {
			cout << "Login failed. Please check your username and password and try again.\n";
		}
		cout << "Press 0 if you want to login again, if not press 1: ";
		int x; cin >> x;
		if (x) break;
	}



	return 0;
}
