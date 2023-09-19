#ifndef GAMEPROGRAMMING23_EXERCISES_PLAYER_H
#define GAMEPROGRAMMING23_EXERCISES_PLAYER_H

class Player {
    private:
    int prev_pos_x = 0;
    int prev_pos_y = 0 ;

    int dir_x = 0;
    int dir_y = 0;
public:
    vector<int> pos_x;
    vector<int> pos_y;
    Player(int start_x, int start_y){
        pos_x.push_back(start_x);
        pos_y.push_back(start_y);
        pos_x.push_back(start_x+1);
        pos_y.push_back(start_y);
        pos_x.push_back(start_x+2);
        pos_y.push_back(start_y);
    }
    void ProcessEvent(unsigned char p_input) {
        switch (p_input) {
            case ITUGames::Console::KEY_A:
                if (dir_x == 0){
                    dir_x = -1;
                    dir_y = 0;
                }
                break;
            case ITUGames::Console::KEY_W:
                if (dir_y == 0){
                    dir_y = -1;
                    dir_x = 0;
                }
                break;
            case ITUGames::Console::KEY_D:
                if (dir_x == 0){
                    dir_x = 1;
                    dir_y = 0;
                }
                break;
            case ITUGames::Console::KEY_S:
                if (dir_y == 0){
                    dir_y = 1;
                    dir_x = 0;
                }
                break;
            default: break;
        }
    }
    void Update() {
        prev_pos_x = pos_x.back();
        prev_pos_y = pos_y.back();
        // `:` is syntax sugar for simple,
        // linear iterator usage
        int next_x = pos_x.front() + dir_x;
        for (int& x: pos_x) {
            int curr_x = x;
            x = next_x;
            next_x = curr_x;
        }
        int next_y = pos_y.front() + dir_y;
        for (int& y: pos_y) {
            int curr_y = y;
            y = next_y;
            next_y = curr_y;
        }
    }

    bool IsOverlapping() {
        // can’t overlap with less than 3 elements
        if (pos_x.size() <= 3)
            return false;
        // here we need the values at the same time,
        // so we do it the verbose way
        auto it_x = pos_x.begin();
        auto it_y = pos_y.begin();
        ++it_x; // the head will always overlap itself,
        ++it_y; // so we skip it
        while (it_x != pos_x.end() && it_y != pos_y.end()) {
            if (*it_x == GetPosX() && *it_y == GetPosY())
                return true;
            ++it_x;
            ++it_y;
        }
        return false;
    }

    void Render(Renderer& r){
        if (prev_pos_x != 0 && prev_pos_y != 0)
            r.erase(prev_pos_x,prev_pos_y);
        for (int i = 0; i < size(pos_x); i++)
            r.print('o', pos_x.at(i), pos_y.at(i));
    }

    int GetPosX() {
        return *pos_x.begin();
    }

    int GetPosY() {
        return *pos_y.begin();
    }

    void Grow() {
        pos_x.push_back(prev_pos_x);
        pos_y.push_back(prev_pos_y);
    }
};
#endif //GAMEPROGRAMMING23_EXERCISES_PLAYER_H
