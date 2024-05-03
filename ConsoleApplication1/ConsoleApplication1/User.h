#pragma once

#include "Date.h"

struct UserInfo
{
	int order = 0;
	string username;
	string password;
	bool is_staff = 0;
	string name;
	Date dob;
	string gender; // Chuyển thành string
};

struct UserNode
{
	UserInfo data;
	UserNode* pNext;
	UserNode() {
		pNext = nullptr;
	}
};

void importUserData(UserNode* &headlUser, UserNode *&tailUser, ifstream& fin);

void exportUserData(UserNode* users, ofstream& fout);

bool login(UserNode* users, UserNode*& temp);

void changePassword(UserNode* &cur);

void viewProfileInfo(UserNode* user);

void deleteUserData(UserNode*& users);
