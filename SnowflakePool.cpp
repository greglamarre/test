#include "SnowflakePool.h"

#include "Constants.h"
#include "Player.h"
#include "SnowflakePool.h"
#include <iostream>


SnowflakePool::~SnowflakePool()
{

}
SnowflakePool::SnowflakePool() : nbSnowflakeActifs{ 0 }, pool(std::make_unique<Snowflake[]>(MAX_SNOWFLAKES))
{
	//pool =;
	  //for (int i = 0; i < MAX_SNOWFLAKES; i++)
	  //{
	  //	pool[i] = std::make_unique<Snowflake>();
	  //}
}

void SnowflakePool::showPool()
{
	std::cout << "La pool a ete cree avec succes" << std::endl;
}

void SnowflakePool::spawn(double x, double y)
{
	if (nbSnowflakeActifs < MAX_SNOWFLAKES)
	{
		pool[nbSnowflakeActifs].init(x, y);

		nbSnowflakeActifs++;
	}
}

void SnowflakePool::spawn()
{
	if (nbSnowflakeActifs < MAX_SNOWFLAKES)
	{
		pool[nbSnowflakeActifs].init();

		nbSnowflakeActifs++;
	}
}
void SnowflakePool::update(double dt)
{
	for (int i = 0; i < nbSnowflakeActifs; i++)
	{

		pool[i].update(dt);
	}
}

void SnowflakePool::testCollision(Player& p) 
{
	for (int i = 0; i < nbSnowflakeActifs; i++)
	{

		pool[i].testCollision(p);
	}
}

//Snowflake* SnowflakePool::getSnowflake(int i)
//{
//	
//		if (i >= 0 && i < MAX_SNOWFLAKES)
//		{
//			return pool[i].get();
//		}
//		return nullptr;
//	
//}

void SnowflakePool::destroy(size_t deleteIdx)
{

}




void SnowflakePool::SetAllSnowFlakesInactive()
{
	for (int i = 0; i < MAX_SNOWFLAKES; i++)
	{
		pool[i].inUse = false;
	}
}

void SnowflakePool::SetAllSnowFlakesActive() 
{
	for (int i = 0; i < MAX_SNOWFLAKES; i++)
	{
		pool[i].inUse = true;
	}
}

int SnowflakePool::GetNumberOfActiveSnowflakes()
{
	return nbSnowflakeActifs;
}

void SnowflakePool::IncreaseNumberOfActiveSnowFlakes()
{
	nbSnowflakeActifs++;
}

void SnowflakePool::render(SDL_Renderer* renderer) const

{

	std::cout << "Je render la" << std::endl;
	for (int i = 0; i < nbSnowflakeActifs; i++)
	{

		pool[i].render(renderer);
	}
}