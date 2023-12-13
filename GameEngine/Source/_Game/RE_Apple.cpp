#include "RE_Apple.h"

#include <iostream>
#include <random>
#include <string>

#include "RE_GameManager.h"
#include "../ConstValues.h"

void RE_Apple::Initialize(RE_SubsystemManager* SubsystemManager, RE_RawInputManager* InputManager) {
    RE_Entity::Initialize(SubsystemManager, InputManager);
    RE_GameManager* GameManager = SubsystemManager->GetSubsystemOfClass<RE_GameManager>();
    GameManager->RegisterCollider(this);
}

void RE_Apple::Start() {
    RE_Entity::Start();
    SetPosition(GetRandomGridPosition());
}

void RE_Apple::OnCollide(ICollidable* Other) {
    SetPosition(GetRandomGridPosition());
}

void RE_Apple::Draw(SDL_Renderer* Renderer) {
    RE_Entity::Draw(Renderer);
    
    const Vector WorldCoords = RE_Grid::GetMapCoordinates().GetWorldCoordinates(Position);
    Rect = {WorldCoords.X,WorldCoords.Y, GRID_CELL_SIZE,GRID_CELL_SIZE};
    
    SDL_SetRenderDrawColor(Renderer, APPLE.R, APPLE.G, APPLE.B, APPLE.Alpha);
    SDL_RenderFillRect(Renderer,&Rect);
}

Vector RE_Apple::GetRandomGridPosition() {

    srand(time(0));
    std::cout << std::to_string(time(0));
    int RandX = rand() % GRID_WIDTH;
    int RandY = rand() % GRID_HEIGHT;
    printf("\n Rand X: %i",RandX);
    Vector RandomPosition = Vector(RandX,RandY);
    return RandomPosition;
}
