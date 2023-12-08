﻿#include "RE_GameLoop.h"

#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>

#include "_Managers/RE_EntityManager.h"
#include "_Managers/RE_RawInputManager.h"
#include "_Managers/RE_RenderHandler.h"

RE_GameLoop::RE_GameLoop(RE_RenderHandler* RenderHandler, RE_EntityManager* EntityManager, RE_RawInputManager* InputManager): RenderHandler(RenderHandler), EntityManager(EntityManager), InputManager(InputManager)

{
}

void RE_GameLoop::Start()
{
    //Init things,
    if (!RenderHandler || !EntityManager)
    {
        printf("Entity manager or Render handler is Null inside The gameloop");
        return;
    }
    EntityManager->Start();
    
    Update();
}

void RE_GameLoop::Update()
{
    SDL_Event Event;
    while (!InputManager->ShouldQuit(Event))
    {
        float DeltaTime = CalculateDeltaTime();

        RenderHandler->RenderStuff();
        InputManager->RegisterInput();
        FixedUpdate(DeltaTime);
        EntityManager->Update(DeltaTime);
        RenderHandler->ClearRender();
    }
}

void RE_GameLoop::FixedUpdate(float DeltaTime)
{
    if (!ShouldRunFixedUpdate()) return;
    EntityManager->FixedUpdate(DeltaTime);
    
}


float RE_GameLoop::CalculateDeltaTime()
{
    float DeltaTime = (SDL_GetTicks() - TimeAtLastFrame) / 1000.0f;
    TimeAtLastFrame = SDL_GetTicks();
    TimeSinceLastFixedUpdate += DeltaTime;
    return DeltaTime;
}

bool RE_GameLoop::ShouldRunFixedUpdate()
{
    if (TimeSinceLastFixedUpdate <60.f)
    {
        TimeSinceLastFixedUpdate = 0;
        return true;
    }
    return false;
}
