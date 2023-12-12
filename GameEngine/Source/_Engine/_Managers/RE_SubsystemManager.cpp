#include "RE_SubsystemManager.h"

#include "../../_Game/RE_GameManager.h"

void RE_SubsystemManager::Start() {

    SubsystemBases.push_back(new RE_GameManager);
    
}

void RE_SubsystemManager::FixedUpdate(float DeltaTime) {
    
    for (const auto Base : SubsystemBases)
    {
        Base->FixedUpdate(DeltaTime);
    }
}
