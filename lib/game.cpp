#include "biblioteka.h"

Game::Game() = default;

void Game::selectCat(Gracz &g1) {



        int wybor;
        std::cout << "Dostępne kategorie:" << std::endl;

//iterator
    for (auto itr = g1.kat.begin(); itr != g1.kat.end(); ++itr) {
        int i = std::distance(g1.kat.begin(), itr); // Pobieramy indeks z iteratora
        if (g1.zablokowaneKat.find(i) == g1.zablokowaneKat.end()) {
            std::cout << i << " = " << *itr << std::endl;
        }
    }

    //to samo bez iteratora

     /*
        for (int i = 0; i < g1.kat.size(); ++i) {
            if (g1.zablokowaneKat.find(i) == g1.zablokowaneKat.end()) {
                std::cout << i << " = " << g1.kat[i] << std::endl;
            }
        }

      */

        std::cout << "Wybierz kategorię: ";
        std::cin >> wybor;

        if (wybor < 0 || wybor >= g1.kat.size()) {
            std::cout << "Niepoprawny numer. Spróbuj ponownie." << std::endl;
        } else if (g1.zablokowaneKat.find(wybor) != g1.zablokowaneKat.end()) {
            std::cout << "Ta kategoria została już wybrana. Wybierz inną." << std::endl;
        } else {
            g1.obecnaKategoria = wybor;
            g1.zablokowaneKat.insert(wybor);
            std::cout << "Kategoria " << g1.kat[wybor] << " została wybrana.\nPowodzenia!" << std::endl;
        }

    }

void Game::loadQuestions(Gracz &g1) {

        std::fstream plik;
         plik.open("../pytania.txt", std::ios::in);
        if (plik.good()) {
            std::string linia;
            srand(time(nullptr));
            int nrLinii = 2 + g1.obecnaKategoria * 70 + 7 * (rand() % 10);
            //std::cout << "nrLinii: " << nrLinii << std::endl;
            int j=1;
            std::string trescPytania, a, b, c, d, poprawnaOdpowiedz;
            std::vector<std::string> choices;


                while(getline(plik, linia)) {
                if(j == nrLinii) trescPytania = linia;                //1
                if(j == nrLinii+1) choices.push_back(linia);
                if(j == nrLinii+2) choices.push_back(linia);
                if(j == nrLinii+3) choices.push_back(linia);
                if(j == nrLinii+4) choices.push_back(linia);
                if(j == nrLinii+5) poprawnaOdpowiedz = linia;
                j++;

            }
            plik.close();
            Question q(trescPytania, choices, poprawnaOdpowiedz);
            std::cout << q.getQuestionText() << std::endl;
            auto choice = q.getChoices();
            char literki[] = {'a', 'b', 'c', 'd'};
            for (int i = 0; i < choices.size(); i++) {
                std::cout << literki[i] << ")\t" << choices[i] << std::endl;
            }
            q.getAnswer();
            q.checkAnswer(g1);


        } else {
            std::cout << "Nie udalo sie otworzyc pliku z pytaniami! " << std::endl;
            std::cout << "Blad: " << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
    }

void Game::run() {
    Gracz player1;
    player1.zmienImie();
    while(true) {
        selectCat(player1);
        loadQuestions(player1);
    }
}
