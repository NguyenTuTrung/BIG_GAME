#pragma once
#include "CommonFunc.h"
#include "lib.h"

using namespace std;

class land : LTexture
{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    position posLand;
};
