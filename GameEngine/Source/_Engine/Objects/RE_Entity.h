#pragma once
#include <SDL_render.h>

#include "../RE_Image.h"
#include "../Helpers/RE_Helpers.h"


class RE_Entity
{
public:
    RE_Entity();
    virtual void BeginPlay(){};
    virtual void Update(){};
public:
    RE_Image Image;
    Vector Position;
};
