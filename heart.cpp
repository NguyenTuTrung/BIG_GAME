#include "heart.h"

using namespace std;

bool heart::init()
{
    posHeart.getPos(0, 0);                      // đưa con trỏ tới vị trí
    string back_path = "./res/image/heart.png"; // mở ảnh theo đường dẫn
    if (isNULL())
    {
        if (Load(back_path.c_str(), 0.04))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void heart::Free()
{
    free();
}

void heart::render()
{
    for (int i = 0; i < num_heart; i++)
    {
        Render(i * 30, 0);
    }
}

int heart::update()
{
    num_heart--;
    return num_heart;
}