#pragma once

#include "Library.h"

struct Date
{
	int day = 0;
	int month = 0;
	int year = 0;
};

void exportDate(Date date, ofstream& fo);
void importDate(Date date, ifstream& fi);