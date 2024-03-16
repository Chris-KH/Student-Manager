#pragma once

#include "Library.h"
#include "Date.h"

struct UserInfo
{
	string username;
	string password;
	bool is_staff;
	string name;
	Date dob;
	bool gender;
};

struct UserNode
{
	UserInfo data;
	UserNode* pNext;
};

void importUserData(UserNode* &users, ifstream& fin);
bool login(string password, string username);

	