#pragma once
#include "../Helpers/RE_Helpers.h"
#include "../ObserverPattern/RE_DelegateBase.h"
#include <SDL.h>

class RE_GameLoop;

class RE_RawInputManager
{
    friend RE_GameLoop;

private:
    void RegisterInput();
    Vector GetMoveInput() const { return MoveInput;}
    bool ShouldQuit(SDL_Event &e);
    void Start();
    
public:
    RE_MulticastDelegate1<Vector> OnMoveInputUpdated;
private:
    Vector MoveInput;
};
