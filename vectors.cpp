#include "declarations.h"

int main()
{

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