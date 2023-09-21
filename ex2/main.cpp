#include <chrono>

#include "ITUGames.h"
#include "Engine.h"
#include "Score.h"
#include "Player.h"
#include "Collectible.h"
#include "Renderer.h"

using namespace std;

const int FRAME_RATE = 1;
const chrono::duration<double> MS_PER_FRAME{ 1000.0 / FRAME_RATE / 1000.0 };
const int PLAYER_START_X = 20;
const int PLAYER_START_Y = 20;
const int PLAY_AREA_MARGINS = 5;

bool ProcessEvents();
void Update();
void Render();


Engine engine = Engine();
Player player = Player(PLAYER_START_X, PLAYER_START_Y);
Score score = Score();
Collectible collectible = Collectible(
            PLAY_AREA_MARGINS,
            PLAY_AREA_MARGINS,
            engine.GetScreenWidth(),
            engine.GetScreenHeight(),
            player
        );
Renderer renderer = Renderer(
        engine.GetScreenWidth(),
        engine.GetScreenHeight()
        );

int main() {
    ITUGames::Console::InitScreenForRendering();
    ITUGames::Console::HideCursor();
    bool quit = false;
	while(!quit) {
        engine.Init();
		quit = ProcessEvents();
		Update();
		Render();
        engine.setComputationTime();
        ITUGames::Utils::PreciseSleep(MS_PER_FRAME - engine.GetTimeComputation());
        engine.setElapsed();
    }
	return 0;
}

bool ProcessEvents()
{
    bool engine_state = engine.ProcessEvent();
    player.ProcessEvent(engine.input);
    return engine_state;
}

void Update() {
    player.Update();
    // check death
    if (player.IsOverlapping()) {
        ++score.deaths;
        score.wins = 0;
        ITUGames::Console::ClearScreen();
        player = Player(PLAYER_START_X, PLAYER_START_Y);
        collectible = Collectible(
                PLAY_AREA_MARGINS,
                PLAY_AREA_MARGINS,
                engine.GetScreenWidth() - PLAY_AREA_MARGINS,
                engine.GetScreenHeight() - PLAY_AREA_MARGINS,
                player
        );
    }
    // check collection
    if (
            player.GetPosX() == collectible.GetPosX() &&
            player.GetPosY() == collectible.GetPosY()
    ) {
        ++score.wins;
        player.Grow();
        renderer.erase(collectible.GetPosX(), collectible.GetPosY());
        collectible = Collectible(
                PLAY_AREA_MARGINS,
                PLAY_AREA_MARGINS,
                engine.GetScreenWidth() - PLAY_AREA_MARGINS,
                engine.GetScreenHeight() - PLAY_AREA_MARGINS,
                player
        );

    }
}

void Render()
{
    engine.Render(renderer);
    player.Render(renderer);
    score.Render(renderer);
    collectible.Render(renderer);
    for(auto& instruction : renderer.instructions){
        char c = get<0>(instruction);
        int x = get<1>(instruction);
        int y = get<2>(instruction);
        ITUGames::Console::RenderCharacter(c, x, y);
    }
    renderer.instructions.clear();
}