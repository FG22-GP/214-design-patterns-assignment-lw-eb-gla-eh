#include "RE_RawInputManager.h"

#include <SDL_keyboard.h>
#include <SDL_stdinc.h>


void RE_RawInputManager::RegisterInput()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_W])
    {
        MoveInput.Y = 1;
    }
    else if (keystate[SDL_SCANCODE_S])
    {
        MoveInput.Y = -1;
    }
    else
    {
        MoveInput.Y = 0;
    }
    
    if (keystate[SDL_SCANCODE_A])
    {
        MoveInput.X = -1;
    }
    else if (keystate[SDL_SCANCODE_D])
    {
        MoveInput.X = 1;
    }
    else
    {
        MoveInput.Y = 0;
    }
    int Number = 5;

    TestDelegate.BroadCast(Number);
}
