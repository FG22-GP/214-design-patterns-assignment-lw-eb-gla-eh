#include "RE_Apple.h"

#include "RE_GameManager.h"

void RE_Apple::Initialize(RE_SubsystemManager* SubsystemManager, RE_RawInputManager* InputManager) {
    RE_Entity::Initialize(SubsystemManager, InputManager);
    RE_GameManager GameManager = SubsystemManager->GetSubsystemOfClass<RE_GameManager>();
    GameManager.RegisterCollider(this);
}

void RE_Apple::Start() {
    RE_Entity::Start();
    Position = GetRandomGridPosition();
}

void RE_Apple::OnCollide(ICollidable* Other) {
    
}

void RE_Apple::Draw(SDL_Renderer* Renderer) {
    RE_Entity::Draw(Renderer);
    
    SDL_SetRenderDrawColor(Renderer, 255  , 0, 0, 255);
    SDL_RenderFillRect(Renderer,&rect);
}

Vector RE_Apple::GetRandomGridPosition() {
    Vector Start = Vector(0,0);
    return Start;
}
