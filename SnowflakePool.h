#pragma once

#include <SDL.h>
#include "Snowflake.h"



#include <cstddef>
#include <memory>

class SnowflakePool
{
public:
	~SnowflakePool();
	SnowflakePool();
	void render(SDL_Renderer* renderer) const;
	void spawn();
	void spawn(double x, double y);
	void destroy(size_t deleteIdx);
	void showPool(); //pour debug;
	void SetAllSnowFlakesInactive();
	void SetAllSnowFlakesActive();
	int GetNumberOfActiveSnowflakes();
	void IncreaseNumberOfActiveSnowFlakes();
	void SetNumberOfActiveSnowFlakes(int nbSnow);
	//void init(double x, double y);
	//Snowflake* getSnowflake(int i);
	void update(double dt);
	void testCollision(Player& p);
	std::unique_ptr<Snowflake[]> pool;
private:
	const int MAX_SNOWFLAKES = 50000;

	
	size_t nbSnowflakeActifs;

	

}; 


