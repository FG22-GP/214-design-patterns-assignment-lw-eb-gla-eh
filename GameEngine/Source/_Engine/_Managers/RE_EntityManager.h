#pragma once
#include <vector>

#include "../../_Game/RE_Grid.h"
#include "../../_Game/RE_Snake.h"
#include "../../_Game/RE_Apple.h"

class RE_Entity;
class RE_RenderHandler;

class RE_EntityManager
{
public:
    RE_EntityManager(RE_RenderHandler* Renderer,RE_SubsystemManager* SubsystemManager ,RE_RawInputManager* InInputManager);
    
    void Start();
    void Update(float DeltaTime) const;
    void FixedUpdate(float DeltaTime);

public:
    RE_RenderHandler* RenderHandler;
    RE_RawInputManager* InputManager;
    RE_SubsystemManager* SubsystemManager;

private:
    std::vector<RE_Entity*> Entities;
};
