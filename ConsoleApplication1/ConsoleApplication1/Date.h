#pragma once

#include "Library.h"

struct Date
{
	string day = "";
	string month = "";
	string year = "";
};

void exportDate(Date date, ofstream& fo);
void importDate(Date date, ifstream& fi);