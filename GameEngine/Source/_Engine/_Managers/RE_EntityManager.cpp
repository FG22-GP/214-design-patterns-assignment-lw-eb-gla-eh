#include "RE_EntityManager.h"

#include <SDL_image.h>
#include <SDL_render.h>

#include "RE_RenderHandler.h"
#include "../Objects/RE_Entity.h"


RE_EntityManager::RE_EntityManager(RE_RenderHandler* Renderer)
{
    RenderHandler = Renderer;
}

void RE_EntityManager::CreateEntity(RE_Entity* Entity)
{
    Entities.push_back(Entity);
}

void RE_EntityManager::DrawEntity(RE_Entity* Entity)
{
    SDL_Surface* loadedSurface = IMG_Load("img/pikachu.png");

    Entity->Image.Texture = SDL_CreateTextureFromSurface(RenderHandler->GetRenderer(), loadedSurface);
    
    SDL_RenderCopy(RenderHandler->GetRenderer(), Entity->Image.Texture, NULL, &Entity->Image.Rect);

}
