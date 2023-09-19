#ifndef GAMEPROGRAMMING23_EXERCISES_ENGINE_H
#define GAMEPROGRAMMING23_EXERCISES_ENGINE_H
#include <chrono>
#include "Renderer.h"

using namespace std;


class Engine {
public:
    chrono::time_point<chrono::steady_clock> time_start;
    chrono::time_point<chrono::steady_clock> time_end;
    chrono::time_point<chrono::steady_clock> time_end_computation;
    chrono::duration<double> time_elapsed{};
    chrono::duration<double> time_computation{};
    unsigned char input{};

    Engine() = default;
    void Init(){
        time_start = chrono::steady_clock::now();
    }

    void setElapsed(){
        time_elapsed = chrono::steady_clock::now() - time_start;
    }

    void setComputationTime(){
        time_computation = chrono::steady_clock::now() - time_start;
    }

    double GetFPS() {
        return 1.0 / time_elapsed.count();
    }
    double GetTimeElapsedMs() {
        return 1000 * time_elapsed.count();
    }
    chrono::duration<double> GetTimeComputation() {
        return time_computation;
    }

    int GetScreenWidth(){
        return ITUGames::Console::GetTerminalWidth();
    }
    int GetScreenHeight(){
        return ITUGames::Console::GetTerminalHeight();
    }

    bool ProcessEvent() {
        input = ITUGames::Console::GetCharacter(false);
        return input == int('Q');
    }
    void Render(Renderer& r) {
        string fps         = "FPS                   : " + to_string(GetFPS()) + "\n";
        string frame_time  = "Frame time(ms)        : " + to_string(GetTimeElapsedMs()) + "\n";
        string computation = "Computation(ms)       : " + to_string(GetTimeComputation().count()) + "\n";
        r.printString(fps,0 ,0);
        r.printString(frame_time,0,1);
        r.printString(computation,0,2);
    }
};
#endif //GAMEPROGRAMMING23_EXERCISES_ENGINE_H
