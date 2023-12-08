#pragma once
#include <SDL_stdinc.h>

struct RE_Helpers
{
    //just for the name of the file
};
struct Vector
{
public:
    Vector(){}
    Vector(const int InX, const int InY)
    {
        X=InX;
        Y =InY;
    }
public:
    int X,Y;
    
};
struct Color
{
public:
    Color(const Uint8 InR, const Uint8 InG, const Uint8 InB, const Uint8 InAlpha)
    {
        R = InR;
        G = InG;
        B = InB;
        Alpha = InAlpha;
    }
    Uint8 R,G,B,Alpha;
};