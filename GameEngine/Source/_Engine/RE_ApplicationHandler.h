#pragma once

class RE_EntityManager;
class RE_Entity;
class RE_RenderHandler;

class RE_ApplicationHandler
{
    
public:
    void Run();
    void CloseApplication();
private:
    void CreateWindow();
    void CreateGame();
    void RunGame();
    void GetInputs();
private:
    RE_RenderHandler* RenderHandler;
    RE_EntityManager* EntityManager;
};
