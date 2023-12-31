﻿#pragma once
#include <vector>

#include "RE_Grid.h"
#include "../ConstValues.h"
#include "../_Engine/Interfaces/ICollidable.h"
#include "../_Engine/Objects/RE_Entity.h"
#include "../_Engine/ObserverPattern/RE_DelegateBase.h"

struct RE_BodyPart
{
public:
    RE_BodyPart(const Vector InCurrentPosition, Vector InDirection = {0,0}, Color InColor = {})
    {
        CurrentPosition= InCurrentPosition;
        const Vector WorldCoords = RE_Grid::GetMapCoordinates().GetWorldCoordinates(CurrentPosition);
        Rect ={WorldCoords.X,WorldCoords.Y, GRID_CELL_SIZE,GRID_CELL_SIZE};
        Direction = InDirection;
        Color = InColor;
    }
    RE_BodyPart(const RE_BodyPart& OtherBodyPart)
    {
        CurrentPosition = OtherBodyPart.CurrentPosition;
        Rect= OtherBodyPart.Rect;
        Direction= {0,0};
    }
    void Move()
    {
        Rect.x+= Direction.X * GRID_CELL_SIZE;
        Rect.y+= Direction.Y * GRID_CELL_SIZE;
        CurrentPosition ={Rect.x/GRID_CELL_SIZE,Rect.y/GRID_CELL_SIZE};
    };
    SDL_Rect Rect;
    Color Color;
    Vector Direction;
    Vector CurrentPosition;

};

class RE_Snake :public RE_Entity, public ICollidable
{
public:
    RE_Snake();
    virtual ~RE_Snake();
    void Initialize(RE_SubsystemManager* SubsystemManager,RE_RawInputManager* InputManager) override;
    void Start() override;
    void FixedUpdate() override;
    void Draw(SDL_Renderer* Renderer) override;
    void UpdateMoveDirection(Vector NewMoveInput);
    void OnCollide(ICollidable* Other) override;
    Vector GetCurrentPosition() override {return GetHeadPart()->CurrentPosition;}
private:
    void CreateStartingBodyParts();
    void CreateBodyPart();
    void MoveSnake() const;
    bool HasEatenItself();
    RE_BodyPart* GetHeadPart() const { return BodyParts[0];}
    
public:
    RE_MulticastDelegate1<Vector> OnSnakeStepped;
private:
    const Vector SnakeStartPos = {8,6};
    //Amount of squares for the snake in addition to the head
    int StartingSnakeSize = 5;
    Vector MoveDirection = {1,0};
    std::vector<RE_BodyPart*> BodyParts;
};
