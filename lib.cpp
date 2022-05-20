#include "lib.h"

using namespace std;

bool LTexture::quit = false;
bool LTexture::die = false;
short int LTexture::score = 0;
short int LTexture::PIPE_SPACE = 160;

SDL_Window *LTexture::gWindow = NULL;
SDL_Renderer *LTexture::gRenderer = NULL;
SDL_Event LTexture::event;
SDL_Texture *gTexture = NULL;

LTexture::LTexture()
{
	Texture = NULL;
}

short int LTexture::getWidth()
{
	return tWidth;
}

short int LTexture::getHeight()
{
	return tHeight;
}

void LTexture::free()
{
	if (Texture != NULL)
	{
		SDL_DestroyTexture(Texture);
		Texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

void LTexture::Render(short int x, short int y, short int angle, SDL_Rect *clip, SDL_RendererFlip flip)
{
	SDL_Rect Rec_Render = {x, y, tWidth, tHeight};

	if (clip != NULL)
	{
		Rec_Render.w = clip->w;
		Rec_Render.h = clip->h;
	}

	SDL_RenderCopyEx(gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip);
	// hiện thị kết cấu ra màn hình
}

bool LTexture::Load(string path, double scale)
{
	free();

	SDL_Surface *loadedSurface = IMG_Load(path.c_str()); // load lên màn hình theo đường dẫn
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255));
		// cài đặt background chi tiết cùng màu với nền

		Texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		// tạo 1 Texture mới từ Surface

		if (Texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			tWidth = (loadedSurface->w) * scale;
			tHeight = (loadedSurface->h) * scale;
		}

		SDL_FreeSurface(loadedSurface);
		// thoái khỏi cái Surface cũ
	}
	// SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	//  vẽ lại nền màu white

	return Texture != NULL;
}

bool LTexture::isNULL()
{
	if (Texture == NULL)
		return true;
	return false;
}

void position::getPos(const short int x, const short int y)
{
	this->x = x;
	this->y = y;
}
