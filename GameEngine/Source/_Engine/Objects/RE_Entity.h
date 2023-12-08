#pragma once
#include <SDL_render.h>

#include "../RE_Image.h"
#include "../Helpers/RE_Helpers.h"
#include "../Interfaces/INeedToRender.h"


class RE_Entity
{
public:
    
    RE_Entity();
    virtual void Start(){};
    virtual void Update(){};
    virtual void FixedUpdate(){};
    virtual void Draw(SDL_Renderer* Renderer);
public:
    
    RE_Image Image;
    Vector Position;
};
