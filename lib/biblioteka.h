#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <unordered_set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <tuple>

class Gracz;
class Question;
class Wynik;


class Wynik {
public:
//funkcja czysto wirtualna
    virtual void showResult(Gracz &g1) = 0;
};

//dziedzieczenie po klasie abstrakcyjnej Wynik
class Zwyciestwo : public Wynik {
public:
    void showResult(Gracz &g1) override;
};

//dziedzieczenie po klasie abstrakcyjnej Wynik
class Przegrana : public Wynik {

public:
    void showResult(Gracz &g1) override;
};


class Game {
public:
    Game();
    void run();
    void selectCat(Gracz &g1);
    //void help(Gracz &g1);

private:
    std::vector<Question> questions;
    static void loadQuestions(Gracz &g1) ;
};




class Gracz {
private:
    std::string imie;
    int punkty;
    int obecnaKategoria;
    std::vector<std::string> IDkat;
    std::unordered_set<int> zablokowaneKat;
    std::vector<std::string> kat;


public:
    Gracz(std::string = "Anonim", int = 0);
    ~Gracz();
    void zmienImie();
    std::string getImie() const { return imie; }
    int getPunkty() const { return punkty; }
    void showCategories();

    //przeciazenie operatora ++
    Gracz operator++(int) {
        Gracz temp = *this;
        this->punkty++;
        std::cout << "Dobra odpowiedź!" << std::endl;
        return temp;
    }

    //klasy Game, Question są przyjaciółmi klasy Gracz
    friend class Question;
    friend class Game;
};



class Interface {
    int wyborTrybu;
public:
    void menu();
    void wypiszNagrody();
    void wypiszKategorie();
    void rozpocznij();
    void pokazRanking();
};






class Question {
public:
    Question(const std::string &questionText, const std::vector<std::string> &choices, std::string &correctAnswer);

    std::string getQuestionText() const;
    std::vector<std::string> getChoices() const;
    bool checkAnswer(Gracz &g1);
    void getAnswer();

private:
    std::string questionText;
    std::vector<std::string> choices;
    std::string correctAnswer;
    std::string answer;

    friend class Game;
};


class Ranking {


public:
    void showRanking();
    void addResult(Gracz &g1);
};

#endif

