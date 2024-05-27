#include "biblioteka.h"

void Zwyciestwo::showResult(Gracz &g1) {
    std::cout << "Gracz " << g1.getImie() << " Jest mądrzejszy od 5-klasisty" << std::endl;
    std::cout << "Gratulacje!\nWygrywasz $1,000,000!" << std::endl;
    Ranking r12;
    r12.addResult(g1);
    exit(0);
}

void Przegrana::showResult(Gracz &g1) {
    std::cout << "Twój wynik to: " << g1.getPunkty() << std::endl;
    Ranking r13;
    r13.addResult(g1);
    std::cout << g1.getImie() << " teraz przyznaj się do porażki\n" << std::endl;
    std::string porazka;
    std::string porazka2 = "Nie jestem mądrzejszy od 5-klasisty";

    if (g1.getPunkty() > 4) {
        std::cout << "Gratulacje!\nWygrywasz sumę gwarantowaną $25,000!" << std::endl;
    } else {
        std::cout << "Niestety, odchodzisz z pustymi rękami." << std::endl;
    }
    std::cout << "Napisz: \"" << porazka2 << "\"" << std::endl;
    while (porazka2 != porazka) {
        std::getline(std::cin, porazka);
    }
    std::ofstream file("NieJestemMadrzejszy.txt");

    if (file.is_open()) {
        file << porazka2 << std::endl << g1.getImie();
        file.close();
    } else {
        std::cout << "Nie można otworzyć pliku" << std::endl;
    }
    exit(0);
}