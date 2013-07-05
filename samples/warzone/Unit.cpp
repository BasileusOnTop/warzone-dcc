#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

	Unit::Unit()
	{
	}

	Unit::Unit(uint32_t health, uint32_t damage, uint32_t speed, float positionX, float positionY, float radius, Factions team, Environment* env) 
		:Agent(health, damage, positionX, positionY, radius, team, env)
	{
		m_speed = speed;
	}