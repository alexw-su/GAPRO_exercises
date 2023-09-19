#ifndef EX2_COLLECTIBLE_H
#define EX2_COLLECTIBLE_H
class Collectible {
private:
    int x, y;
public:
    Collectible(int margins_width, int margins_height, int screen_width, int screen_height, Player& player) {
        do{
            x = (rand() % (screen_width)) + margins_width;
            y = (rand() % (screen_height)) + margins_height;
        } while (InPlayer(player));
    }

    bool InPlayer(Player& player){
        auto it_x = player.pos_x.begin();
        auto it_y = player.pos_y.begin();
        while (it_x != player.pos_x.end() && it_y != player.pos_y.end()) {
            if (*it_x == GetPosX() && *it_y == GetPosY())
                return true;
            ++it_x;
            ++it_y;
        }
        return false;
    }

    int GetPosX() {
        return x;
    }

    int GetPosY() {
        return y;
    }

    void Render(Renderer& r){
        r.print('X',GetPosX(), GetPosY());
    }
};
#endif //EX2_COLLECTIBLE_H
