#include "RE_PickachuEntity.h"


RE_PickachuEntity::RE_PickachuEntity(Vector Position)
{
    Image.Rect.x = Position.X;
    Image.Rect.y = Position.Y;
}

void RE_PickachuEntity::Draw(SDL_Renderer* Renderer)
{
    SDL_RenderFillRect(Renderer,&Image.Rect);
}
