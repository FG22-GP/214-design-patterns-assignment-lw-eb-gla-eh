#include "RE_ApplicationHandler.h"

#include <SDL_timer.h>

#include "../_Engine/_Managers/RE_RenderHandler.h"
#include "../_Game/RE_PickachuEntity.h"
#include "_Managers/RE_EntityManager.h"

void RE_ApplicationHandler::Run()
{
    CreateWindow();
    CreateGame();
    RunGame();
}

void RE_ApplicationHandler::CloseApplication()
{
    delete RenderHandler;
}

void RE_ApplicationHandler::CreateWindow()
{
    RenderHandler = new RE_RenderHandler();
    RenderHandler->CreateWindow();
    EntityManager = new RE_EntityManager(RenderHandler);
    //render_handler->RenderStuff();
}

void RE_ApplicationHandler::CreateGame()
{
    RE_PickachuEntity* PickaPicka = new RE_PickachuEntity(Vector(512,300));
    EntityManager->DrawEntity(PickaPicka);
}

void RE_ApplicationHandler::RunGame()
{
    while (true)
    {
        //Draw things
        //Get inputs
        //Call Updates
        GetInputs();
        SDL_Delay(0);
        RenderHandler->ClearRender();
    }
}

void RE_ApplicationHandler::GetInputs()
{
}
