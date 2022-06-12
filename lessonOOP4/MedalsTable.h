#pragma once
#include "MedalRow.h"
class MedalsTable
{
public:
	static const int maxSize{ 10 };
private:
	MedalRow* medalRows;
	int size;
	int findCountry(const char* country)const;
public:
	MedalsTable();
	MedalsTable(const MedalsTable& other);
	~MedalsTable();
	MedalRow& operator[](const char* country);
	const MedalRow& operator[](const char* country)const;
	void print()const;
};

