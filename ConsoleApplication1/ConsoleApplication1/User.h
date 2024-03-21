#pragma once

#include "Library.h"
#include "Date.h"

struct UserInfo
{
	string username = "";
	string password = "";
	bool is_staff = false;
	string name = "";
	Date dob;
	bool gender = 0;
};

struct UserNode
{
	UserInfo data;
	UserNode* pNext;
	UserNode() {
		pNext = nullptr;
	}
};

void importUserData(UserNode* &users, ifstream& fin);

bool login(UserNode* users, UserNode*& cur);

void changePassword(UserNode* &cur);

