﻿#pragma once
#include "../Helpers/RE_Helpers.h"
#include "../ObserverPattern/RE_DelegateBase.h"
#include <SDL.h>

class RE_RawInputManager
{
public:
    RE_MulticastDelegate1<int> TestDelegate;

    void RegisterInput();
    Vector GetMoveInput() const { return MoveInput;}
    bool ShouldQuit(SDL_Event &e);
    void Start();


private:
    Vector MoveInput;
};
