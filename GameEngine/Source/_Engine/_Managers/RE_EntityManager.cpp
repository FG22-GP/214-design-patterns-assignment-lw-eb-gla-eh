#include "RE_EntityManager.h"

#include <SDL_image.h>
#include <SDL_render.h>

#include "RE_RenderHandler.h"
#include "../../_Game/RE_Grid.h"
#include "../../_Game/RE_Snake.h"
#include "../Objects/RE_Entity.h"


RE_EntityManager::RE_EntityManager(RE_RenderHandler* Renderer,RE_RawInputManager* InInputManager)
{
    RenderHandler = Renderer;
    InputManager = InInputManager;
}

void RE_EntityManager::Start()
{
    //RE_Grid* Grid = new RE_Grid();
    
    Entities.push_back(&Grid);
    Entities.push_back(&Snake);
    Entities.push_back(&Apple);
    for (auto Entity : Entities)
    {
        Entity->Initialize(InputManager);
        Entity->Start();
    }
}

void RE_EntityManager::Update(float DeltaTime) const
{
    for (const auto Entity : Entities)
    {
        Entity->Update();
        Entity->Draw(RenderHandler->GetRenderer());
    }
}


void RE_EntityManager::FixedUpdate(float DeltaTime)
{
    for (const auto Entity : Entities)
    {
        Entity->FixedUpdate();
    }
}
