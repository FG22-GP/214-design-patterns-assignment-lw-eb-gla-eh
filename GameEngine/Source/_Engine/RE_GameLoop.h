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

private:
    void Update();
    void FixedUpdate(float DeltaTime);
    float CalculateDeltaTime();
    bool ShouldRunFixedUpdate();
private:
    float TimeSinceLastFixedUpdate;
    float TimeAtLastFrame;
    RE_RenderHandler* RenderHandler;
    RE_EntityManager* EntityManager;
    RE_RawInputManager* InputManager;
};
