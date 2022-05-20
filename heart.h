#pragma once
#include "CommonFunc.h"
#include "lib.h"

using namespace std;

class heart : LTexture
{
public:
    bool init();

    void Free();

    void render();

    int update();

private:
    position posHeart;
    short int num_heart = 3;
};