#pragma once
#include <vector>

#include "../_Engine/Objects/RE_Entity.h"

struct RE_BodyPart
{
    SDL_Rect Rect;
    RE_BodyPart* PreviousBodyPart;
};

class RE_Snake :public RE_Entity
{
public:
    void Initialize(RE_RawInputManager* InputManager) override;
    void Start() override;
    void FixedUpdate() override;
    void Draw(SDL_Renderer* Renderer) override;
    void UpdateMoveDirection(Vector NewMoveInput);
private:
    Vector MoveDirection;
    std::vector<RE_BodyPart> BodyParts;
};
