#include "RE_RenderHandler.h"

#include <cstdio>
#include <SDL_image.h>

#include "../RE_Image.h"
#include "../../ConstValues.h"
#include "../Objects/RE_Entity.h"

RE_RenderHandler::RE_RenderHandler()
{
}

void RE_RenderHandler::CreateWindow()
{
    int imgFlags = IMG_INIT_PNG;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &Window, &Renderer);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(Renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    DrawBackground(Color(0  , 143, 50, 255));
}

void RE_RenderHandler::RenderStuff()
{
    for (INeedToRender* Object : ObjectsToRender)
    {
        Object->Draw(Renderer);
    }
}

void RE_RenderHandler::ClearRender()
{
    SDL_RenderPresent(Renderer);
}


void RE_RenderHandler::DrawBackground(const Color BackgroundColor) const
{
    SDL_SetRenderDrawColor(Renderer, BackgroundColor.R  , BackgroundColor.G, BackgroundColor.B, BackgroundColor.Alpha);
    SDL_RenderClear(Renderer);
}

