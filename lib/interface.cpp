#include "biblioteka.h"

void Interface::pokazRanking() {
    Ranking r1;
    r1.showRanking();}

void Interface::wypiszKategorie() {
    Gracz kategorie;
    kategorie.showCategories();
}


void Interface::rozpocznij() {
    Game game1;
    game1.run();
}

void Interface::wypiszNagrody() {
  std::cout << "1\t$1,000\n2\t$2,000\n3\t$5,000\n4\t$10,000\n"
               "5\t$25,000(Suma gwarantowana)\n6\t$50,000\n7\t$100,000\n"
               "8\t$175,000\n9\t$300,000\n10\t$500,000\n11\t$1,000,000(Nagroda główna)" << std::endl;
}

void Interface::menu() {

    while(true) {
        std::cout << "\t***Czy jesteś mądrzejszy od 5-klasisty?***" << std::endl;
        std::cout << "1. Rozpocznij nową grę" << std::endl;
        std::cout << "2. Wyświetl ranking" << std::endl;
        std::cout << "3. Jak grać?" << std::endl;
        std::cout << "4. Wyjście" << std::endl;
        std::string WT;
        std::cin >> WT;
        //wyjatek
        try {
            wyborTrybu = std::stoi(WT);
        } catch (const std::invalid_argument& e) {
            wyborTrybu = 0; }
        Gracz gracc;
        switch(wyborTrybu) {
        case 1:
            std::cout << "Witaj w naszym teleturnieju!" << std::endl;
            //wyswietla przywitanie
            Interface::rozpocznij();
            break;
        case 2:
            pokazRanking();
            break;
        case 3:
            std::cout << "Gra polega na odpowiedzi na pytania z zakresu wiedzy 5-klasisty." << std::endl;
            std::cout << "Za każdą poprawną odpowiedź zarabiasz $$$" << std::endl;
            std::cout << "To dostępne kategorie pytań:" << std::endl;
            wypiszKategorie();
            std::cout << "Powodzenia!\nNagrody:" << std::endl;

            Interface::wypiszNagrody();

            std::cin.ignore(); //ignoruje ostatnie wejście
            std::cout << "Naciśnij dowolny klawisz, aby powrócić do menu" << std::endl;
            //czeka na naciśnięcie dowolnego klawisza
            getc_unlocked(stdin);
            for (int i = 0; i < 50; i++) std::cout << std::endl;

            break;
        case 4:
            std::cout << "Czy na pewno chcesz wyjść?" << std::endl;
            std::cout << "1. Tak" << std::endl;
            std::cout << "2. Nie" << std::endl;
            std::string WT1;    std::cin >> WT1;
            try {
                wyborTrybu = std::stoi(WT1);
            } catch (const std::invalid_argument &e) {
                wyborTrybu = 0;
            }
            if (wyborTrybu == 1) {
                std::cout << "Do zobaczenia!" << std::endl;
                exit(0);
            } else break;
    }
    }

}
