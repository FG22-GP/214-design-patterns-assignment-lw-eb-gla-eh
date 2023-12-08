#include "RE_Snake.h"

#include "../ConstValues.h"
#include "../_Engine/_Managers/RE_RawInputManager.h"

void RE_Snake::Initialize(RE_RawInputManager* InputManager)
{
    InputManager->OnMoveInputUpdated+= RE_DelegateMember1(this, &RE_Snake::UpdateMoveDirection);
}

void RE_Snake::Start()
{
    MoveDirection.X = 1;
    RE_BodyPart FirstBodyPart;
    FirstBodyPart.Rect.h = GRID_CELL_SIZE;
    FirstBodyPart.Rect.w =GRID_CELL_SIZE;
    FirstBodyPart.Rect.x = GRID_CELL_SIZE * 8;
    FirstBodyPart.Rect.y = GRID_CELL_SIZE * 6;
    
    BodyParts.push_back(FirstBodyPart);
}

void RE_Snake::FixedUpdate()
{
    for (auto& BodyPart : BodyParts)
    {
        BodyPart.Rect.x += MoveDirection.X * GRID_CELL_SIZE;
        BodyPart.Rect.y += MoveDirection.Y * GRID_CELL_SIZE;
    }
}

void RE_Snake::Draw(SDL_Renderer* Renderer)
{
    SDL_SetRenderDrawColor(Renderer, 0  , 0, 255, 255);
    for (auto& BodyPart : BodyParts)
    {
        SDL_RenderFillRect(Renderer,&BodyPart.Rect);
    }
}

void RE_Snake::UpdateMoveDirection(Vector NewMoveInput)
{
    if (MoveDirection.X !=0 && NewMoveInput.Y != 0)
    {
        MoveDirection.X = 0;
        MoveDirection.Y = NewMoveInput.Y;
    }
    else if (MoveDirection.Y !=0 && NewMoveInput.X != 0)
    {
        MoveDirection.Y = 0;
        MoveDirection.X = NewMoveInput.X;
    }
}
