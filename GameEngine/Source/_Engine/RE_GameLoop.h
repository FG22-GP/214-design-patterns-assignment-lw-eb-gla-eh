#pragma once
#include "ObserverPattern/RE_DelegateBase.h"

class RE_RawInputManager;
class RE_EntityManager;
class RE_RenderHandler;

class RE_GameLoop
{
public:
    RE_GameLoop(RE_RenderHandler* RenderHandler, RE_EntityManager* EntityManager, RE_RawInputManager* InputManager);
    void Start();
    void Update();
    void FixedUpdate();
    void TestFunctionWithOutDelegaet(int Number);
    void TestFunctionWithOutDelegaet2(int Number);

private:
    RE_RenderHandler* RenderHandler;
    RE_EntityManager* EntityManager;
    RE_RawInputManager* InputManager;
};
