#include "RE_ApplicationHandler.h"

#include <SDL_timer.h>

#include "../_Engine/_Managers/RE_RenderHandler.h"
//#include "../_Game/RE_PickachuEntity.h"
//#include "_Managers/RE_EntityManager.h"

RE_ApplicationHandler::RE_ApplicationHandler(): EntityManager(&RenderHandler), GameLoop(&RenderHandler,&EntityManager, &InputManager)
{
}

void RE_ApplicationHandler::Run()
{
    CreateWindow();
    CreateGame();
    RunGame();
}

void RE_ApplicationHandler::CloseApplication()
{
}

void RE_ApplicationHandler::CreateWindow()
{
    RenderHandler.CreateWindow();
    //render_handler->RenderStuff();
}

void RE_ApplicationHandler::CreateGame()
{
}

void RE_ApplicationHandler::RunGame()
{
    //SDL_Rect Rect;
    GameLoop.Start();
}


