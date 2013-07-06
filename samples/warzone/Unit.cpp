#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

Unit::Unit(uint32_t health, uint32_t damage, float speed, float coord_x, float coord_y, float radius, Factions team, Environment* env) 
	:Agent(health, damage, coord_x, coord_y, radius, team, env)
{
	m_speed 	= speed;
	m_type 		= UNIT; //THIS IS OK
}

int Unit::move()
{
	m_coord_y += (float)m_speed*(1.0/60.0);

	return 0;
}

int Unit::update()
{
	Agent::update();
	move();

	return 0;
}