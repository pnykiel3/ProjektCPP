#include "biblioteka.h"


Gracz::Gracz(std::string n, int pk){
    imie = n;
    punkty = pk;
    for (int i = 0; i < 10; ++i) {
        IDkat.push_back(std::to_string(i));
    }
    kat = {
            "przyroda", "lektury", "wiedza ogolna", "edukacja ekologiczna", "historia", "geografia", "jezyk angielski", "matematyka", "wiedza o spoleczenstwie", "gry i zabawy"
    };
    //1 PRZYRODA
    //2 LEKTURY
    //3 WIEDZA OGÓLNA
    //4 EDUKACJA EKOLOGICZNA
    //5 HISTORIA
    //6 GEOGRAFIA
    //7 JĘZYK ANGIELSKI
    //8 MATEMATYKA
    //9 WIEDZA O SPOŁECZEŃSTWIE
    //10 GRY I ZABAWY

}

Gracz::~Gracz() = default;

void Gracz::zmienImie() {
    std::cout << "Jak masz na imię?: ";
    std::cin >> imie;


}

//zakresowa pętla for
void Gracz::showCategories() {
    for(std::string &kategoria : kat) {
        std::cout << kategoria << std::endl;
    }
}
