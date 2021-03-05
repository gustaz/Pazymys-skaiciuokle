#include "declarations.h"
double accumulatedTime = 0;

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

	std::cout << "Vykdomas galutiniu ivertinimu skaiciavimas." << std::endl;
	clockStart = std::chrono::steady_clock::now();
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
	std::cout << "Galutiniu ivertinimu skaiciavimas truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl;
	accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();

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

		try {

			int dir = _mkdir("data");

			if (dir == 0)
				std::cout << "Sukurta direktorija data." << std::endl;
			else
				if (dir != 0 && errno == EEXIST)
				{
					std::cout << "Direktorija data jau egzistuoja. Nieko nedaroma." << std::endl;
				}
				else throw(1);

			dir = _mkdir("data/output");

			if (dir == 0)
				std::cout << "Sukurta subdirektorija data/output." << std::endl;
			else
				if (dir != 0 && errno == EEXIST)
				{
					std::cout << "Subdirektorija data/output jau egzistuoja. Nieko nedaroma." << std::endl;
				}
				else throw(1);
		}
		catch (int err)
		{
			std::cout << "Ivyko klaida aplankalu kurimo metu! Programa nutraukia veikla.";
			exit(1);
		}

		if (tolower(pasirinkimas) == 't')
		{
			clockStart = std::chrono::steady_clock::now();
			for (int i = 0; i < studentai.size(); i++)
			{
				if (studentai[i].galutinisVid >= 5.00)
					kietiakai.push_back(studentai[i]);
				else
					vargsiukai.push_back(studentai[i]);
			}
			std::cout << "Rusiavimas truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl
				<< "Rusiavimas baigtas!" << std::endl;
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
			clockStart = std::chrono::steady_clock::now();
			std::ofstream output;

			output.open("data/output/kietiakai.txt");
			writeToConsoleAvg("(Vid.)", kietiakai, output);
			output.close();

			output.open("data/output/vargsiukai.txt");
			writeToConsoleAvg("(Vid.)", vargsiukai, output);
			output.close();

			std::cout << "Isvestis truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl
				<< "Isvestis i faila baigta!";
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
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
			std::cout << "Rusiavimas truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl
				<< "Rusiavimas baigtas!" << std::endl;
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
			
			clockStart = std::chrono::steady_clock::now();
			std::ofstream output;

			output.open("data/output/kietiakai.txt");
			writeToConsoleAvg("(Med.)", kietiakai, output);
			output.close();

			output.open("data/output/vargsiukai.txt");
			writeToConsoleAvg("(Med.)", vargsiukai, output);
			output.close();

			std::cout << "Isvestis truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl
			<< "Isvestis i failus baigta!";
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
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
			writeToConsoleAvg("(Vid.)", studentai, std::cout);
			std::cout << "Israsymas truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl;
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
		}
		if (tolower(pasirinkimas) == 'n')
		{
			clockStart = std::chrono::steady_clock::now();
			writeToConsoleMed("(Med.)", studentai, std::cout);
			std::cout << "Israsymas truko: " << std::fixed << std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count() << "s" << std::endl;
			accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
		}
	}
	std::cout << std::endl << "Galutinis vykdymas truko " << accumulatedTime << " s.";
}