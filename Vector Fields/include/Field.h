#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <iostream>
#include <SDL.h>

using namespace std;

class Field
{
    public:
        Field();
        virtual ~Field();
        vector<double> getAccel(double (&arr)[2]);
        void render(SDL_Renderer*);
    protected:

    private:
};

#endif // FIELD_H
