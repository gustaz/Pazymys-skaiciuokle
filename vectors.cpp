#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
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

int main()
{
	srand(time(NULL));

	std::cout << "Atsakydami i programos uzduodamus klausimus rasykite raides T (-taip) arba N (-ne)."
		<< std::endl;

	std::vector<Studentas> studentai;
	char pasirinkimas;

	std::cout << "Ar norite nuskaityti duomenis is failo? (T/N): ";
	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	bool nuskaitytiDuomenys = false;
	bool skaitytiToliau = false;

	if(tolower(pasirinkimas) == 't')
	{
		readFromFile(studentai);
		nuskaitytiDuomenys = true;
		std::cout << "Failo duomenys nuskaityti. "
			<< std::endl;
	}
	if (nuskaitytiDuomenys)
	{
		std::cout << "Ar norite duomenis taip pat ivesti ranka? (T/N): ";
		std::cin >> pasirinkimas;
		checkInput(pasirinkimas);

		if (tolower(pasirinkimas) == 't')
			skaitytiToliau = true;
	}
	else
		std::cout << "Nepasirinkta duomenis skaityti is failo. Pereinama prie ivedimo rankiniu budu. "
			<< std::endl;

	while (skaitytiToliau || !nuskaitytiDuomenys)
	{
		std::cin.ignore();
		inputStudent(studentai);		

		std::cout << "Ar norite prideti dar viena studenta? (T/N): ";
		std::cin >> pasirinkimas;
		
		checkInput(pasirinkimas);

		if (tolower(pasirinkimas) == 'n')
			break;
	}
	std::cout << "Dabar yra suteikiama galimybe pasirinkti isvedima."
		<< std::endl;

	std::cout << "Ar norite, jog rezultatas butu vidurkis? "
		<< "Jei pasirinksite ne, bus rodoma mediana. (T/N): ";
	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	std::sort(studentai.begin(), studentai.end(), palyginimas());

	if (tolower(pasirinkimas) == 't')
	{
		std::cout << std::left
			<< std::setw(20) << "Pavarde"
			<< std::setw(15) << "Vardas"
			<< std::setw(10) << "Galutinis (Vid.)"
			<< std::endl
			<< std::string(65, '-')
			<< std::endl;

		for (int i = 0; i < studentai.size(); i++)
		{
			double avg = 0;

			for (int j = 0; j < studentai[i].nd.size(); j++)
				avg += studentai[i].nd[j];

			avg = avg / studentai[i].nd.size();
			avg = 0.4 * avg + 0.6 * studentai[i].egzaminas;
			
			std::cout << std::left
				<< std::setw(20) << studentai[i].pavarde
				<< std::setw(15) << studentai[i].vardas
				<< std::setw(15) << std::fixed << std::setprecision(2) << avg
				<< std::endl;
		}
	}
	else
	{
		std::cout << std::left
			<< std::setw(20) << "Pavarde"
			<< std::setw(15) << "Vardas"
			<< std::setw(10) << "Galutinis (Med.)"
			<< std::endl
			<< std::string(65, '-')
			<< std::endl;

		for (int i = 0; i < studentai.size(); i++)
		{
			std::sort(studentai[i].nd.begin(), studentai[i].nd.end());

			double median = 0;

			if (studentai[i].nd.size() % 2 == 1)
				median = studentai[i].nd[studentai[i].nd.size() / 2];

			else median = ((double)studentai[i].nd[studentai[i].nd.size() / 2] + (double)studentai[i].nd[studentai[i].nd.size() / 2 - 1]) / 2;

			double final = median * 0.4 + studentai[i].egzaminas * 0.6;
			std::cout << std::left
				<< std::setw(20) << studentai[i].pavarde
				<< std::setw(15) << studentai[i].vardas
				<< std::setw(15) << std::fixed << std::setprecision(2) << final
				<< std::endl;
		}

	}
	WINPAUSE;
}

void readFromFile(std::vector<Studentas>& studentai)
{
	Studentas student;

	std::ifstream input;

	int pasirinkimas;

	std::cout << "Pasirinkite, kuri faila norite skaityti: "
		<< std::endl << "(1) studentai10000.txt"
		<< std::endl << "(2) studentai100000.txt"
		<< std::endl << "(3) studentai1000000.txt"
		<< std::endl << "(4) sortdemo.txt"
		<< std::endl << "(5) kursiokai.txt"
		<< std::endl;

	std::cout << "Jusu pasirinkimas: ";
	std::cin >> pasirinkimas;

	while (true)
	{
		switch (pasirinkimas)
		{
		case 1:
			input.open("studentai10000.txt");
			break;
		case 2:
			input.open("studentai100000.txt");
			break;
		case 3:
			input.open("studentai1000000.txt");
			break;
		case 4:
			input.open("sortdemo.txt");
			break;
		case 5:
			input.open("kursiokai.txt");
			break;
		default:
			{
			std::cout << "Ivedete klaidinga reiksme! Pasirinkite skaiciu nuo 1 iki 4: ";
			std::cin >> pasirinkimas;
			continue;
			}
		}
		break;
	}


	input.ignore(256, '\n');

	while (!input.eof())
	{
		std::string line, vardas, pavarde;
		
		input >> vardas >> pavarde;
		getline(input, line);

		std::stringstream stream(line);
		std::vector<int> values;

		int n;
		while (stream >> n)
				values.push_back(n);

		values.pop_back();
		student.egzaminas = n;
		student.nd = values;
		student.vardas = vardas;
		student.pavarde = pavarde;
		studentai.push_back(student);
	}
	input.close();
}

void inputStudent(std::vector<Studentas>& studentai) 
{
	Studentas stud;	
	char pasirinkimas;
	int n;

	std::cout << "Iveskite studento varda: ";
	getline(std::cin, stud.vardas);

	std::cout << "Iveskite studento pavarde: ";
	getline(std::cin, stud.pavarde);

	std::cout << "Pradedami ivesti studento " << stud.vardas << " " << stud.pavarde << " duomenys."
		<< std::endl
			<< "Ar zinomas tikslus atliktu namu darbu skaicius? (T/N): ";

	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	if (tolower(pasirinkimas) == 't')
	{
		std::cout << "Iveskite studento atliktu namu darbu skaiciu: ";
		std::cin >> n;
		checkInput(n, false);

		std::cout << "Dabar yra suteikiama galimybe pasirinkti ivedima."
			<< " Duomenys vedami arba ranka, arba generuojami atsitiktinai."
				<< std::endl
					<< "Ar norite duomenis generuoti atsitiktinai? (T/N): ";
		
		std::cin >> pasirinkimas;
		checkInput(pasirinkimas);

		if (tolower(pasirinkimas) == 't')
		{
			std::cout << "Pasirinkta duomenis generuoti atsitiktine tvarka.";

			for (int i = 0; i < n; i++)
				stud.nd.push_back(rand() % 10 + 1);

			stud.egzaminas = rand() % 10 + 1;

			std::cout << std::endl
				<< "Gauti pazymiai: ";
			for (int i = 0; i < stud.nd.size(); i++)
				std::cout << stud.nd[i] << " ";

			std::cout << std::endl
				<< "Gautas egzamino ivertinimas: "
					<< stud.egzaminas
						<< std::endl;
		}
		else if (tolower(pasirinkimas) == 'n')
		{
			std::cout << "Pasirinktas duomenu ivedimas ranka." <<
				std::endl;

			for (int i = 0; i < n; i++)
			{
				int ivestis;
				std::cout << "Iveskite " << i + 1 << "-aji pazymi: ";
				std::cin >> ivestis;
				checkInput(ivestis, true);
				stud.nd.push_back(ivestis);
			}
			std::cout << "Iveskite egzamino pazymi: ";
			std::cin >> stud.egzaminas;
			checkInput(stud.egzaminas, true);

			std::cout << "Baigtas duomenu ivedimas." 
				<< std::endl;
		}
	}
	else if (tolower(pasirinkimas) == 'n')
	{
		std::cout << "Kadangi studento namu darbu skaicius nezinomas,"
			<< " atliekama ivestis rankiniu budu."
			<< std::endl;

		std::cout << "Noredami nutraukti pazymiu ivedima, pazymi suveskite 0."
			<< std::endl;

		while (true)
		{
			int ivestis;
			std::cout << "Iveskite " << stud.nd.size() + 1 << "-aji pazymi: ";
			std::cin >> ivestis;
			checkInput(ivestis, true);

			if (ivestis == 0 && stud.nd.size() > 0)
			{
				std::cout << "Iveskite egzamino pazymi: ";
				std::cin >> stud.egzaminas;
				checkInput(stud.egzaminas, true);
				break;
			}
			else if (ivestis == 0 && stud.nd.size() == 0)
				std::cout << "Studentas turi tureti bent viena pazymi!"
					<< std::endl;

			stud.nd.push_back(ivestis);
		}
	}
	studentai.push_back(stud);	
}

void checkInput(int &skaicius, bool limited) 
{
	while (std::cin.fail() || skaicius < 0 || skaicius > 10) 
	{
		if(std::cin.fail()) 
			std::cout 
				<< "Ivedete reiksme, netenkinancia salygos! (Gal netycia vietoje skaiciaus ivedete raide?)" 
					<< std::endl;

		else if (skaicius <= 0)
			std::cout
				<< "Ivedete reiksme, netenkinancia salygos! (Skaicius negali buti mazesne uz 0!)"
					<< std::endl;
		else if (skaicius > 10)
		{
			if (!limited) break;

			std::cout
				<< "Ivedete reiksme, netenkinancia salygos! (Skaicius negali buti didesnis uz 10!)"
					<< std::endl;
		}
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Pakartokite ivedima: ";
		std::cin >> skaicius;
	}
}

void checkInput(char& ivestis) 
{
	while (std::cin.fail() || tolower(ivestis) != 't' && tolower(ivestis) != 'n')
	{
		if (std::cin.fail())
			std::cout
				<< "Ivedete reiksme, netenkinancia salygos! (Gal netycia vietoje raides ivedete skaiciu?)"
					<< std::endl;
		else if(tolower(ivestis) != 't' && tolower(ivestis) != 'n')
			std::cout
				<< "Atsakydami i programos uzduodamus klausimus rasykite raides T (-taip) arba N (-ne)!"
				<< std::endl;

		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Pakartokite ivedima: ";
		std::cin >> ivestis;
	}
}