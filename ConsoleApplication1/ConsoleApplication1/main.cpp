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
			break;
		}
		else {
			cout << "Login failed. Please check your username and password and try again.\n";
		}
	}

	menuForStaff();
	int n; 
	cout << "Your choice: "; cin >> n;

    switch (n)
    {
    case 1:
    {

    }
    case 2:
    {

    }
    case 3:
    {

    }
    case 4:
    {

    }
    case 5:
    {

    }
    case 6:
    {

    }
    case 7:
    {

    }
    case 8:
    {

    }
    case 9:
    {

    }
    case 10:
    {
    }
	return 0;
}
