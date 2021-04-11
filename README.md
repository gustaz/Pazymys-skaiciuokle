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
g++ main.cpp functions.cpp -o skaiciuokle
```
3. Gautą vykdomąjį failą paleisti:
    1. Naudojant paleidimo argumentus:
        1. vector - Darbui su vector konteineriu;
        2. deque - Darbui su deque konteineriu;
        3. list - Darbui su list konteineriu;
        4. generate - Failu sugeneravimui vykdyti;
    2. Nenaudojant paleidimo argumentu programa pereis prie iprastines, ne spartos bandymams vykdyti, veiklos.
	
## Programos naudojimas
Naudojimas
1. Paleidus vykdomąjį failą programa tikrina, ar yra paleidimo parametrai. 
2. Jei parametrai neįvedami, programa pereina prie įprastinės veiklos.
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


| **Vector**                            | 1 000    | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| ------------------------------------- | -------- | ------ | ------- | --------- | ---------- |
| Bendras vykdymo laikas                | 0.050s   | 0.191s | 1.732s  | 18.523s   | 191.880s   |
| Nuskaitymas                           | 0.021s   | 0.115s | 1.120s  | 11.738s   | 114.629s   |
| Išrūšiavimas                          | 0.002s   | 0.030s | 0.407s  |  4.865s   |  58.336s   |
| Išvedimas                             | 0.026s   | 0.044s | 0.204s  |  1.919s   |  18.882s   |

| **Deque**                             | 1 000    | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| ------------------------------------- | -------- | ------ | ------- | --------- | ---------- |
| Bendras vykdymo laikas                | 0.034s   | 0.193s | 1.875s  | 19.673s   | 207.906s   |
| Nuskaitymas                           | 0.011s   | 0.112s | 1.181s  | 11.435s   | 114.040s   |
| Išrūšiavimas                          | 0.003s   | 0.040s | 0.487s  |  6.255s   |  74.644s   |
| Išvedimas                             | 0.019s   | 0.040s | 0.207s  |  1.981s   |  19.221s   |

| **List**                              | 1 000    | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| ------------------------------------- | -------- | ------ | ------- | --------- | ---------- |
| Bendras vykdymo laikas                | 0.034s   | 0.169s | 1.616s  | 16.964s   | 180.331s   |
| Nuskaitymas                           | 0.011s   | 0.116s | 1.130s  | 11.553s   | 116.246s   |
| Išrūšiavimas                          | 0.001s   | 0.015s | 0.254s  |  3.320s   |  44.200s   |
| Išvedimas                             | 0.020s   | 0.037s | 0.230s  |  2.090s   |  19.883s   |

AMD Ryzen 5-3550H, 2.1GHz Quad-core, 16GB DDR4 2333MHz RAM, NVMe SSD.

## Programoje esančių dviejų strategijų spartos tikrinimas

| ***Vector***             | 1 000   | 10 000  | 100 000   | 1 000 000  | 10 000 000   |
| ------------------------ | ------- | ------- | --------- | ---------- | ------------ |
| **Atminties naudojimas** |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.093MB | 0.136MB |  8.544MB  | 83.756MB   |   838.762MB  |
| Dviejų konteinerių       | 0.144MB | 3.525MB | 23.609MB  | 263.655MB  |  2297.112MB  |
| Skirtumas                | 0.051MB | 3.389MB | 15.065MB  | 179.899MB  |  1458.350MB  |
|                          |         |         |           |            |              |
| **Laiko naudojimas**     |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.002s  | 0.037s  | 0.413s    | 5.188s     |  71.450s     |
| Dviejų konteinerių       | 0.001s  | 0.032s  | 0.302s    | 3.918s     |  43.976s     |
| Skirtumas                | 0.001s  | 0.005s  | 0.111s    | 1.270s     |  24.474s     |

| ***Deque***              | 1 000   | 10 000  | 100 000   | 1 000 000  | 10 000 000   |
| ------------------------ | ------- | ------- | --------- | ---------- | ------------ |
| **Atminties naudojimas** |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.121MB | 0.625MB | 10.746MB  | 88.343MB   |   873.031MB  |
| Dviejų konteinerių       | 0.250MB | 2.125MB | 30.089MB  | 218.039MB  |  2120.707MB  |
| Skirtumas                | 0.129MB | 1.500MB | 19.343MB  | 129.695MB  |  1247.675MB  |
|                          |         |         |           |            |              |
| **Laiko naudojimas**     |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.0023s | 0.057s  | 0.719s    | 6.222s     |  79.265s     |
| Dviejų konteinerių       | 0.0028s | 0.043s  | 0.653s    | 5.669s     |  72.471s     |
| Skirtumas                | 0.0005s | 0.014s  | 0.066s    | 0.553s     |   6.794s     |

| ***List***               | 1 000   | 10 000  | 100 000   | 1 000 000  | 10 000 000   |
| ------------------------ | ------- | ------- | --------- | ---------- | ------------ |
| **Atminties naudojimas** |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.101MB | 0.781MB | 10.539MB  |  99.308MB  |   977.425MB  |
| Dviejų konteinerių       | 0.242MB | 2.312MB | 24.750MB  | 239.164MB  |  2355.082MB  |
| Skirtumas                | 0.141MB | 1.531MB | 14.210MB  | 139.855MB  |  1377.656MB  |
|                          |         |         |           |            |              |
| **Laiko naudojimas**     |         |         |           |            |              |
|                          |         |         |           |            |              |
| Vieno konteinerio        | 0.0015s | 0.022s  | 0.255s    | 3.568s     |  59.181s     |
| Dviejų konteinerių       | 0.0011s | 0.011s  | 0.139s    | 1.468s     |  18.419s     |
| Skirtumas                | 0.0004s | 0.011s  | 0.116s    | 2.100s     |  40.762s     |

**IŠVADA**: Vieno konteinerio metodas yra brangesnis laiko atžvilgiu, tačiau sunaudoja *žymiai* mažiau atminties. Atsižvelgus į poreikius vienas algoritmas už kitą pranašesnis.

Vieno konteinerio metodas išlošia tada, kai laikas nėra svarbu, o atmintis - ribota.
Dviejų konteinerių metodas išlošia priešingu atveju - kai laikas svarbu ir atmintis - nėra ribota.

## Po std::stable_partition optimizacijos metodo pritaikymo vykdytas spartos tikrinimas

*Jei prie skirtumo parašyta +, tai reiškia, jog pritaikytas optimizacijos metodas naudojo papildomai resursų.*
*Jei prie skirtumo parašyta -, tai reiškia, jog pritaikytas optimizacijos metodas naudojo mažiau resursų.*

| ***Vector***                                     | 1 000      | 10 000   | 100 000   | 1 000 000   | 10 000 000   |
| ------------------------------------------------ | ---------- | -------- | --------- | ----------- | ------------ |
| **Atminties naudojimas**                         |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         |  0.109MB   | 0.625MB  |  6.242MB  |  62.324MB   |   623.113MB  |
| Skirtumas palyginus su vieno konteinerio metodu  | +0.016MB   | +0.489MB | -2.302MB  | -25.432MB   |  -215.649MB  |
|                                                  |            |          |           |             |              |
| **Laiko naudojimas**                             |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         | 0.001s     | 0.032s   | 0.281s    | 3.513s      |  43.847s     |
| Skirtumas palyginus su dviejų konteinerių metodu | 0.000s     | 0.000s   | -0.021s   | -0.405s     |  -0.129s     |

| ***Deque***                                      | 1 000      | 10 000   | 100 000   | 1 000 000   | 10 000 000   |
| ------------------------------------------------ | ---------- | -------- | --------- | ----------- | ------------ |
| **Atminties naudojimas**                         |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         | 0.500MB    | 0.515MB  |  5.895MB  |  39.382MB   |    43.328MB  |
| Skirtumas palyginus su vieno konteinerio metodu  | +0.379MB   | -0.11MB  | -4.851MB  | -48.961MB   |  -829.703MB  |
|                                                  |            |          |           |             |              |
| **Laiko naudojimas**                             |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         | 0.0029s    | 0.050s   | 0.368s    | 5.513s      |  67.559s     |
| Skirtumas palyginus su dviejų konteinerių metodu | +0.006s    | +0.007s  | -0.285s   | -0.156s     |  -11.706s    |

| ***List***                                       | 1 000      | 10 000   | 100 000   | 1 000 000   | 10 000 000   |
| ------------------------------------------------ | ---------- | -------- | --------- | ----------- | ------------ |
| **Atminties naudojimas**                         |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         | 0.121MB    | 0.750MB  | 12.371MB  |  20.433MB   |    65.132MB  |
| Skirtumas palyginus su vieno konteinerio metodu  | +0.020MB   | +0.031MB | +1.832MB  | -78.875MB   |  -912.293MB  |
|                                                  |            |          |           |             |              |
| **Laiko naudojimas**                             |            |          |           |             |              |
|                                                  |            |          |           |             |              |
| Taikant stable_partition                         | 0.00008s   |  0.009s  |   0.126s  |    1.319s   |     14.409s  |
| Skirtumas palyginus su dviejų konteinerių metodu | -0.00102s  |  -0.002s |   -0.013s |    -0.149s  |     -4.01s   |

**IŠVADA**: std::stable_partition iš esmės programai suteikė spartą, kuri buvo gaunama naudojant du konteinerius ir suteikė tą patį atminties optimizuotumą, kaip ir vieno konteinerio metodas. Kai kuriais atvejais efektyvumas padidėjo netgi drastiškai, nes implementaicja pakeista iš template funkcijos, iteruojančios pro visą konteinerį, kuri buvo tam tikrais atvejais neefektyvi.
	
## Versijos
* [v0.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.1) Įgyvendintas esminis funkcionalumas
* [v0.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.2) Pridėta galimybė duomenis skaityti iš failo, duomenis rikiuoti
* [v0.3](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.3) Programa išskaidyta į funckijų ir į pagrindinį failą, sukurtas antraščių failas, pridėtas klaidos išvedimas neradus failo.
* [v0.4](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4) Kodas optimizuotas, pridėtas studentų grupavimas į dvi kategorijas ir išvedimas į failus.
* [v0.4.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.1) Pridėtas dar vienas skaičiavimų trukmės išvedimas, įvedimas ir išvedimas perkelti į subaplankalus tam, kad būtų palaikoma tvarka.
* [v0.4.2](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.4.2) Pridėtas spartos tikrinimo kelias,  kodo refaktorizacija ir optimizavimas.
* [v0.5](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v0.5) Pridėtas funkcionalumas su deque ir list, perėjimas prie template funkcijų, pridėti paleidimo argumentai.
* [v1.0.1](https://github.com/gustaz/Pazymys-skaiciuokle/releases/tag/v1.0.1) Pridėtas dviejų algoritmų tikrinimas lyginant jų atminties ir laiko sąnaudas. Dėl atminties tikrinimo algoritmo, ši versija tinka tik Windows operacinę sistemą naudojantiems vartotojams.
