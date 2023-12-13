#pragma once
#include "_Engine/Helpers/RE_Helpers.h"
//Screen dimension constants

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int GRID_CELL_SIZE = 50;
const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 15;

const Color BACKGROUND = Color(55, 163, 75);
const Color GRID = Color(36, 135, 61);
const Color SNAKE_HEAD = Color(136, 0, 209);
const Color SNAKE_BODY_EVEN = Color(66, 135, 245);
const Color SNAKE_BODY_ODD = Color(41, 81, 214);
const Color APPLE = Color(255, 64, 96);

inline const char* pikachuImagePath{ "img/pikachu.png" };
inline const char* LazyFontPath{ "../font/lazy.ttf" };
