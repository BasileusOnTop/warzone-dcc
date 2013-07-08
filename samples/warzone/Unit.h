#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Vec2.h"

class Environment;

class Unit : public Agent
{
private:

	Vec2		m_dir;
	float 		m_speed;

public: 
	Unit(uint32_t health, uint32_t damage, float speed, const Vec2& pos, float radius, Faction team, Environment* env);

private:

	int 			move();
	int 			update();
	
};

