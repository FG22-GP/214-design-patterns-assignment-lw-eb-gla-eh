#pragma once
#include "../_Game/RE_PickachuEntity.h"
#include "_Managers/RE_EntityManager.h"
#include "_Managers/RE_RenderHandler.h"

class RE_EntityManager;
class RE_Entity;
class RE_RenderHandler;

class RE_ApplicationHandler
{
    
public:
    RE_ApplicationHandler();
    void Run();
    void CloseApplication();
private:
    void CreateWindow();
    void CreateGame();
    void RunGame();
    void GetInputs();
private:
    RE_RenderHandler RenderHandler;
    RE_EntityManager EntityManager;
    RE_PickachuEntity PickaPicka;
};
