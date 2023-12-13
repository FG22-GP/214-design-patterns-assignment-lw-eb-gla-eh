#pragma once
#include <vector>

#include "../_Engine/Interfaces/ICollidable.h"
#include "../_Engine/Objects/RE_SubsystemBase.h"

class RE_GameManager: public RE_SubsystemBase{
public:
    void RegisterCollider(ICollidable* Collidable);

    void FixedUpdate(float DeltaTime) override;
    //~RE_GameManager() override;

private:
    void CheckCollision();
    
public:
    std::vector<ICollidable*> Collidables;
    
};
