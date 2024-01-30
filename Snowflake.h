#pragma once

#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Snowflake : public GameObject
{
public:
    Snowflake(double x, double y);
    Snowflake(); // constructeur par défaut ajouté sinon C++ aime pas ça :(
    void update(double dt) override;
    virtual void collide(Player& o) override;
    void init();
    void init(double a, double b);
    bool inUse=false;
    double returnX();
  //  Snowflake
};
