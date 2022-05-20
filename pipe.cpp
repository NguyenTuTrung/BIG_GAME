#include "pipe.h"
#include "CommonFunc.h"
#include "lib.h"

using namespace std;

vector<position> posPipe;

bool pipe::init() // khởi tạo ống nước
{
    posPipe.clear();
    for (int i = 0; i < TOTAL_PIPE; i++)
    {
        position temp;
        temp.getPos(SCREEN_WIDTH + i * PIPE_DISTANCE + 350, (rand() % (randMax - randMin + 1)) + randMin);
        posPipe.push_back(temp); // thêm vào đằng sau mảng vecto posPipe
    }
    if (isNULL())
    {
        if (Load("./res/image/pipe.png", 1))
        {
            return true;
        }
    }
    return false;
}

void pipe::Free() // xóa ống nước khỏi màn
{
    free();
}

void pipe::render()
{
    for (int i = 0; i < TOTAL_PIPE; i++)
    {
        if (posPipe[i].x <= SCREEN_WIDTH && posPipe[i].x > -getWidth())
        {
            Render(posPipe[i].x, posPipe[i].y);
            Render(posPipe[i].x, posPipe[i].y + getHeight() + PIPE_SPACE, 180);
        }
    }
}

void pipe::update()
{
    if (!die)
    {
        for (int i = 0; i < TOTAL_PIPE; i++)
        {
            if (posPipe[i].x < -getWidth())
            {
                posPipe[i].y = (rand() % (randMax - randMin + 1)) + randMin;
                posPipe[i].x = posPipe[(i + TOTAL_PIPE - 1) % TOTAL_PIPE].x + PIPE_DISTANCE;
            }
            else
            {
                /////////////////////////////////
                if (score >= 0 && score <= 20)
                {
                    posPipe[i].x -= 3;
                }
                else if (score > 20 && score <= 40)
                {
                    posPipe[i].x -= 3.1;
                }
                else if (score > 40)
                {
                    posPipe[i].x -= 3.2;
                }
            }
        }
    }
    if (score > 10 && score <= 20)
    {
        PIPE_SPACE = 140;
    }
    else if (score > 20 && score <= 40)
    {
        PIPE_SPACE = 120;
    }
    else if (score > 40)
    {
        PIPE_SPACE = 100;
    }
}