#pragma once
#include <SDL_render.h>

#include "../RE_Image.h"
#include "../Helpers/RE_Helpers.h"
#include "../Interfaces/INeedToRender.h"


class RE_Entity :public INeedToRender
{
public:
    
    RE_Entity();
    virtual void BeginPlay(){};
    virtual void Update(){};
    virtual void Draw(SDL_Renderer* Renderer) override;
public:
    
    RE_Image Image;
    Vector Position;
};
