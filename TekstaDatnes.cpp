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
#include <ctime>
#include <cstdlib>
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

int lietotajaAtb(){
    int atbilde;
    cout<<"Ievadi, pēc savām domām, pareizo atbildi (1-4): ";

    while(true){
        string ievade;
        getline(cin >> ws, ievade);

        if(ievade.length()== 1 && ievade[0] >= '1' && ievade[0] <= '4'){
            atbilde = ievade[0] - '0';
            break;
        }
        cout<<"Nederīga atbilde, ievadi ciparu kas ir no 1 līdz 4: ";
    }
    return atbilde;
}

bool atbilzuparbaude(int lietotajaAtbilde1, int lietotajaAtbilde2){
    return(lietotajaAtbilde1 == 1 && lietotajaAtbilde2 == 2) || (lietotajaAtbilde1 == 2 && lietotajaAtbilde2 == 1);
}

int main(){

    srand(time(nullptr));
    vector<jautajums> jautajumi = jautajumuielade("jautajumi.txt");
    string speletajaVards;
    cout<<"Ievadiet savu vārdu! ";
    getline(cin >> ws,speletajaVards);
    int rezultats = 0;
    for(int i=0; i < 10; i++){
        system("clear");
        cout<< jautajumi[i].teksts << endl;
        for(int j=0; j<4; j++){
            cout << j+1 << ". "<< jautajumi[i].iespejas[j] << endl;
        }

        int lietotajaAtbilde1 = lietotajaAtb();
        int lietotajaAtbilde2;
        do{
            lietotajaAtbilde2 = lietotajaAtb();
        }while (lietotajaAtbilde2 == lietotajaAtbilde1);
        if(atbilzuparbaude(lietotajaAtbilde1,lietotajaAtbilde2)){
            rezultats += 2;
            cout<<"Pareizi!" << endl;
        }else if (lietotajaAtbilde1 == 1 || lietotajaAtbilde1 == 2 || lietotajaAtbilde2 == 1 || lietotajaAtbilde2 == 2){
            rezultats += 1;
            cout<<"Daļēji pareizi!" << endl;
        }else{
            cout<<"Nepareizi!" << endl;
        }
    }

}