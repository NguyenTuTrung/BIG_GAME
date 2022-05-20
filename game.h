#pragma once
#include "dog.h"
#include "pipe.h"
#include "land.h"
#include "sound.h"
#include "CommonFunc.h"
#include "heart.h"

using namespace std;

class game : LTexture
{
public:
    struct input
    {
        enum type
        {
            QUIT,
            PLAY,
            NONE,
            PAUSE
        };
        type Type;
    };
    input userInput;
    dog shiba;
    pipe pipe;
    sound sound;
    land land;
    heart heart;

public:
    game();

    ~game();

    bool initGraphic();

    bool isQuit()
    {
        return quit;
    }

    bool isDie()
    {
        return die;
    }

    int getPipeWidth()
    {
        return pipe.width();
    }

    int getPipeHeight()
    {
        return pipe.height();
    }

    bool colorscreen();

    void takeInput();

    void display();

    void releaseGraphic();

    void renderScoreSmall();

    void renderScoreLarge();

    void renderBestScore();

    void renderMessageOne();

    void renderMessage();

    void Menu();

    void renderBackground();

    void renderBackgroundNight();

    void resume();

    void pause();

    void renderPauseTab();

    void lightTheme();

    void darkTheme();

    void nextButton();

    bool changeTheme();

    void renderGameOver();

    void renderMedal();

    void replay();

    void resumeGame();

    void Continue();

    bool checkResume(); //

    bool checkReplay(); ///

    bool checkContinue();

    // bool checkPause();

    void Restart();

    void ContinueGame();

private:
    const double scaleNumberS = 0.75;
    short int bestScore;
};