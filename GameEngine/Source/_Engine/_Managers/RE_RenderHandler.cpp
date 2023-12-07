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
    // // All data related to pikachu
    // SDL_Texture* pikachu = NULL; // The final optimized image
    // bool pikachuMoveRight = false;
    // int pik_x, pik_y;
    //
    // pik_x = pik_y = 0;
    // int pik_w, pik_h;
    // pik_w = pik_h = 200;
    // //Load image at specified path
    // SDL_Surface* loadedSurface = IMG_Load(pikachuImagePath);
    // if (loadedSurface == NULL)
    // {
    //     printf("Unable to load image %s! SDL_image Error: %s\n", pikachuImagePath, IMG_GetError());
    //     //return -1;
    // }
    // else
    // {
    //     //Convert surface to screen format
    //     pikachu = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
    //     if (pikachu == NULL)
    //     {
    //         printf("Unable to create texture from %s! SDL Error: %s\n", pikachuImagePath, SDL_GetError());
    //         //return -1;
    //     }
    //
    //     SDL_FreeSurface(loadedSurface);
    // }
    // // render Pikachu
    // SDL_Rect targetRectangle{
    //     pik_x,
    //     pik_y,
    //     pik_w,
    //     pik_h
    // };
    //SDL_RenderClear(Renderer);
    //
    // SDL_RenderCopy(Renderer, pikachu, NULL, &targetRectangle);
    // present screen (switch buffers)
    // SDL_RenderPresent(Renderer);
    // SDL_SetRenderDrawColor(Renderer, 0  , 143, 50, 255);
    // SDL_RenderClear(Renderer);

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

