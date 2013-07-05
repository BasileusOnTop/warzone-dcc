#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

Unit::Unit(uint32_t health, uint32_t damage, uint32_t speed, float positionX, float positionY, float radius, Factions team, Environment* env) 
	:Agent(health, damage, positionX, positionY, radius, team, env)
{
	m_speed = speed;
}

int Unit::move()
{
	m_positionY += 5.0*(1.0/60.0);
	return 0;
}

int Unit::update()
{
	Agent::update();
	move();
	return 0;
}