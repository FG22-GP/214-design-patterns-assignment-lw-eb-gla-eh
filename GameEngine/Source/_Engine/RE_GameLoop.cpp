﻿#include "RE_GameLoop.h"

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
    RE_DelegateMember1<RE_GameLoop,int,void> Name(this,&RE_GameLoop::TestFunctionWithOutDelegaet);
    RE_DelegateMember1<RE_GameLoop,int,void> Name2(this,&RE_GameLoop::TestFunctionWithOutDelegaet2);

    InputManager->TestDelegate+= Name;
    InputManager->TestDelegate+= Name2;
    Update();
}

void RE_GameLoop::Update()
{
    while (true)
    {
        RenderHandler->RenderStuff();
        EntityManager->UpdateEntities();
        InputManager->RegisterInput();
        SDL_Delay(2000);
        RenderHandler->ClearRender();
    }
}

void RE_GameLoop::TestFunctionWithOutDelegaet(int Number)
{
    printf("Print my number Senpai %i \n", Number);
}

void RE_GameLoop::TestFunctionWithOutDelegaet2(int Number)
{
    printf("Print my number Senpai NUMBER 2 %i \n", Number);

}
