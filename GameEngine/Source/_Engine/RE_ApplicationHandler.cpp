#include "RE_ApplicationHandler.h"

#include <SDL_timer.h>

#include "../_Engine/_Managers/RE_RenderHandler.h"
//#include "../_Game/RE_PickachuEntity.h"
//#include "_Managers/RE_EntityManager.h"

RE_ApplicationHandler::RE_ApplicationHandler(): EntityManager(&RenderHandler), PickaPicka(Vector(200,300))
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
    RenderHandler.ObjectsToRender.push_back(&PickaPicka);
}

void RE_ApplicationHandler::CreateGame()
{
    //RE_PickachuEntity pickachu_entity(Vector(200,300));
    //PickaPicka = new RE_PickachuEntity(Vector(512,300));
    EntityManager.DrawEntity(&PickaPicka);
}

void RE_ApplicationHandler::RunGame()
{
    SDL_SetRenderDrawColor(EntityManager.RenderHandler->GetRenderer(), 0  , 0, 250, 255);
    //SDL_Rect Rect;
    while (true)
    {
        RenderHandler.RenderStuff();
        PickaPicka.Image.Rect.w+=1;
        //SDL_RenderFillRect(EntityManager.RenderHandler->GetRenderer() ,&PickaPicka.Image.Rect);
        //EntityManager.DrawEntity(&PickaPicka);

        //Draw things
        //Get inputs
        //Call Updates
        GetInputs();
        SDL_Delay(10);
        RenderHandler.ClearRender();
    }
}

void RE_ApplicationHandler::GetInputs()
{
}
