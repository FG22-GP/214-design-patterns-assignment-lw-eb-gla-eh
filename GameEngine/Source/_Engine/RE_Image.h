#pragma once
#include <SDL_render.h>

#include "Helpers/RE_Helpers.h"

struct RE_Image
{
public:
    RE_Image(){}
    RE_Image(SDL_Texture* InTexture, const Vector& Position)
    {
        Texture = InTexture;
        Rect.x = Position.X;
        Rect.y = Position.Y;
    }
public:
    void Draw();
public:
    SDL_Texture* Texture;
    SDL_Rect Rect{0,0,100,100};
};
