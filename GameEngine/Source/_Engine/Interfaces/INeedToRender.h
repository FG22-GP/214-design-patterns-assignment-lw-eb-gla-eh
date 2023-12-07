#pragma once
class SDL_Renderer;

class INeedToRender
{
public:
    virtual void Draw(SDL_Renderer* Renderer) = 0;
};
