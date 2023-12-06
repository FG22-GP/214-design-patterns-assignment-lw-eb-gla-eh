#pragma once
#include "RE_Image.h"
#include <memory>

extern class IImageLoader;

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Whether Window Startup was successful
	bool success;
	// dependency to the ImageLoader
	IImageLoader* imageLoader;
	SDL_Renderer* renderer;
public:
	Window(int width, int height, IImageLoader* imageLoader);
	~Window();
	bool wasSuccessful() { return success; }
	void render(RE_Image* image);
	void clear();
	void present();
	std::unique_ptr<RE_Image> loadImage(const char* path);
};

