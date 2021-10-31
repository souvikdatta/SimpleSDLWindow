#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

void showError(string errString)
{
    std::cout << errString << endl;
}

int main(int argc, char **argv)
{
    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        //Create window
        g_pWindow = SDL_CreateWindow("Chapter 1", SDL_WINDOWPOS_CENTERED, \
            SDL_WINDOWPOS_CENTERED, 640, 480,SDL_WINDOW_SHOWN);

        //If window creation is successful, then create the render
        if(g_pWindow)
        {
            // g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
            if(!g_pRenderer)
            {
                showError("Failed to create SDL Renderer!!");    
            }    
        }
        else
        {
            showError("Failed to create SDL Window!!");
        }
    }
    else
    {
        showError("Failed to initialize SDL!!");
        return 1;
    }

    //Now set rendering color to Blue
    SDL_SetRenderDrawColor(g_pRenderer,255 , 0, 255, 255);

    //MOST IMPORTANT Stage
    SDL_RenderClear (g_pRenderer);

    //Show the window
    SDL_RenderPresent (g_pRenderer);

    //Show it for 5 secs
    SDL_Delay(5000);

    //Cleanup
    SDL_Quit();

    return 0;
}

