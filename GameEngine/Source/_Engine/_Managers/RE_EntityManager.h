#pragma once
#include <vector>

#include "../../_Game/RE_Grid.h"
#include "../../_Game/RE_Snake.h"

class RE_Entity;
class RE_RenderHandler;

class RE_EntityManager
{
public:
    RE_EntityManager(RE_RenderHandler* Renderer,RE_RawInputManager* InInputManager);
    
    void Start();
    void Update(float DeltaTime) const;
    void FixedUpdate(float DeltaTime);

public:
    std::vector<RE_Entity*> Entities;
    RE_RenderHandler* RenderHandler;
    RE_RawInputManager* InputManager;

private:
    RE_Grid Grid;
    RE_Snake Snake;
};
