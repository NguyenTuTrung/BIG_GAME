#include "game.h"
#include "CommonFunc.h"
#include "dog.h"
#include "lib.h"
#include "land.h"
#include "sound.h"
#include "heart.h"

using namespace std;

const short int FPS = 60;      // số khung hình cần render lên trên 1 giây
const short int frameDelay = 1000 / FPS; //thời gian tính trên lý thuyết để máy tính tính toán và render xong 1 frame

using namespace std;

int main(int argc, char *argv[])
{
    Uint32 frameStart;
    short int frameTime;
    game g;
    bool isMenu = 0;
    bool isPause = 0;
    bool isSound = 1;
    bool isDark = 0;
    int num_player;

    while (!g.isQuit())
    {
        frameStart = SDL_GetTicks(); // SDL_GetTicks() : chức năng lấy về tổng số miliseconds từ khi SDL được khởi tạo.

        if (g.isDie())
        {
            if (isMenu)
            {
                g.sound.playHit();
                g.shiba.render();
            }
            g.userInput.Type = game::input::NONE;
            while (g.isDie() && !g.isQuit())
            {
                g.takeInput();
                if (isMenu == 1 && g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay() || g.checkContinue())
                    {
                        isMenu = 0;
                        num_player = g.heart.update();
                        g.heart.render();
                    }
                    if (num_player <= 0)
                    {
                        isMenu = 1;
                    }

                    g.userInput.Type = game::input::NONE;
                }
                isDark = g.colorscreen();
                if (!isDark)
                {
                    g.renderBackground();
                }
                else
                {
                    g.renderBackgroundNight();
                }

                g.pipe.render();
                g.land.render();
                g.shiba.render();
                // g.heart.render();

                if (isMenu)
                {
                    g.shiba.render();
                    g.renderGameOver();
                    g.renderMedal();
                    g.renderScoreSmall();
                    g.renderBestScore();
                    g.replay();
                    g.Continue();
                }
                else
                {
                    g.pipe.init();
                    g.shiba.init(false);
                    g.shiba.render();
                    if (num_player < 3 && num_player > 0)
                    {
                        g.renderMessage();
                    }
                    else
                        g.renderMessageOne();
                    if (g.userInput.Type == game::input::PLAY)
                    {
                        g.ContinueGame();
                        if (g.checkContinue())
                        {
                            g.ContinueGame();
                        }
                        else if (g.checkReplay())
                        {
                            g.Restart();
                        }
                        isMenu = 1;
                        g.userInput.Type = game::input::NONE;
                    }
                    g.land.update();
                }
                g.display();
            }
            g.pipe.init();
        }
        else
        {
            g.takeInput();

            if (g.userInput.Type == game::input::PAUSE)
            {
                isPause = abs(1 - isPause); // Nhấn phím ESC để pause hoặc nhấp chuột phải
                g.userInput.Type = game::input::NONE;
            }

            if (isPause == 0 && g.userInput.Type == game::input::PLAY)
            {
                if (isSound)
                    g.sound.playBreath();
                g.shiba.resetTime();
                g.userInput.Type = game::input::NONE;
            }
            isDark = g.colorscreen();
            if (!isDark)
            {
                g.renderBackground();
            }
            else
            {
                g.renderBackgroundNight();
            }
            g.pipe.render();
            g.land.render();
            g.shiba.render();
            g.renderScoreLarge();
            g.heart.render();

            if (!isPause)
            {
                g.shiba.update(g.getPipeWidth(), g.getPipeHeight());
                g.pipe.update();
                g.land.update();
                g.pause();
            }
            else
            {
                g.resume();
                g.renderPauseTab();
                g.renderScoreSmall();
                g.renderBestScore();
                g.resumeGame();
                g.sound.renderSound();
                if (!isDark)
                    g.lightTheme();
                else
                    g.darkTheme();
                g.nextButton();
                if (g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkResume())
                    {
                        isPause = 0;
                    }
                    else if (g.sound.checkSound())
                    {
                        isSound = abs(1 - isSound);
                    }
                    else if (g.changeTheme())
                    {
                        isDark = abs(isDark - 1);
                        g.shiba.init(isDark);
                    }
                    g.userInput.Type = game::input::NONE;
                }
            }
            g.display();
        }

        // Limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
