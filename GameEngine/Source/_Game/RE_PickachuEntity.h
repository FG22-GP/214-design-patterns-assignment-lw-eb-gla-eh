#pragma once
#include "../_Engine/Objects/RE_Entity.h"

class RE_PickachuEntity : public RE_Entity
{
public:
    RE_PickachuEntity();
    RE_PickachuEntity(Vector Position);
    virtual void Draw(SDL_Renderer* Renderer) override;
};
