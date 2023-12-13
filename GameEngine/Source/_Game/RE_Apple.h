#pragma once
#include "RE_Grid.h"
#include "../_Engine/Interfaces/ICollidable.h"
#include "../_Engine/Objects/RE_Entity.h"
#include "../ConstValues.h"

class RE_Apple : public RE_Entity, public ICollidable{
    
public:
    void Initialize(RE_SubsystemManager* SubsystemManager,RE_RawInputManager* InputManager) override;
    void Start() override;
    void OnCollide(ICollidable* Other) override;
    Vector GetCurrentPosition() override {return Position;}
    void Draw(SDL_Renderer* Renderer) override;
    
public:
    Vector GetRandomGridPosition();
    void SetPosition(Vector Position)
    {
        this->Position = Position;
    }

private:
    Vector Position;
    SDL_Rect Rect;
};
