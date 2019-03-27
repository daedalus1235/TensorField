#include "Field.h"

Field::Field()
{

    //ctor
}

Field::~Field()
{
    //dtor
}


vector<double> Field::getAccel(double (&arr)[2]) {
    vector<double> accel;

    accel.push_back(0);
    accel.push_back(9.81);

    return accel;
}

void Field::render(SDL_Renderer* ren){

}
