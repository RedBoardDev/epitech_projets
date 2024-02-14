#include "../includes/SDL.hpp"
#include "../includes/IDisplayModule.hpp"
#include "SDL2/SDL.h"

#include <chrono>

Arcade::Graphics::SDL::SDL(size_t winX, size_t winY)
{

    this->sdl = std::make_unique<SDLEncaps>(winX, winY);

    this->winSize.first = winX;
    this->winSize.second = winY;

    // TTF_Font * font = TTF_OpenFont("arial.ttf", 25);
    // SDL_Color color = { 255, 255, 255 };
    // SDL_Surface * surface = TTF_RenderText_Solid(font,
    // "Welcome to Programmer's Ranch", color);
    // SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
    // surface);

    // int texW = 0;
    // int texH = 0;
    // SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    // SDL_Rect dstrect = { 0, 0, texW, texH };
}

Arcade::Graphics::SDL::~SDL()
{

}

void Arcade::Graphics::SDL::setFrameRateLimit(int limit)
{
    this->sdl->setFrameRateLimit(limit);
}
void Arcade::Graphics::SDL::putpixel(int x, int y, unsigned int color)
{
    if (x < 0 || x > this->winSize.first)
        return;
    if (y < 0 || y > this->winSize.second)
        return;
    this->sdl->putPixel(x, y, color);
}

std::vector<Arcade::Graphics::IDisplayModule::Events> Arcade::Graphics::SDL::getEvents()
{
    return this->eventList;
}

bool Arcade::Graphics::SDL::isOpen()
{
    return true;
}

void Arcade::Graphics::SDL::clearWin()
{
    for (int i = 0; i < this->winSize.first; ++i) {
        for (int j = 0; j < this->winSize.second; ++j)
            this->putpixel(i, j, 0);
    }
}

void Arcade::Graphics::SDL::refreshWin()
{
    this->eventList = this->sdl->getEvents();
    this->mousePos = this->sdl->getMousePos();

    this->sdl->display();
}

void Arcade::Graphics::SDL::puttext(int x, int y, unsigned int color, const std::string &str)
{

    this->sdl->putText(x, y, color, str);
    // this->fontSurface = TTF_RenderText_Solid(this->font, str.c_str(), (SDL_Color){(Uint8)((color >> 24) % 256), (Uint8)((color >> 16) % 256),(Uint8)((color >> 8) % 256)});
    // SDL_Rect srcRect;
    // SDL_Rect destRect;
    // destRect.x = 0;
    // destRect.y = 0;
    // destRect.w = 100;
    // destRect.h = 50;

    // SDL_GetClipRect(this->fontSurface, &srcRect);

    // SDL_BlitSurface(this->fontSurface, &srcRect,this->screen, &destRect);

    // int texW = 0;
    // int texH = 0;

    // this->fontTexture = SDL_CreateTextureFromSurface(this->renderer, this->fontSurface);
    // SDL_QueryTexture(this->fontTexture, NULL, NULL, &texW, &texH);
    // SDL_Rect dstrect = { 0, 0, texW, texH };


    // this->fontSurface = TTF_RenderText_Solid(this->font, str.c_str(), (SDL_Color){(Uint8)((color >> 24) % 256), (Uint8)((color >> 16) % 256),(Uint8)((color >> 8) % 256)});
    // SDL_RenderCopy(this->renderer, this->fontTexture, NULL, &dstrect);
    // SDL_RenderPresent(this->renderer);
}

std::pair<int, int> Arcade::Graphics::SDL::getMousePos()
{
    return this->mousePos;
}