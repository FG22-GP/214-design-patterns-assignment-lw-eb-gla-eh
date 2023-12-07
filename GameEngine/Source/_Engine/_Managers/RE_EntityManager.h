#pragma once
#include <vector>

class RE_Entity;
class RE_RenderHandler;

class RE_EntityManager
{
public:
    RE_EntityManager(RE_RenderHandler* Renderer);
    void CreateEntity(RE_Entity* Entity);
    void DrawEntity(RE_Entity* Entity);

public:
    std::vector<RE_Entity*> Entities;
    RE_RenderHandler* RenderHandler;
};
