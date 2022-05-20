#pragma once
#include "CommonFunc.h"
#include "lib.h"

using namespace std;

extern vector<position> posPipe; // khai báo dạng ko biết địa chỉ

class pipe : LTexture
{
private:
    const short int randMin = -373 + 30;
    const short int randMax = SCREEN_HEIGHT - LAND_HEIGHT - 373 - PIPE_DISTANCE - 30;

public:
    bool init();

    void Free();

    void render();

    void update();

    short int width() { return getWidth(); }

    short int height() { return getHeight(); }
};
