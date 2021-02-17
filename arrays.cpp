#include <iostream>
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
	int n = 0;
	int* nd = 0;
	int egzaminas = 0;

};

void inputStudent(Studentas& studentai);
void checkInput(int& skaicius, bool limited);
void checkInput(char& ivestis);

int main()
{
	srand(time(NULL));

	std::cout << "Atsakydami i programos uzduodamus klausimus rasykite raides T (-taip) arba N (-ne)."
		<< std::endl;

	int studentu = 0;
	Studentas* studentai = new Studentas[studentu + 1];

	char pasirinkimas;

	while (true)
	{
		inputStudent(studentai[studentu]);

		studentu++;

		std::cout << "Ar norite prideti dar viena studenta? (T/N): ";
		std::cin >> pasirinkimas;
		std::cin.ignore();

		if (tolower(pasirinkimas) == 'n')
			break;
		else
		{
			Studentas* studentai_didesnis = new Studentas[studentu + 1];

			for (int i = 0; i < studentu; i++)
				studentai_didesnis[i] = studentai[i];

			delete[] studentai;
			studentai = studentai_didesnis;
		}			
	}
	
	std::cout << "Dabar yra suteikiama galimybe pasirinkti isvedima."
		<< std::endl;

	std::cout << "Ar norite, jog rezultatas butu vidurkis? "
		<< "Jei pasirinksite ne, bus rodoma mediana. (T/N): ";
	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	if (tolower(pasirinkimas) == 't')
	{
		std::cout << std::left
			<< std::setw(20) << "Pavarde"
			<< std::setw(15) << "Vardas"
			<< std::setw(10) << "Galutinis (Vid.)"
			<< std::endl
			<< std::string(65, '-')
			<< std::endl;

		for (int i = 0; i < studentu; i++)
		{
			double avg = 0;

			for (int j = 0; j < studentai[i].n; j++)
				avg += studentai[i].nd[j];

			avg /= studentai[i].n;
			avg = 0.4 * avg + 0.6 * studentai[i].egzaminas;
			
			std::cout << std::left
				<< std::setw(20) << studentai[i].pavarde
				<< std::setw(15) << studentai[i].vardas
				<< std::setw(15) << std::setprecision(2) << avg
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

		for (int i = 0; i < studentu; i++)
		{
			std::sort(studentai[i].nd, studentai[i].nd + studentai[i].n);

			double median = 0;

			if (studentai[i].n % 2 == 1)
				median = studentai[i].nd[studentai[i].n / 2];

			else median = ((double)studentai[i].nd[studentai[i].n / 2] + (double)studentai[i].nd[studentai[i].n / 2 - 1]) / 2;

			double final = median * 0.4 + studentai[i].egzaminas * 0.6;
			std::cout << std::left
				<< std::setw(20) << studentai[i].pavarde
				<< std::setw(15) << studentai[i].vardas
				<< std::setw(15) << std::fixed << std::setprecision(2) << final
				<< std::endl;
		}

	}
	delete[] studentai;
	WINPAUSE;
}

void inputStudent(Studentas& studentai) 
{
	std::string vardas, pavarde;
	int n = 0, egzaminas{};
	bool looped = false;

	int* nd = new int[n+1];
	char pasirinkimas;

	std::cout << "Iveskite studento varda: ";
	getline(std::cin, vardas);

	std::cout << "Iveskite studento pavarde: ";
	getline(std::cin, pavarde);

	std::cout << "Pradedami ivesti studento " << vardas << " " << pavarde << " duomenys."
		<< std::endl
			<< "Ar zinomas tikslus atliktu namu darbu skaicius? (T/N): ";

	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	if (tolower(pasirinkimas) == 't')
	{
		std::cout << "Iveskite studento atliktu namu darbu skaiciu: ";
		std::cin >> n;
		checkInput(n, false);

		delete[] nd;
		nd = new int[n];

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
				nd[i] = rand() % 10 + 1;

			egzaminas = rand() % 10 + 1;

			std::cout << std::endl
				<< "Gauti pazymiai: ";
			for (int i = 0; i < n; i++)
				std::cout << nd[i] << " ";

			std::cout << std::endl
				<< "Gautas egzamino ivertinimas: "
					<< egzaminas
						<< std::endl;
		}
		else if (tolower(pasirinkimas) == 'n')
		{
			std::cout << "Pasirinktas duomenu ivedimas ranka." <<
				std::endl;

			for (int i = 0; i < n; i++)
			{
				std::cout << "Iveskite " << i + 1 << "-aji pazymi: ";
				std::cin >> nd[i];
				checkInput(nd[i], true);
			}

			std::cout << "Iveskite egzamino pazymi: ";
			std::cin >> egzaminas;
			checkInput(egzaminas, true);

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
			std::cout << "Iveskite " << n + 1 << "-aji pazymi: ";
			std::cin >> nd[n];
			checkInput(nd[n], true);

			if (nd[n] == 0 && n > 0)
			{
				std::cout << "Iveskite egzamino pazymi: ";
				std::cin >> egzaminas;
				checkInput(egzaminas, true);
				break;
			}
				
			else if (nd[n] == 0 && n == 0)
				std::cout << "Studentas turi tureti bent viena pazymi!"
					<< std::endl;

			else
			{
				n++;

				int* nd_didesnis = new int[n + 1];

				for (int i = 0; i < n; i++)
					nd_didesnis[i] = nd[i];

				delete[] nd;
				nd = nd_didesnis;
			}

		}

	}

	studentai.vardas = vardas;
	studentai.pavarde = pavarde;
	studentai.n = n;
	studentai.nd = nd;
	studentai.egzaminas = egzaminas;
		
}

void checkInput(int &skaicius, bool limited) {

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

void checkInput(char& ivestis) {

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