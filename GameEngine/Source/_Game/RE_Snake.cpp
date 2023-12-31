﻿#include "RE_Snake.h"

#include "RE_GameManager.h"
#include "../_Engine/_Managers/RE_RawInputManager.h"

RE_Snake::RE_Snake()
{
}

RE_Snake::~RE_Snake()
{
    for (auto& BodyPart : BodyParts)
    {
        delete BodyPart;
    }
}

void RE_Snake::Initialize(RE_SubsystemManager* SubsystemManager, RE_RawInputManager* InputManager)
{
    InputManager->OnMoveInputUpdated+= RE_DelegateMember1(this, &RE_Snake::UpdateMoveDirection);
    RE_GameManager* GameManager = SubsystemManager->GetSubsystemOfClass<RE_GameManager>();
    GameManager->RegisterCollider(this);
}

void RE_Snake::Start()
{
    CreateStartingBodyParts();
    
}

void RE_Snake::FixedUpdate()
{
    MoveSnake();
    if (HasEatenItself())
    {
        printf("Game Over: Ate yourself\n");
        //Game Over;
    }
    if (RE_Grid::GetMapCoordinates().IsOutsideTheMap(GetHeadPart()->CurrentPosition))
    {
        printf("Game Over Hit The Wall\n");
    }

    OnSnakeStepped.BroadCast(GetHeadPart()->CurrentPosition);
}

void RE_Snake::MoveSnake() const
{
    const int Size = static_cast<int>(BodyParts.size());
    GetHeadPart()->Direction = MoveDirection;
    GetHeadPart()->Move();
    for (int i = Size-1; i > 0; --i)
    {
        BodyParts[i]->Move();
        BodyParts[i]->Direction = BodyParts[i-1]->Direction;
    }
}

bool RE_Snake::HasEatenItself()
{
    for (int i = 1; i < BodyParts.size(); ++i)
    {
        if (BodyParts[i]->CurrentPosition == GetHeadPart()->CurrentPosition)
        {
            return true;
        }
    }

    return false;
}

void RE_Snake::Draw(SDL_Renderer* Renderer)
{
    //Draw body parts
    const int Size = static_cast<int>(BodyParts.size());

    RE_BodyPart* BodyPart = nullptr;
    for (int i = Size-1; i >= 0; --i)
    {
        BodyPart = BodyParts[i];
        if (!BodyPart) return;
        
        SDL_SetRenderDrawColor(Renderer, BodyPart->Color.R  , BodyPart->Color.G, BodyPart->Color.B, BodyPart->Color.Alpha);
        SDL_RenderFillRect(Renderer,&BodyPart->Rect);
    }

}

void RE_Snake::UpdateMoveDirection(Vector NewMoveInput)
{
    //TODO: we should compare to the heads direction
    if (GetHeadPart()->Direction.X !=0 && NewMoveInput.Y != 0)
    {
        MoveDirection.X = 0;
        MoveDirection.Y = NewMoveInput.Y;
    }
    else if (GetHeadPart()->Direction.Y !=0 && NewMoveInput.X != 0)
    {
        MoveDirection.Y = 0;
        MoveDirection.X = NewMoveInput.X;
    }
}

void RE_Snake::OnCollide(ICollidable* Other) {
    CreateBodyPart();
}

void RE_Snake::CreateStartingBodyParts()
{
    // CreateHeadPart
    
    BodyParts.push_back(new RE_BodyPart(SnakeStartPos, MoveDirection,SNAKE_HEAD));
    for (int i = 0; i < StartingSnakeSize; ++i)
    {
        CreateBodyPart();
    }
}


void RE_Snake::CreateBodyPart()
{
    const RE_BodyPart& LastBodyPart = *BodyParts[BodyParts.size()-1];
    RE_BodyPart* NewBodyPart = new RE_BodyPart(LastBodyPart);
    if (BodyParts.size()%2 == 0)
    {
        NewBodyPart->Color = SNAKE_BODY_EVEN;
    }
    else
    {
        NewBodyPart->Color =SNAKE_BODY_ODD;
    }
    BodyParts.push_back(NewBodyPart);
   
}

