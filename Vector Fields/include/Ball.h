#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <vector>

#include <SDL.h>
#include <stdio.h>

#include "Field.h"

using namespace std;

class Ball
{
    public:
        Ball();
        Ball(double (&pos)[2]);
        Ball(double (&pos)[2], double (&vel)[2]);
        virtual ~Ball();

        vector<double> getPos();
        vector<double> getVel();
        int update(vector<Field>);
        void render(SDL_Renderer*);
    protected:

    private:
        double position[2];
        double velocity[2];
        int radius;

};

#endif // BALL_H
