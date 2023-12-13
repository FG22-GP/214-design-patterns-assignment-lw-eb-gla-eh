#pragma once
#include <map>

#include "../ConstValues.h"
#include "../_Engine/Objects/RE_Entity.h"

struct RE_MapCoordinates
{
    //std::vector<Vector> Coordinates; 
    
    std::map<std::tuple<int,int>,std::tuple<int,int>> GameToWorldCoords;
    Vector GetWorldCoordinates(const Vector& GameCoordinates) const;
    bool IsOutsideTheMap(const Vector& GameCoordinates)const;
    
    
    
};
class RE_Grid : public RE_Entity
{
public:
    static const RE_MapCoordinates& GetMapCoordinates() { return MapCoordinates; }
public:
    void Start() override;
    void Draw(SDL_Renderer* Renderer) override;
private:
    void DrawGrid(SDL_Renderer* Renderer);
private:
    std::map<std::tuple<int,int>,std::tuple<int,int>> GameToWorldCoords;

    static RE_MapCoordinates MapCoordinates;
    Vector BorderSize = {GRID_WIDTH,GRID_HEIGHT};
};
