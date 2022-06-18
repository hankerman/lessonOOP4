#include "MedalRow.h"

MedalRow::MedalRow(const char* countryP, const int* medalsP)
{
	strcpy_s(country, 4, countryP ? countryP : "NON");
	for (int i{ 0 }; i < 3; ++i)
	{
		medals[i] = medalsP ? medalsP[i] : 0;
	}
}

MedalRow& MedalRow::setCountry(const char* countryP)
{
	if (countryP)
	{
		strcpy_s(country, 4, countryP);
	}
	return *this;
}

int& MedalRow::operator[](int idx)
{
	assert((idx >= 0 and idx < 3) and "Index out "
		"of range!");
	return medals[idx];
}

int MedalRow::operator[](int idx) const
{
	assert((idx >= 0 and idx < 3) and "Index out "
		"of range!");
	return medals[idx];
}

void MedalRow::print() const
{
	std::cout << '[' << country << "]-( ";
	for (int i{ 0 }; i < 3; ++i)
	{
		std::cout << medals[i];
		if (i < 2) { std::cout << '\t'; }
	}
	std::cout << " )\n";
}

int MedalRow::getMedal(int i)
{
	return medals[i];
}
