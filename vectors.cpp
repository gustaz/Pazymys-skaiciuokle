#include "declarations.h"


int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::cout << "Atsakydami i programos uzduodamus klausimus rasykite raides T (-taip) arba N (-ne)."
		<< std::endl;

	std::vector<Studentas> studentai;
	char pasirinkimas;

	std::cout << "Ar norite vykdyti failu generacija? (T/N): ";
	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	if (tolower(pasirinkimas) == 't')
	{
		askForGeneration();
	}
	else std::cout << "Pasirinkta failu negeneruoti. " << std::endl;

	std::cout << "Ar norite nuskaityti duomenis is failo? (T/N): ";
	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	bool nuskaitytiDuomenys = false;
	bool skaitytiToliau = false;

	if (tolower(pasirinkimas) == 't')
	{
		readFromFile(studentai);
		nuskaitytiDuomenys = true;

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

	for (int i = 0; i < studentai.size(); i++)
	{
		double avg = 0;
		for (int j = 0; j < studentai[i].nd.size(); j++)
		{
			avg += studentai[i].nd[j];
		}
		avg /= studentai[i].nd.size();
		studentai[i].galutinisVid = 0.4 * avg + 0.6 * studentai[i].egzaminas;

		studentai[i].galutinisMed = findMedian(studentai[i].nd, studentai[i].nd.size()) * 0.4 + studentai[i].egzaminas * 0.6;
	}

	bool outputDone = false;
	std::cout << "Dabar yra suteikiama galimybe pasirinkti isvedima."
		<< std::endl;

	std::cout << "Ar norite, jog rezultatas butu skirstomas pagal galutini vidurki? "
		<< "Jei pasirinksite ne, jis bus neskirstomas. (T/N): ";

	std::cin >> pasirinkimas;
	checkInput(pasirinkimas);

	if (tolower(pasirinkimas) == 't')
	{
		std::vector<Studentas> kietiakai;
		std::vector<Studentas> vargsiukai;
		outputDone = true;

		std::cout << "Pasirinkote surusiavima ir isvesti i faila."
			<< std::endl << "Ar norite, jog rezultatas isvedamas butu pagal galutini ivertinima? "
			<< "Pasirinkus ne, bus skaiciuojama pagal mediana. (T/N): ";

		std::cin >> pasirinkimas;
		checkInput(pasirinkimas);
		if (tolower(pasirinkimas) == 't')
		{
			clockStart = std::chrono::steady_clock::now();
			for (int i = 0; i < studentai.size(); i++)
			{
				if (studentai[i].galutinisVid >= 5)
					kietiakai.push_back(studentai[i]);
				else
					vargsiukai.push_back(studentai[i]);
			}
			std::cout << "Rusiavimas truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << std::endl
				<< "Rusiavimas baigtas!" << std::endl;
			clockStart = std::chrono::steady_clock::now();
			std::ofstream output;

			output.open("kietiakai.txt");

			output << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Vid.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < kietiakai.size(); i++)
			{
				output << std::left
					<< std::setw(20) << kietiakai[i].pavarde
					<< std::setw(15) << kietiakai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << kietiakai[i].galutinisVid
					<< "\n";
			}

			output.close();

			output.open("vargsiukai.txt");

			output << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Vid.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < vargsiukai.size(); i++)
			{
				output << std::left
					<< std::setw(20) << vargsiukai[i].pavarde
					<< std::setw(15) << vargsiukai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << vargsiukai[i].galutinisVid
					<< "\n";
			}
			std::cout << "Isvestis truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << std::endl
				<< "Isvestis i faila baigta!";
		}
		if (tolower(pasirinkimas) == 'n')
		{
			clockStart = std::chrono::steady_clock::now();
			for (int i = 0; i < studentai.size(); i++)
			{
				if (studentai[i].galutinisMed >= 5)
					kietiakai.push_back(studentai[i]);
				else
					vargsiukai.push_back(studentai[i]);
			}
			std::cout << "Rusiavimas truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << std::endl
				<< "Rusiavimas baigtas!" << std::endl;
			clockStart = std::chrono::steady_clock::now();
			std::ofstream output;

			output.open("kietiakai.txt");

			output << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Med.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < kietiakai.size(); i++)
			{
				output << std::left
					<< std::setw(20) << kietiakai[i].pavarde
					<< std::setw(15) << kietiakai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << kietiakai[i].galutinisMed
					<< "\n";
			}

			output.close();

			output.open("vargsiukai.txt");

			output << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Med.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < vargsiukai.size(); i++)
			{
				output << std::left
					<< std::setw(20) << vargsiukai[i].pavarde
					<< std::setw(15) << vargsiukai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << vargsiukai[i].galutinisMed
					<< "\n";
			}

			output.close();
			std::cout << "Isvestis truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << std::endl
			<< "Isvestis i failus baigta!";
		}
	}

	if (tolower(pasirinkimas) == 'n' && !outputDone)
	{
		std::sort(studentai.begin(), studentai.end(), palyginimas());
		std::cout << "Pasirinkote paprasta isvesti i komandine eilute."
			<< std::endl << "Ar norite, jog rezultate butu rodomas vidurkis? "
			<< "Pasirinkus ne, bus rodoma mediana. (T/N): ";

		std::cin >> pasirinkimas;
		checkInput(pasirinkimas);

		

		if (tolower(pasirinkimas) == 't')
		{
			clockStart = std::chrono::steady_clock::now();
			std::cout << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Vid.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < studentai.size(); i++)
			{

				std::cout << std::left
					<< std::setw(20) << studentai[i].pavarde
					<< std::setw(15) << studentai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << studentai[i].galutinisVid
					<< "\n";
			}
			std::cout << "Israsymas truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << "\n";
		}
		if (tolower(pasirinkimas) == 'n')
		{
			clockStart = std::chrono::steady_clock::now();
			std::cout << std::left
				<< std::setw(20) << "Pavarde"
				<< std::setw(15) << "Vardas"
				<< std::setw(10) << "Galutinis (Med.) \n"
				<< std::string(65, '-')
				<< "\n";

			for (int i = 0; i < studentai.size(); i++)
			{
				std::cout << std::left
					<< std::setw(20) << studentai[i].pavarde
					<< std::setw(15) << studentai[i].vardas
					<< std::setw(15) << std::fixed << std::setprecision(2) << studentai[i].galutinisMed
					<< "\n";
			}
			std::cout << "Israsymas truko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - clockStart).count() << " ms" << "\n";

		}
	}
	std::cout << std::endl;
	WINPAUSE;
}