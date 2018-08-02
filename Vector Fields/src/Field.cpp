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

    accel.push_back(arr[0]);
    accel.push_back(arr[1]);

    return accel;
}
