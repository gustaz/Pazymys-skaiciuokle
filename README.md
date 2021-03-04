# Pažymių skaičiuoklė

## Funkcijos
* Leidžia vartotojui įvesti studento vardą, pavardę;
* Duoda galimybę pasirinkti, ar žinomas atsiskaitytų namų darbų kiekis;
* Jei taip, leidžia pažymius įvesti arba sugeneruoti atsitiktinai;
* Jei ne, suteikia galimybę vartotojui pačiam įrašyti tiek įvertinimų, kiek jis nori.

## Programos diegimas
PIRMASIS BŪDAS
1. Parsisiųsti .exe vykdomąjį failą ir, rekomenduojama tik patikrinus, jog jo MD5 hash atitinka, paleisti.

ANTRASIS BŪDAS
1. Parsisiųsti norimą programos versijos kodą iš releases;
2. Kodą sukompiliuoti per komandinę eilutę arba pasirinktą IDE;
```sh
g++ vectors.cpp functions.cpp -o skaiciuokle
.\skaiciuokle
```
3. Gautą vykdomąjį failą paleisti.
	
## Programos naudojimas
Naudojimas
1. Paleidus vykdomąjį failą atidaromas komandinės eilutės langas ir vartotojas gali naviguoti laikydamasis programos numatytos eigos.
2. Leidžiama pasirinkti, ar vartotojas nori įvedimą daryti iš failo. 
3. Baigus ar nepasirinkus įvedimą iš failo taip pat galima pasirinkti ir įvedimą rankiniui būdu. Įvedus vardą, pavardę, duodama pasirinkti pažymių įvedimo būdą (generacija, įvedimas rankiniu būdu).
4. Suvedus visus duomenis vartotojo paklausiama, ar jis nori pridėti dar vieną studentą. Jei taip, kartojami žingsniai 1-3.
5. Jei ne, paklausiama, ar vartotojas nori matyti vidurkį, ar medianą.
6. Pagal atitinkamą vartotojo pasirinkimą parodoma lentelė su įvestų studentų duomenimis.
	
## Versijos
* [v0.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.1) Įgyvendintas esminis funkcionalumas
* [v0.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.2) Pridėta galimybė duomenis skaityti iš failo, duomenis rikiuoti
* [v0.3](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.3) Programa išskaidyta į funckijų ir į pagrindinį failą, sukurtas antraščių failas, pridėtas klaidos išvedimas neradus failo.
* [v0.4](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4) Kodas optimizuotas, pridėtas studentų grupavimas į dvi kategorijas ir išvedimas į failus.
* [v0.4.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.1) Pridėtas dar vienas skaičiavimų trukmės išvedimas, įvedimas ir išvedimas perkelti į subaplankalus tam, kad palaikyti tvarką.
