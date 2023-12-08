#include "RE_Grid.h"
#include <SDL.h>
#include <map>
#include "../ConstValues.h"

RE_MapCoordinates RE_Grid::MapCoordinates;

Vector RE_MapCoordinates::GetWorldCoordinates(Vector GameCoordinates)
{
    return {0,0};
}
void RE_Grid::Start()
{
    int xx = 0,yy = 0;
    for (int x = 0; x < (SCREEN_WIDTH - BorderSize.X) / GRID_CELL_SIZE; ++x)
    {
        for (int y = 0; y < (SCREEN_HEIGHT- BorderSize.Y)/GRID_CELL_SIZE; ++y)
        {
            Vector WorldCoords {x*GRID_CELL_SIZE+BorderSize.X,y*GRID_CELL_SIZE + BorderSize.Y};
            std::tuple<int,int> GameCoords (x,y);
            std::tuple<int,int> WorldCoordsTuple (WorldCoords.X,WorldCoords.Y);
            //MapCoordinates.DOThing();
            MapCoordinates.GameToWorldCoords.insert_or_assign(GameCoords,WorldCoordsTuple);
        }
    }
}

void RE_Grid::Draw(SDL_Renderer* Renderer)
{
    DrawGrid(Renderer);
}

void RE_Grid::DrawGrid(SDL_Renderer* Renderer)
{
    SDL_SetRenderDrawColor(Renderer, GridColor.R,GridColor.G,GridColor.B,GridColor.Alpha);
    for (int i = BorderSize.Y; i < SCREEN_HEIGHT; i+= GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(Renderer, BorderSize.X, i, SCREEN_WIDTH, i);
    }
    for (int i = BorderSize.X; i < SCREEN_WIDTH; i+= GRID_CELL_SIZE)
    {
        SDL_RenderDrawLine(Renderer, i, BorderSize.Y, i, SCREEN_HEIGHT);
    }

}
