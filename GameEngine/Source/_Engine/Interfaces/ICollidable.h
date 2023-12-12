#pragma once
#include "../Helpers/RE_Helpers.h"

class ICollidable {
public:
    virtual void OnCollide(ICollidable* Other) = 0;
    virtual Vector GetCurrentPosition() = 0;
};
