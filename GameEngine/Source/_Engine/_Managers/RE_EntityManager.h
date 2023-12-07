#pragma once
#include <vector>

class RE_Entity;
class RE_RenderHandler;

class RE_EntityManager
{
public:
    RE_EntityManager(RE_RenderHandler* Renderer);
    void Start();
    void UpdateEntities() const;

public:
    std::vector<RE_Entity*> Entities;
    RE_RenderHandler* RenderHandler;
};
