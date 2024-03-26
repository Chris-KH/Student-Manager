#include"Date.h"


void exportDate(Date date, ofstream &fo)
{
	fo << date.day << " " << date.month << " " << date.year << endl;
}

void importDate(Date date, ifstream& fi)
{
	fi >> date.day >> date.month >> date.year;
}