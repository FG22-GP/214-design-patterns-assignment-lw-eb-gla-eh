#pragma once
#include <vector>

class RE_Entity;
class RE_RenderHandler;

class RE_EntityManager
{
public:
    RE_EntityManager(RE_RenderHandler* Renderer);
    void Start();
    void Update(float DeltaTime) const;
    void FixedUpdate(float DeltaTime);

public:
    std::vector<RE_Entity*> Entities;
    RE_RenderHandler* RenderHandler;
};
