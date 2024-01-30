#pragma once
#include <vector>
#include <memory>

#include "Player.h"
#include "Snowflake.h"
#include "Game.h"
#include "SnowflakePool.h"

class GameSnow : public Game
{
public:
    GameSnow();

    void handleInput(const SDL_Event& event) override;
    void update(unsigned long dt) override;
    void render(SDL_Renderer* renderer) const override;

    void init(int snowflakes);
    void addSnowflake();
    void addSnowflake(double x, double y);
    SnowflakePool snowflakePool;
private:
    bool m_pause;
    unsigned long presets[9] = { 1000, 2500, 5000, 6000, 7000, 8000, 9000, 10000, 12000 };

    Player p;
    std::vector<std::unique_ptr<Snowflake>> snowflakes;
   
};
