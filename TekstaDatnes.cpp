// Izstrādāt mācību materiālu un elektronisko testu par tēmu "Darbs ar teksta datnēm programmēšanas valodā C++".
// Tests satur 10 jautājumus (izstrāde notiek programmēšanas valodā C++),
// katram jautājumam 4 atbilžu varianti, no kuriem pareizi 2 vai 3 atbilžu varianti.
// Jautājumi un jautājumu atbildes tiek nolasītas no teksta datnes.
// Lietotājs atbild uz katru jautājumu 1 reizi un saņem tūlītēju novērtējumu, vai atbilde pareiza vai nepareiza.
//  Beigās paziņo, cik jautājumi atbildēti pareizi. Pareizo un nepareizo atbilžu skaits tiek saglabāts teksta datnē.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct jautajums {
    string teksts;
    vector <string> iespejas;
};
struct cilveks{
    string vards;
    int rezultats;
};