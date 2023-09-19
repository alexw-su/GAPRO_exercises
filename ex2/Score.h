#ifndef GAMEPROGRAMMING23_EXERCISES_SCORE_H
#define GAMEPROGRAMMING23_EXERCISES_SCORE_H
#include "Renderer.h"
class Score{

public:
    int wins = 0;
    int deaths = 0;
    Score()= default;
    void Update(){

    }
    void Render(Renderer& r){
        string winsStr    = "Wins                  : " + to_string(wins) + "\n";
        string deathsStr  = "Deaths                : " + to_string(deaths) + "\n";
        r.printString(winsStr,0,3);
        r.printString(deathsStr,0,4);
    }
};
#endif //GAMEPROGRAMMING23_EXERCISES_SCORE_H
