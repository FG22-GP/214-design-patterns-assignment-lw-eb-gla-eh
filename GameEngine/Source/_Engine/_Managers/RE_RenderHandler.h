#pragma once
class RE_ApplicationHandler;
struct Color;
class RE_Entity;
class SDL_Window;
class SDL_Renderer;

class RE_RenderHandler
{
public:
    RE_RenderHandler();

    SDL_Renderer* GetRenderer() const {return Renderer;}
    
    void CreateWindow();
    void RenderStuff();
    void ClearRender();
private:
    void DrawBackground(Color BackgroundColor) const;
private:
    SDL_Window* Window{};
    SDL_Renderer* Renderer;
};



