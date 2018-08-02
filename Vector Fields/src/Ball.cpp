#include "Ball.h"

Ball::Ball(){
    //ctor
}

Ball::Ball(double (&pos)[2]){

}

Ball::Ball(double (&pos)[2], double (&vel)[2]){

}

Ball::~Ball(){
    //dtor
}

vector<double> Ball::getPos(){

}

vector<double> Ball::getVel(){

}

int Ball::update(vector<Field> fields){
    for(vector<Field>::iterator it = fields.begin(); it != fields.end(); ++it){

    }

    return 0;
}
