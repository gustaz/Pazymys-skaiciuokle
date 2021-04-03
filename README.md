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
2. Leidžiama pasirinkti programos vykdymo eigą paleidžiant failą - programai davus parametrus vector, list, deque arba betkokią šių trijų kombinaciją bus vykdoma spartos tikrinimo eiga su būtent šių tipų konteineriais. Kitais atvejais, kai pasirenkami netinkami parametrai arba jie nepasirenkami, programa pereina prie įprastos vykdymo eigos.
3. Pasirinkus spartos tikrinimo eigą, nieko daryti nereikia - programa pati automatiškai toliau viską atliks.
4. Pasirinkus įprastinę tvarką leidžiama pasirinkti, ar norima generuoti duomenis.
6. Vėliau leidžiama pasirinkti, ar vartotojas nori įvedimą daryti iš failo. 
7. Baigus ar nepasirinkus įvedimą iš failo taip pat galima pasirinkti ir įvedimą rankiniui būdu. Įvedus vardą, pavardę, duodama pasirinkti pažymių įvedimo būdą (generacija, įvedimas rankiniu būdu).
8. Suvedus visus duomenis vartotojo paklausiama, ar jis nori pridėti dar vieną studentą. Jei taip, kartojami žingsniai 7-8.
9. Jei ne, vartotojo paklausiama, ar jis nori išvestį išskirti į du failus.
10. Pasirinkus taip, išvestis pateikiama dvejuose failuose, pagal pasirinkimą rodomas galutinis pažymys paskaičiuotas su vidurkiu arba mediana.
11. Jei ne, išvestis vykdoma komandinėje eilutėje ir taip pat pagal pasirinkimą rodomas galutinis pažymys paskaičiuotas su vidurkiu arba mediana.
12. Pagal atitinkamą vartotojo pasirinkimą parodoma lentelė komandinėje eilutėje arba pateikiama išvestis.

## Programos spartos įvertinimas

| Konteineris                           | 1 000    | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| ------------------------------------- | -------- | ------ | ------- | --------- | ---------- |
| **Vector** (bendras vykdymo laikas)   | 0.050s   | 0.191s | 1.732s  | 18.523s   | 191.880s   |
| Nuskaitymas                           | 0.021s   | 0.115s | 1.120s  | 11.738s   | 114.629s   |
| Išrūšiavimas                          | 0.002s   | 0.030s | 0.407s  |  4.865s   |  58.336s   |
| Išvedimas                             | 0.026s   | 0.044s | 0.204s  |  1.919s   |  18.882s   |
|                                       |          |        |         |           |            |
| **Deque** (bendras vykdymo laikas)    | 0.034s   | 0.193s | 1.875s  | 19.673s   | 207.906s   |
| Nuskaitymas                           | 0.011s   | 0.112s | 1.181s  | 11.435s   | 114.040s   |
| Išrūšiavimas                          | 0.003s   | 0.040s | 0.487s  |  6.255s   |  74.644s   |
| Išvedimas                             | 0.019s   | 0.040s | 0.207s  |  1.981s   |  19.221s   |
|                                       |          |        |         |           |            |
| **List** (bendras vykdymo laikas)     | 0.034s   | 0.169s | 1.616s  | 16.964s   | 180.331s   |
| Nuskaitymas                           | 0.011s   | 0.116s | 1.130s  | 11.553s   | 116.246s   |
| Išrūšiavimas                          | 0.001s   | 0.015s | 0.254s  |  3.320s   |  44.200s   |
| Išvedimas                             | 0.020s   | 0.037s | 0.230s  |  2.090s   |  19.883s   |

AMD Ryzen 5-3550H, 2.1GHz Quad-core, 16GB DDR4 2333MHz RAM, NVMe SSD.
	
## Versijos
* [v0.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.1) Įgyvendintas esminis funkcionalumas
* [v0.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.2) Pridėta galimybė duomenis skaityti iš failo, duomenis rikiuoti
* [v0.3](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.3) Programa išskaidyta į funckijų ir į pagrindinį failą, sukurtas antraščių failas, pridėtas klaidos išvedimas neradus failo.
* [v0.4](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4) Kodas optimizuotas, pridėtas studentų grupavimas į dvi kategorijas ir išvedimas į failus.
* [v0.4.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.1) Pridėtas dar vienas skaičiavimų trukmės išvedimas, įvedimas ir išvedimas perkelti į subaplankalus tam, kad būtų palaikoma tvarka.
* [v0.4.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.2) Pridėtas spartos tikrinimo kelias,  kodo refaktorizacija ir optimizavimas.
* [v0.5](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.5) Pridėtas funkcionalumas su deque ir list, perėjimas prie template funkcijų, pridėti paleidimo argumentai.
