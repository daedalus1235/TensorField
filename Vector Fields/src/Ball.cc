#include "../include/Ball.h"

Ball::Ball(){
    //ctor
}

Ball::Ball(double (&pos)[2]){
    position[X] = pos[X];
    position[Y] = pos[Y];
    velocity[X] = 300;
    velocity[Y] = 0;
    radius = 50;
}

Ball::Ball(double (&pos)[2], int rad){
    position[X] = pos[X];
    position[Y] = pos[Y];
    velocity[X] = 300;
    velocity[Y] = 0;
    radius = rad;
}

Ball::Ball(double (&pos)[2], double (&vel)[2]){
    position[X] = pos[X];
    position[Y] = pos[Y];
    velocity[X] = vel[X];
    velocity[Y] = vel[Y];
}

Ball::~Ball(){
    //dtor
}

vector<double> Ball::getPos(){
    return {position[X], position[Y]};
}

vector<double> Ball::getVel(){
    return {velocity[X], velocity[Y]};
}

int Ball::update(vector<Field> fields){
    double pos[] = {position[X], position[Y]};
    double accel[2];
    vector<double> temp;
    for(vector<Field>::iterator it = fields.begin(); it != fields.end(); ++it){
        temp = it->getAccel(pos);
        accel[X]+=temp[X];
        accel[Y]+=temp[Y];
    }

    velocity[X]+=accel[X];
    velocity[Y]+=accel[Y];

    position[X]+=(dt*velocity[X]);
    position[Y]+=(dt*velocity[Y]);

    if(position[X]-radius<=0){
       position[X] = radius;
       velocity[X] = -velocity[X];
    }
    else if (position[X]+radius>=SCREEN_WIDTH){
        position[X] = SCREEN_WIDTH-radius;
        velocity[X] = -velocity[X];
    }

    if(position[Y]-radius<=0){
       position[Y] = radius;
       velocity[Y] = -velocity[Y];
    }
    else if (position[Y]+radius>=SCREEN_HEIGHT){
        position[Y] = SCREEN_HEIGHT-radius;
        velocity[Y] = -.8*velocity[Y];
        velocity[X] -= .5*velocity[X]*dt;
    }

    if(velocity[X]!=0){
        velocity[X] -= .1* velocity[X]*dt;
    }
    if(velocity[Y]!=0){
        velocity[Y] -= .05* velocity[Y]*dt;
    }

    return 0;
}

void Ball::render(SDL_Renderer* ren, vector<Field> fields){
    update(fields);
    //SDL_SetRenderDrawColor(ren, 0x10, 0x10, 0x10, 0xFF);
    fillcircle(ren, round(position[X]),round(position[Y]), radius);
}

void Ball::fillcircle(SDL_Renderer* ren, int x0, int y0, int rad){
    int x = rad-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (rad << 1);

    while (x >= y)
    {
        SDL_RenderDrawLine(ren, x0 - x, y0 + y, x0 + x, y0 + y);
        SDL_RenderDrawLine(ren, x0 + y, y0 + x, x0 - y, y0 + x);
        SDL_RenderDrawLine(ren, x0 + x, y0 - y, x0 - x, y0 - y);
        SDL_RenderDrawLine(ren, x0 + y, y0 - x, x0 - y, y0 - x);

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
            err += dx - (rad << 1);
        }
    }
    SDL_RenderPresent(ren);
}
