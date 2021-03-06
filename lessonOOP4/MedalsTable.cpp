#include "MedalsTable.h"

int MedalsTable::findCountry(const char* country) const
{
    for (int i{ 0 }; i < size; ++i)
    {
        if (strcmp(medalRows[i].getCountry(),
            country) == 0)
        {
            return i;
        }
    }
    return -1;
}

MedalsTable::MedalsTable()
{
    int size = 0;
    medalRows = nullptr;
}

MedalsTable::MedalsTable(const MedalsTable& other)
{
    this->size = other.size;
    this->medalRows = new MedalRow[size];
    for (int i = 0; i < size; i++) {
        medalRows[i] = other.medalRows[i];
    }
}

MedalsTable::~MedalsTable()
{
    delete[]medalRows;
}

MedalRow& MedalsTable::operator[](const char* country)
{
    int idx{ findCountry(country) };
    if (idx == -1)
    {
        /*assert(size < MedalsTable::maxSize and
            "Table is FULL!");*/
        /*idx = size++;
        medalRows[idx].setCountry(country);*/
        if (medalRows == nullptr) {
            idx = size++;
            medalRows = new MedalRow[size];
            medalRows[idx].setCountry(country);
            
        }
        else {
            MedalRow* temp = new MedalRow[size];
            for (int i = 0; i < size; i++) {
                temp[i] = medalRows[i];
            }
            delete[]medalRows;
            size++;
            medalRows = new MedalRow[size];
            for (int i = 0; i < size - 1; i++) {
                medalRows[i] = temp[i];
            }
            delete[]temp;
            idx = size - 1;
            medalRows[idx].setCountry(country);
        }
    }
    return medalRows[idx];
}

const MedalRow& MedalsTable::operator[](const char* country) const
{
    int idx{ findCountry(country) };
    assert(idx != -1 and "Country not found on const "
        "table");
    return medalRows[idx];
}

void MedalsTable::print() const
{
    for (int i{ 0 }; i < size; ++i)
    {
        medalRows[i].print();
    }
}

MedalsTable MedalsTable::operator()(const char* country)const
{
    int num = findCountry(country);
    if (num == -1) {
        cout << "No such country has been found" << endl;
    }
    else {
        int gold, silver, bronze, res;

        gold = medalRows[num].getMedal(0);
        silver = medalRows[num].getMedal(1);
        bronze = medalRows[num].getMedal(2);

        if (gold < silver) {
            if (silver < bronze) {
                cout << country <<"\tBronze - " << bronze;
            }
            else {
                cout << country << "\tSilver - " << silver;
            }
        }
        else {
            if (gold < bronze) {
                cout << country << "\tBronze - " << bronze;
            }
            else {
                cout << country << "\tGold - " << gold;
            }
        }
    }
    return *this;
}

ostream& operator<<(ostream& output, const MedalsTable& a)
{
    a.print();
    return output;
}
