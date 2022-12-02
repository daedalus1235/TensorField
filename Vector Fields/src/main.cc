#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <stdio.h>

#include "../include/Ball.h"
#include "../include/Field.h"
#define nl "\n"

typedef long long ll;

using namespace std;

//Screen dimension constants

SDL_Window* window;
SDL_Renderer* renderer;

vector<Ball> balls;
vector<Field> fields;

int InitDisplay();
void drawcircle(int, int, int);
void fillcircle(int, int, int);

int main( int argc, char* args[] )
{

    double pos[] = {640.,100.};
    double vel[] = {0,0};
    Ball testBall(pos, 30);
    balls.push_back(testBall);

    Field testField;

    InitDisplay();

    ll n = 0;

    bool quit = false;
    SDL_Event e;

    bool ready=false;

    while(!ready){
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_KEYDOWN)
                if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) //presses escape
                    ready = true;
        }
    }


    while(!quit){
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT) //closes window
                quit = true;
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) //presses escape
                    quit = true;
            }
        }

        cout<<n<<nl;
        n++;

        if(n%2==0)
            SDL_SetRenderDrawColor (renderer, 0x00, 0x00, 0xFF, 0xFF);
        else{
            SDL_SetRenderDrawColor (renderer, 0xFF, 0x00, 0x00, 0xFF);
        }

        for(vector<Ball>::iterator it = balls.begin(); it != balls.end(); ++it){
            it->render(renderer, {testField});
        }
        SDL_Delay(10);

        SDL_SetRenderDrawColor (renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
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
		window = SDL_CreateWindow( "Bouncing Ball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
        SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
        SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);


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




