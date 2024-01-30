#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include <SDL.h>

#include "Constants.h"
#include "GameSnow.h"
#include "Player.h"
#include "Snowflake.h"
#include "SnowflakeRebound.h"
#include "SnowflakeNoContact.h"
#include "SnowflakeSine.h"
#include "SnowflakePool.h"

using namespace std;

GameSnow::GameSnow() :
    m_pause(false),
    p(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
    snowflakePool()


{
    
   // snowflakePool.showPool();
    init(presets[0]);
}

void GameSnow::init(int n)
{
    cout << "Init with " << n << " particles" << endl;

    //snowflakes.clear();
  //  snowflakePool.SetNumberOfActiveSnowFlakes(n)
    for(int i=0; i<n; i++) {
        double x = rand()/(double)RAND_MAX * SCREEN_WIDTH;
        double y = rand()/(double)RAND_MAX * (SCREEN_HEIGHT + 10) - 10;
        snowflakePool.spawn(x, y);

        
       // addSnowflake(x, y);
    }
}

void GameSnow::addSnowflake()
{
    // Default : top of the screen
    addSnowflake(rand()/(double)RAND_MAX * SCREEN_WIDTH, -10);
}

void GameSnow::addSnowflake(double x, double y)
{
    //Trouver la premi�re particule inactive de mon pool

   // if (snowflakePool.GetNumberOfActiveSnowflakes() < )

    //La rendre active

    //snowflakePool.spawn( x,  y);
    /*unique_ptr<Snowflake> snowflake;

    int rnd = rand();
    if(rnd < RAND_MAX / 10)
        snowflake = make_unique<SnowflakeRebound>(x, y);
    else if(rnd < RAND_MAX / 5 * 2)
        snowflake = make_unique<SnowflakeNoContact>(x, y);
    else if(rnd < RAND_MAX / 2)
        snowflake = make_unique<SnowflakeSine>(x, y);
    else
        snowflake = make_unique<Snowflake>(x, y);

    snowflakes.push_back(move(snowflake));*/
}

void GameSnow::handleInput(const SDL_Event& event)
{
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                p.x = x;
                p.y = y;
            }
            break;
    case SDL_KEYUP:
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            p.inputs.left = false;
            break;
        case SDLK_RIGHT:
            p.inputs.right = false;
            break;
        case SDLK_DOWN:
            p.inputs.down = false;
            break;
        case SDLK_UP:
        case SDLK_SPACE:
            p.inputs.jump = false;
            break;
        }
        break;

    case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            p.inputs.left = true;
            break;
        case SDLK_RIGHT:
            p.inputs.right = true;
            break;
        case SDLK_DOWN:
            p.inputs.down = true;
            break;
        case SDLK_UP:
        case SDLK_SPACE:
            p.inputs.jump = true;
            break;

            // Pause
        case SDLK_p:
            m_pause = !m_pause;
            break;

        case SDLK_1:
        case SDLK_2:
        case SDLK_3:
        case SDLK_4:
        case SDLK_5:
        case SDLK_6:
        case SDLK_7:
        case SDLK_8:
        case SDLK_9:
            init(presets[event.key.keysym.sym - SDLK_1]);
            break;

        case SDLK_ESCAPE:
            keepPlaying = false;
            break;
        }
    }
}

void GameSnow::update(unsigned long dt)
{
    if(m_pause) return;

    double delta_t = dt / 1000.0;

    // Physics
    p.update(delta_t);

    
    snowflakePool.update(delta_t);

    snowflakePool.testCollision(p);
   /* for (int i = 0; i < snowflakePool.GetNumberOfActiveSnowflakes(); i++)
    {
        snowflakePool[i]->update(delta_t);
    }*/

   // for(auto *obj : snowflakePool)
   //{
   //     obj->update(delta_t);
   // }

    // Collisions
   /* for(auto& obj : snowflakes)
    {
        obj->testCollision(p);
    }*/

    // Remove unused objects
    long size_before = snowflakes.size();

    snowflakes.erase(remove_if(snowflakes.begin(),
                               snowflakes.end(),
                               [](auto& ptr) {
                                   return ptr->shouldDelete();
                               }),
                     snowflakes.end());

    long nb_new_snowflakes = size_before - snowflakes.size();

    for(int i=0; i<nb_new_snowflakes; i++)
    {
        snowflakePool.spawn();
       // addSnowflake();
    }
}

void GameSnow::render(SDL_Renderer* renderer) const
{
    // -- Clear screen --
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    // Draw particles
    p.render(renderer);


    snowflakePool.render(renderer);
    /*for(const auto& obj : snowflakes)
    {
        obj->render(renderer);
    }*/

    SDL_RenderPresent(renderer);
}
