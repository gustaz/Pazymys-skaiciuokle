# Pažymių skaičiuoklė

## Funkcijos
* Suteikia vartotojui galimybę pasirinkti tarp programos vykdymo įprasta tvarka ir programos vykdymo spartos tikrinimo tvarka;
* Generuoja įvestį, ją apdoroja, gali suskirstyti duotą įvestį pagal vidurkį į du atitinkamus išvesties failus;
* Pateikia veiksmų trukmės ataskaitas programą vykdant;
* Leidžia vartotojui įvesti studento vardą, pavardę;
* Duoda galimybę pasirinkti, ar žinomas atsiskaitytų namų darbų kiekis;
* Jei taip, leidžia pažymius įvesti arba sugeneruoti atsitiktinai;
* Jei ne, suteikia galimybę vartotojui pačiam įrašyti tiek įvertinimų, kiek jis nori.

## Programos diegimas
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
2. Leidžiama pasirinkti programos vykdymo eigą.
3. Pasirinkus spartos tikrinimo eigą, nieko daryti nereikia - programa pati automatiškai toliau viską atliks.
4. Pasirinkus įprastinę tvarką leidžiama pasirinkti, ar norima generuoti duomenis.
6. Vėliau leidžiama pasirinkti, ar vartotojas nori įvedimą daryti iš failo. 
7. Baigus ar nepasirinkus įvedimą iš failo taip pat galima pasirinkti ir įvedimą rankiniui būdu. Įvedus vardą, pavardę, duodama pasirinkti pažymių įvedimo būdą (generacija, įvedimas rankiniu būdu).
8. Suvedus visus duomenis vartotojo paklausiama, ar jis nori pridėti dar vieną studentą. Jei taip, kartojami žingsniai 7-8.
9. Jei ne, vartotojo paklausiama, ar jis nori išvestį išskirti į du failus.
10. Pasirinkus taip, išvestis pateikiama dvejuose failuose, pagal pasirinkimą rodomas galutinis pažymys paskaičiuotas su vidurkiu arba mediana.
11. Jei ne, išvestis vykdoma komandinėje eilutėje ir taip pat pagal pasirinkimą rodomas galutinis pažymys paskaičiuotas su vidurkiu arba mediana.
12. Pagal atitinkamą vartotojo pasirinkimą parodoma lentelė komandinėje eilutėje arba pateikiama išvestis.
	
## Versijos
* [v0.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.1) Įgyvendintas esminis funkcionalumas
* [v0.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.2) Pridėta galimybė duomenis skaityti iš failo, duomenis rikiuoti
* [v0.3](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.3) Programa išskaidyta į funckijų ir į pagrindinį failą, sukurtas antraščių failas, pridėtas klaidos išvedimas neradus failo.
* [v0.4](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4) Kodas optimizuotas, pridėtas studentų grupavimas į dvi kategorijas ir išvedimas į failus.
* [v0.4.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.1) Pridėtas dar vienas skaičiavimų trukmės išvedimas, įvedimas ir išvedimas perkelti į subaplankalus tam, kad būtų palaikoma tvarka.
* [v0.4.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.2) Pridėtas spartos tikrinimo kelias, kodo refaktorizacija ir optimizavimas.
