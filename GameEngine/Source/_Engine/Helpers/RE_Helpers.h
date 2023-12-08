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
    bool operator==(const Vector& Other) const
    {
        return (X==Other.X && Y == Other.Y);
    }
    bool operator!=(const Vector& Other) const
    {
        return (X!=Other.X || Y != Other.Y);
    }
    // void operator=(const Vector& Other)
    // {
    //     X= Other.X;
    //     Y=Other.Y;
    // }


    
};
struct Color
{
public:
    Color()
    {
        R = 255;
        G = 255;
        B = 255;
        Alpha = 255;
    };
    Color(const Uint8 InR, const Uint8 InG = 255, const Uint8 InB = 255, const Uint8 InAlpha = 255)
    {
        R = InR;
        G = InG;
        B = InB;
        Alpha = InAlpha;
    }
    Uint8 R,G,B,Alpha;
};