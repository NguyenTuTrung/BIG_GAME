#pragma once
#include "CommonFunc.h"
#include "lib.h"
#include "pipe.h"

using namespace std;

class dog : LTexture
{
public:
    bool init(bool isDark);

    void render();

    void Free();

    void resetTime()
    {
        time = 0;
    }

    void update(short int pileWidth, short int pileHeight);

private:
    short int angle, time, x0;
    short int ahead = 0;
    string saved_path = "";
    position posDog;
};
