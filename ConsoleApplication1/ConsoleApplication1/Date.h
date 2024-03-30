#pragma once

#include "Menu.h"

struct Date
{
	string day;
	string month;
	string year;
};

void exportDate(Date &date, ofstream& foout);
void importDate(Date &date, ifstream& fin);