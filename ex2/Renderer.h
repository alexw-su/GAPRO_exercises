#ifndef EX2_RENDERER_H
#define EX2_RENDERER_H
#include <vector>
using namespace std;

struct Renderer{
    char* map;
    int width;
    Renderer(int screen_width, int screen_height){
        map = new char[screen_width * screen_height];
        width = screen_width;
    }
    vector<tuple<char,int,int>> instructions;

    void print(char c, int x, int y){
        if (map[y*(width)+x+1] != c) instructions.push_back(make_tuple(c,x+1,y+1));
    }
    void printString(string header, int x, int y){
        for (int i = 0; i < header.size(); i++) print(header.at(i), x + i, y);

    }
    void erase(int x, int y){
        print(' ',x,y);
    }
};
#endif //EX2_RENDERER_H
