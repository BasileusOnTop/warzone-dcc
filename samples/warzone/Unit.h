#pragma once

#include <stdint.h>
#include "Agent.h"

class Environment;

class Unit : public Agent
{
	float 		m_speed;

public: // Constructor


	Unit(uint32_t health, uint32_t damage, float speed, float coord_x, float coord_y, float radius, Factions team, Environment* env);

private:
	
	int 			move();
	int 			update();
};

