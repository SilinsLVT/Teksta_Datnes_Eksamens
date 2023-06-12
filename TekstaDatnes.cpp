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

vector<jautajums> jautajumuielade(const string& failiN){
    vector<jautajums> jautajumi;
    ifstream fails(failiN);
    if (fails.is_open()){
        string rinda;
        while (getline(fails,rinda)){
            jautajums jautajums;
            jautajums.teksts = rinda;
            getline(fails,rinda);
            size_t pozicija = 0;
            string atstarpe = "  ";
            while((pozicija = rinda.find(atstarpe)) != string::npos){
                string iespeja = rinda.substr(0,pozicija);
                jautajums.iespejas.push_back(iespeja);
                rinda.erase(0,pozicija + atstarpe.length());
            }
            jautajums.iespejas.push_back(rinda);
            jautajumi.push_back(jautajums);
        }
        fails.close();
    }
    return jautajumi;
}