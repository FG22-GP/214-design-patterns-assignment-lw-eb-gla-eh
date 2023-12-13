#include "RE_SubsystemManager.h"

#include "../../_Game/RE_GameManager.h"

void RE_SubsystemManager::Start() {

    RE_GameManager* NewGameManager = new RE_GameManager;
    SubsystemBases.push_back(NewGameManager);
    
}

void RE_SubsystemManager::FixedUpdate(float DeltaTime) {
    
    for (const auto Base : SubsystemBases)
    {
        Base->FixedUpdate(DeltaTime);
    }
}
