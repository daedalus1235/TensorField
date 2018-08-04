#include <iostream>
#include <vector>

#include <SDL.h>
#include <stdio.h>

#include "Ball.h"
#include "Field.h"
#define nl "\n"

#include <SDL.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window;
SDL_Renderer* renderer;

int InitDisplay();
void drawcircle(int, int, int);
void fillcircle(int, int, int);

int main( int argc, char* args[] )
{
    InitDisplay();

    ll n = 0;
    double pos[2];
    double vel[2];
    Field* test = new Field();

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT) //closes window
                quit = true;
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) //presses escape
                    quit = true;
            }
        }

        pos[0]=n;
        pos[1]=2*n;
        vel[0]=test->getAccel(pos)[0];
        vel[1]=test->getAccel(pos)[1];
        cout<<vel[0]<<", "<<vel[1]<<nl;
        n++;

        if(n%2==0)
            SDL_SetRenderDrawColor (renderer, 0x00, 0x00, 0xFF, 0xFF);
        else{
            SDL_SetRenderDrawColor (renderer, 0xFF, 0x00, 0x00, 0xFF);
        }


        fillcircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 100);


    }

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

int InitDisplay(){
    SDL_Window* window = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}
	else{
		//Create window
		window = SDL_CreateWindow( "Loading Icon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ){
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return -2;
		}
		else{
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL ){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                return -3;
            }
            else{
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear(renderer);

                SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
                SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect( renderer, &fillRect );
                SDL_RenderPresent (renderer);
            }
		}
	}
	return 0;
}

void drawcircle(int x0, int y0, int radius){
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        //compute first octant, render in other 7
        SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
        SDL_RenderPresent (renderer);


        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void fillcircle(int x0, int y0, int radius){
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        //compute first octant, render in other 7
        SDL_RenderDrawLine(renderer, x0, y0, x0 + x, y0 + y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 + y, y0 + x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 - y, y0 + x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 - x, y0 + y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 - x, y0 - y);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 - y, y0 - x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 + y, y0 - x);
        SDL_RenderPresent (renderer);

        SDL_RenderDrawLine(renderer, x0, y0, x0 + x, y0 - y);
        SDL_RenderPresent (renderer);


        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}


