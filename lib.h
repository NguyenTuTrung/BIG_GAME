#pragma once
#include "CommonFunc.h"

using namespace std;

class position // position : định vị
{
public:
    short int x, y, angle, state;
    void getPos(const short int x, const short int y);
};

class LTexture
{
public:
    LTexture();
    ~LTexture(){};

    bool isNULL();
    bool Load(string path, double scale = 1); // scale : kích thước

    short int getWidth();
    short int getHeight();

    void free();

    void Render(short int x, short int y, short int angle = 0, SDL_Rect *clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    // SDL_Rect : biến cho hình chữ nhật
    // SDL_RendererFlip : lật hình ảnh
    // SDL_FLIP_NONE  : không lật

    SDL_Texture *Texture; // khai báo biến chứa các pixel rendering lên cửa sổ

    short int tWidth;
    short int tHeight;

    static SDL_Window *gWindow; // khai báo biến chứa tất cả thông tin của cửa sổ
    static SDL_Window *gWindow1;
    static SDL_Renderer *gRenderer; // khai báo biến chứa tất các rendering lên cửa sổ
    static SDL_Renderer *gRenderer1;
    static SDL_Event event; // khai báo biến chứa các sự kiến từ bàn phím , chuột , tay cầm
    static bool quit;
    static bool die;
    static bool Continue; // khai báo biến tiếp tục game
    static short int score;
    static short int PIPE_SPACE;

    // cách hằng số khởi tạo
    static const short int SCREEN_WIDTH = 350;
    static const short int SCREEN_HEIGHT = 625;
    // static const short int PIPE_SPACE = 160;
    static const short int TOTAL_PIPE = 4;
    static const short int PIPE_DISTANCE = 220;
    static const short int LAND_HEIGHT = 140;
    static const short int SHIBA_WIDTH = 50;
    static const short int SHIBA_HEIGHT = 35;
};