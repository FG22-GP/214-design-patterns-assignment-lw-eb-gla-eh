#pragma once
#include <SDL_stdinc.h>

struct RE_Helpers
{
    //just for the name of the file
};
struct Vector
{
public:
    Vector(){};
    Vector(const float InX, const float InY)
    {
        X=InX;
        Y =InY;
    }
public:
    float X,Y;
    
};
struct Color
{
public:
    Color(int InR, int InG, int InB, int InAlpha)
    {
        R = InR;
        G = InG;
        B = InB;
        Alpha = InAlpha;
    }
    Uint8 R,G,B,Alpha;
};