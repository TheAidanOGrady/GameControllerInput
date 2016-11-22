/******************************************************************************
 *
 * @file    controller.h
 * @author  Aidan O'Grady
 * @date    2016-11-21
 * @version 0.4
 *
 * The controller version of user input. Inputs from a controller are converted
 * into commands recognized by the system.
 *
 ******************************************************************************/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "keydata.h"
#include "controller.h"

/**
 * The deadzone of the controller, input is ignored inside this limit.
 */
const int DEAD_ZONE = 8000;

/**
 * The controller to read data from.
 */
SDL_GameController* controller = NULL;

/**
 * Initialises the controller, ensuring that it is connected.
 */
bool controller_init() {
    for (int i = 0; i < SDL_NumJoysticks(); i++)
    {
        if (SDL_IsGameController(i))
        {
            controller = SDL_GameControllerOpen(i);
            if (controller)
            {
                return true;
            }
            else
            {
                printf("SDL_Error controller: %s\n", SDL_GetError());
                return false;
            }
        }
    }

    if (controller == NULL)
    {
        printf("SDL_Error controller: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void move(Cursor* k_cursor)
{
    int x = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
    int y = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
    if (x > DEAD_ZONE)
    {
        k_cursor->x = (k_cursor->x + 1) % (COLS - k_cursor->size + 1);
    }
    else if (x < -DEAD_ZONE)
    {
        k_cursor->x = k_cursor->x - 1;
        if (k_cursor->x < 0)
        {
            k_cursor->x = COLS - k_cursor->size;
        }
    }
    else if (y > DEAD_ZONE)
    {
        k_cursor->y = (k_cursor->y + 1) % (ROWS - k_cursor->size + 1);
    }
    else if (y < -DEAD_ZONE)
    {
        k_cursor->y = k_cursor->y - 1;
        if (k_cursor->y < 0)
        {
            k_cursor->y = ROWS - k_cursor->size;
        }
    }
}

/**
 * Graceful close of the controller.
 */
void controller_close()
{
    SDL_GameControllerClose(controller);
    controller = NULL;
}