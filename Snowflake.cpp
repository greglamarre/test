#include <iostream>

#include "Constants.h"
#include "Player.h"
#include "Snowflake.h"
#include <algorithm>
using namespace std;


Snowflake::Snowflake() 
{

}
Snowflake::Snowflake(double x, double y)
    : GameObject{x, y}
{
    w = 3;
    h = 6;

    color_r = 0.8;
    color_g = 0.8;
    color_b = 1;
    color_a = 0.3;

    vy = 100 + rand()/(double)RAND_MAX * 100;

    inUse = false;
}

void Snowflake::update(double dt)
{
    GameObject::update(dt);

    if(y > SCREEN_HEIGHT + h) {
        deleteMe = true;
    }
}

void Snowflake::collide(Player& p)
{
    deleteMe = true;
}

void Snowflake::init(double a, double b)
{
    inUse = true;
    this->x = a;
    this->y = b;
}

void Snowflake::init()
{
    inUse = true;
    this->x = rand() / (double)RAND_MAX * SCREEN_WIDTH;
    this->y= -10;
}

double Snowflake::returnX()
{
    return x;
}