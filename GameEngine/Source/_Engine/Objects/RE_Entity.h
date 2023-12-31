﻿#pragma once
#include <SDL_render.h>

#include "../RE_Image.h"
#include "../Helpers/RE_Helpers.h"
#include "../_Managers/RE_SubsystemManager.h"


class RE_RawInputManager;

class RE_Entity
{
public:
    RE_Entity();
    virtual void Initialize(RE_SubsystemManager* subsystem_manager,RE_RawInputManager* InputManager){};
    virtual void Start(){};
    virtual void Update(){};
    virtual void FixedUpdate(){};
    virtual void Draw(SDL_Renderer* Renderer);
public:
    Color EntityColor;
    RE_Image Image;
    Vector Position;
};
