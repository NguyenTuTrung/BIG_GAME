#include "land.h"
#include "CommonFunc.h"
#include "lib.h"

using namespace std;

bool land::init() // khởi tạo mặt đất
{
    posLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT); // đưa con trỏ tới vị trí
    string back_path = "./res/image/land.png";      // mở ảnh theo đường dẫn
    if (isNULL())
    {
        if (Load(back_path.c_str(), 1))
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

void land::Free() // giải phóng màn
{
    free();
}

void land::render() // kết xuất mặt đất
{
    if (posLand.x > 0)
    {
        Render(posLand.x, posLand.y);
    }
    else if (posLand.x > -SCREEN_WIDTH && posLand.x <= 0)
    {
        Render(posLand.x, posLand.y);
        Render(posLand.x + SCREEN_WIDTH, posLand.y, 0, NULL);
    }
    else
    {
        posLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT);
        Render(posLand.x, posLand.y);
    }
}

void land::update()
{
    posLand.x -= 3;
}