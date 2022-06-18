#pragma once
#include <iostream>
#include "MedalRow.h"
using namespace std;
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
	friend ostream& operator<<(ostream& output, const MedalsTable& a);
	MedalsTable operator()(const char* country)const;
};

