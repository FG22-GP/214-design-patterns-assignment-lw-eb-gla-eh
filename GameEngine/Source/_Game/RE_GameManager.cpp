#include "RE_GameManager.h"

void RE_GameManager::RegisterCollider(ICollidable* Collidable) {
    Collidables.push_back(Collidable);
}

void RE_GameManager::CheckCollision() {
    for (auto Collidable : Collidables) {
        for (auto other : Collidables) {
            if(Collidable == other) continue;
            
            if(Collidable->GetCurrentPosition() == other->GetCurrentPosition()) {
                Collidable->OnCollide(other);
            }
        }
    }
}
