#pragma once
#include <SDL_stdinc.h>

#include "ObserverPattern/RE_DelegateBase.h"

class RE_RawInputManager;
class RE_EntityManager;
class RE_RenderHandler;

class RE_GameLoop
{
public:
    RE_GameLoop(RE_RenderHandler* RenderHandler, RE_EntityManager* EntityManager, RE_RawInputManager* InputManager);
    void Start();
    void Update();
    void FixedUpdate();
    void TestFunctionWithOutDelegaet(int Number);
    void TestFunctionWithOutDelegaet2(int Number);
    Uint32 DeltaTime();

private:
    Uint32 FrameCount;
    float TimePassed;
    float RequiredTimeForFixedUpdate;
    RE_RenderHandler* RenderHandler;
    RE_EntityManager* EntityManager;
    RE_RawInputManager* InputManager;
};
