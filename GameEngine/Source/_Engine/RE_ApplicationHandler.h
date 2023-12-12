#pragma once
#include "RE_GameLoop.h"
#include "_Managers/RE_EntityManager.h"
#include "_Managers/RE_RawInputManager.h"
#include "_Managers/RE_RenderHandler.h"
#include "_Managers/RE_SubsystemManager.h"

class RE_EntityManager;
class RE_Entity;
class RE_RenderHandler;
class RE_SubsystemManager;

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
private:
    RE_RenderHandler RenderHandler;
    RE_EntityManager EntityManager;
    RE_RawInputManager InputManager;
    RE_SubsystemManager SubsystemManager;
    RE_GameLoop GameLoop;
};
