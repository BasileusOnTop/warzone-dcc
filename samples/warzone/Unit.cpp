#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

Unit::Unit(uint32_t health, uint32_t damage, float speed, const Vec2& pos, float radius, Faction team, Environment* env) 
	:Agent(health, damage, pos, radius, team, env)
{
	m_dir		= Vec2(0, 0);
	m_speed 	= speed;
	m_type 		= UNIT; //THIS IS OK
}

int Unit::move()
{
	m_dir = (Vec2(-350.0f, 150.0f) - m_pos).normalize();
	m_pos += (m_dir * m_speed) * (1.0f/60.0f);
}

int Unit::update()
{
	Agent::update();
	move();

	return 0;
}