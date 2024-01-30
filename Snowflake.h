#pragma once

#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Snowflake : public GameObject
{
public:
    Snowflake(double x, double y);
    Snowflake(); // constructeur par d�faut ajout� sinon C++ aime pas �a :(
    void update(double dt) override;
    virtual void collide(Player& o) override;
    void init();
    void init(double a, double b);
    bool inUse=false;
    double returnX();
  //  Snowflake
};
