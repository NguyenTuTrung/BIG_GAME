#include "dog.h"
#include <stdio.h>
#include <iostream>

bool dog::init(bool isDark)
{
    string shiba_path = "./res/image/shiba.png";
    if (isDark)
        shiba_path = "./res/image/shiba-dark.png";
    if (saved_path == shiba_path)
    {
        posDog.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != shiba_path)
    {
        saved_path = shiba_path;
        if (Load(shiba_path.c_str(), 1))
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

void dog::Free()
{
    free();
}

void dog::render()
{
    Render(posDog.x, posDog.y, angle);
}

void dog::fall()
{
    if (die && posDog.y < SCREEN_HEIGHT - LAND_HEIGHT - SHIBA_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posDog.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posDog.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else
        return;
}

//***********************************************//

void dog::update(short int pipeWidth, short int pipeHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            x0 = posDog.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posDog.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ((posDog.x + getWidth() > posPipe[ahead].x + 5) && (posDog.x + 5 < posPipe[ahead].x + pipeWidth) &&
            (posDog.y + 5 < posPipe[ahead].y + pipeHeight || posDog.y + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5))
        {
            die = true;
        }
        else if (posDog.x > posPipe[ahead].x + pipeWidth)
        {
            ahead = (ahead + 1) % TOTAL_PIPE;
            score++;
        }

        if (posDog.y > SCREEN_HEIGHT - LAND_HEIGHT - SHIBA_HEIGHT - 5 || posDog.y < -10)
        {
            die = true;
        }
    }
}