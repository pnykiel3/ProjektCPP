#include "biblioteka.h"


void Ranking::showRanking() {
    std::ifstream file("ranking.txt");
    if (file.is_open()) {
        std::vector<std::tuple<int, std::string>> scores;
        std::string name;
        int score;
        while (file >> name >> score) {
            scores.push_back(std::make_tuple(score, name));
        }
        file.close();

        // Sortowanie wektora w kolejności malejącej
        //ALGORYTM STL
        std::sort(scores.begin(), scores.end(), std::greater<>());

        // Wyświetlanie posortowanych wyników
        for (const auto& entry : scores) {
            std::cout << std::get<1>(entry) << " " << std::get<0>(entry) << std::endl;
        }
    } else {
        std::cout << "Nie można otworzyć pliku" << std::endl;
    }
}


void Ranking::addResult(Gracz &g1) {
    std::ofstream file("ranking.txt", std::ios::app);
    if (file.is_open()) {
        file << g1.getImie() << " " << g1.getPunkty() << std::endl;
        file.close();
    } else {
        std::cout << "Nie można otworzyć pliku" << std::endl;
    }
}
