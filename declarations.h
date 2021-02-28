#ifndef DECLARATIONS_H
#define DECLLARATIONS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <functional>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

struct Studentas {

	std::string vardas, pavarde;
	std::vector<int> nd;
	int egzaminas = 0;

};

struct palyginimas
{
	inline bool operator() (const Studentas& struct1, const Studentas& struct2)
	{
		return (struct1.pavarde.compare(struct2.pavarde)) < 0;
	}
};

void readFromFile(std::vector<Studentas>& studentai);
void inputStudent(std::vector<Studentas>& studentai);
void checkInput(int& skaicius, bool limited);
void checkInput(char& ivestis);

#endif