#pragma once
#include "../_Engine/Interfaces/ICollidable.h"
#include "../_Engine/Objects/RE_Entity.h"

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
        rect.x = Position.X;
        rect.y = Position.Y;
        this->Position = Position;
    }

private:
    Vector Position;
    SDL_Rect rect;
};
