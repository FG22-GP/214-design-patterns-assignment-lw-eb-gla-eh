#pragma once
#include <vector>

#include "../../_Game/RE_GameManager.h"

class RE_SubsystemBase;

class RE_SubsystemManager
{
public:
    void Start();
    void FixedUpdate(float DeltaTime);

    template<class t>
    t* GetSubsystemOfClass();
    
public:
    std::vector<RE_SubsystemBase*> SubsystemBases;
};

template <class t>
t* RE_SubsystemManager::GetSubsystemOfClass() {
    
    for (auto Base : SubsystemBases) {
        t* Subsystem = dynamic_cast<t*>(Base);
        if(Subsystem != nullptr) {
            return Subsystem;
        }
    }
    return nullptr;
}
