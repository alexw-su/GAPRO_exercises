#include <chrono>
#include <vector>

#include "ITUGames.h"
#include "Engine.h"
#include "Score.h"
#include "Player.h"
using namespace std;

const int FRAME_RATE = 5;
const chrono::duration<double> MS_PER_FRAME{ 1000.0 / FRAME_RATE / 1000.0 };
const int PLAYER_START_X = 20;
const int PLAYER_START_Y = 20;

void ProcessEvents();
void Update();
void Render();

Engine engine = Engine();
Player player = Player(PLAYER_START_X, PLAYER_START_Y);
Score score = Score();

int main() {
    ITUGames::Console::InitScreenForRendering();
	while(true) {
		ProcessEvents();
		Update();
		Render();

        chrono::duration<double> computation_time = engine.GetTimeComputationMS();

        ITUGames::Utils::PreciseSleep(MS_PER_FRAME - computation_time);

    }
	return 0;
}

void ProcessEvents()
{
    unsigned char input = ITUGames::Console::GetCharacter(false);
    engine.ProcessEvent();
    player.ProcessEvent(input);
}

void Update()
{
    engine.Update();
    player.Update(/*todo*/);
    score.Update();
}

void Render()
{
    engine.Render();
    player.Render();
    score.Render();
}