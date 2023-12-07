#pragma once
#include "../_Engine/Objects/RE_Entity.h"

class RE_Grid : public RE_Entity
{
public:
    void Draw(SDL_Renderer* Renderer) override;
private:
    void DrawGrid(SDL_Renderer* Renderer);
private:
    int GridCellSize = 50;
    Color GridColor{255, 0, 0, 255};
};
