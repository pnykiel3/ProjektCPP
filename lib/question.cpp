#include "biblioteka.h"

Question::Question(const std::string &questionText, const std::vector<std::string> &choices, std::string &correctAnswer)
        : questionText(questionText), choices(choices), correctAnswer(correctAnswer) {}

std::string Question::getQuestionText() const {
    return questionText;
}

std::vector<std::string> Question::getChoices() const {
    return choices;
}


void Question::getAnswer() {
    std::cout << "\nTwoja odpowiedź: ";
    std::cin >> answer;
}

bool Question::checkAnswer(Gracz &g1) {
    if (correctAnswer == answer) {
        //std::cout << "Dobra odpowiedź!" << std::endl;
        g1++;
        //++ dzieki przeciążeniu operatora ++ w gracz.cpp
        if(g1.punkty == 10) {
            std::cout << "Gratulacje! Wygrałeś!" << std::endl;
            //zapisz w pliku ranking, ze uzytkownik jest madrzejszy od 5-klasisty
            //polimorfizm
            Zwyciestwo z;
            Wynik *wsk;
            wsk = &z;
            wsk->showResult(g1);
        }
        return true;
    } else {
        std::cout << "Zła odpowiedź. Poprawna odpowiedź to: " << correctAnswer << std::endl;
        //zakoncz gre i kaz graczowi napisac ze nie jest madrzejszy od 5-klasisty
        //polimorfizm
        Przegrana p;
        Wynik *wsk;
        wsk = &p;
        wsk->showResult(g1);
        return false;
    }
}
