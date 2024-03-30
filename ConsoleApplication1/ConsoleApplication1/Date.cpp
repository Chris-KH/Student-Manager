#include"Date.h"


void exportDate(Date &date, ofstream &fout)
{
	fout << date.day << " " << date.month << " " << date.year << endl;
}

void importDate(Date &date, ifstream& fin)
{
	fin >> date.day >> date.month >> date.year;
}