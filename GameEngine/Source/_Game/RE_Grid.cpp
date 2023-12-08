#include "RE_Grid.h"
#include <SDL.h>
#include "../ConstValues.h"

void RE_Grid::Draw(SDL_Renderer* Renderer)
{
    DrawGrid(Renderer);
}

void RE_Grid::DrawGrid(SDL_Renderer* Renderer)
{
    SDL_SetRenderDrawColor(Renderer, GridColor.R,GridColor.G,GridColor.B,GridColor.Alpha);
    for (int i = 0; i < SCREEN_HEIGHT; i+= GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(Renderer, 0, i, SCREEN_WIDTH, i);
    }
    for (int i = 0; i < SCREEN_WIDTH; i+= GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(Renderer, i, 0, i, SCREEN_HEIGHT);
    }

}
