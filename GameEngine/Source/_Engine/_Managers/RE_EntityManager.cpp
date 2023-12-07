#include "RE_EntityManager.h"

#include <SDL_image.h>
#include <SDL_render.h>

#include "RE_RenderHandler.h"
#include "../../_Game/RE_Grid.h"
#include "../Objects/RE_Entity.h"


RE_EntityManager::RE_EntityManager(RE_RenderHandler* Renderer)
{
    RenderHandler = Renderer;
}

void RE_EntityManager::Start()
{
    //Create snake and first apple.
    RE_Grid* Grid = new RE_Grid();
    Entities.push_back(Grid);
}


void RE_EntityManager::UpdateEntities() const
{
    for (const auto Entity : Entities)
    {
        Entity->Update();
        Entity->Draw(RenderHandler->GetRenderer());
    }
}
