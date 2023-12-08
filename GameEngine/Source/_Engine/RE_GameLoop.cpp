#include "RE_GameLoop.h"

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

    InputManager->TestDelegate+= RE_DelegateMember1(this,&RE_GameLoop::TestFunctionWithOutDelegaet);
    
    Update();
}

void RE_GameLoop::Update()
{
    SDL_Event e; bool quit = false;
    
    while (quit == false)
    {
        RenderHandler->RenderStuff();
        EntityManager->UpdateEntities();
        InputManager->RegisterInput();
        
        while (SDL_PollEvent(&e))
        {
            // check, if it's an event we want to react to:
            switch (e.type) {
                case SDL_QUIT: {
                        quit = true;
                } break;
            } 
        }
        
        SDL_Delay(0);
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
