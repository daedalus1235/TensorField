#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <vector>
#include <cmath>

#include <stdio.h>
#include <stdarg.h>

#include <SDL2/SDL.h>


#include "Field.h"

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Ball
{
    public:
        Ball();
        Ball(double (&pos)[2]);
        Ball(double (&pos)[2],int);
        Ball(double (&pos)[2], double (&vel)[2]);
        virtual ~Ball();

        vector<double> getPos();
        vector<double> getVel();
        int update(vector<Field>);
        void render(SDL_Renderer*, vector<Field>);
    protected:

    private:
        double position[2];
        double velocity[2];
        int radius;
        void fillcircle(SDL_Renderer*,int,int,int);
        double dt = .01;
        enum basis {X,Y};

};

#endif // BALL_H
