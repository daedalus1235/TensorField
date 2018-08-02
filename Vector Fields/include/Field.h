#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <iostream>

using namespace std;

class Field
{
    public:
        Field();
        virtual ~Field();
        vector<double> getAccel(double (&arr)[2]);
    protected:

    private:
};

#endif // FIELD_H
