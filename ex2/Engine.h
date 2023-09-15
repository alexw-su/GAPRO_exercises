#ifndef GAMEPROGRAMMING23_EXERCISES_ENGINE_H
#define GAMEPROGRAMMING23_EXERCISES_ENGINE_H
#include <chrono>
using namespace std;


class Engine {
public:
    chrono::time_point<chrono::steady_clock> time_start;
    chrono::time_point<chrono::steady_clock> time_end;
    chrono::time_point<chrono::steady_clock> time_end_computation;
    chrono::duration<double> time_elapsed;
    chrono::duration<double> time_computation;

    Engine() {

    }

    double GetFPS() {

    }
    chrono::duration<double> GetTimeElapsedMs() {

    }
    chrono::duration<double> GetTimeComputationMS() {

    }

    void ProcessEvent() {

    }
    void Update() {

    }
    void Render() {

    }
};
#endif //GAMEPROGRAMMING23_EXERCISES_ENGINE_H
