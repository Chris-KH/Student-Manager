#include <iostream>

using namespace std;

#include "Header.h"

int main()
{
	string username, password;
	ImportUserData("user.csv");

	while (true)
	{
		cout << "User name: " << endl;
		cin >> username;
		cout << "Password: " << endl;
		cin >> password;
		if (logIn(username, password))
		{

			cout << "MENU:";
			cout<<""

		}
	}
}
