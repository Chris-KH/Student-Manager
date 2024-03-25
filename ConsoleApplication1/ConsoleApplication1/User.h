#pragma once

#include "Date.h"

struct UserInfo
{
	string username = "";
	string password = "";
	bool is_staff = false;
	string name = "";
	Date dob;
	bool gender = 0; // 0 là nữ, 1 là nam
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

void exportUserData(UserNode* users, ofstream& fout);

bool login(UserNode* users, UserNode*& cur);

void changePassword(UserNode* &cur);

void viewProfileInfo(UserNode* user);

void deleteUserData(UserNode*& users);
