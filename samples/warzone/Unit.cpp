#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

Unit::Unit(const Vec2& pos, Faction team, Environment* env) 
	:Agent(pos, team, env)
{
	m_dir		= Vec2(0, 0);

	m_speed 	= 5.0f;
	m_health 	= 100;
	m_damage	= 10;
	m_radius	= 50.0f;
	m_type 		= UNIT;
}

int Unit::move(float dt)
{
	m_dir = (Vec2(-350.0f, 150.0f) - m_pos).normalize();
	m_pos += (m_dir * m_speed) * (dt);
}

int Unit::update(float dt)
{
	Agent::update(dt);
	move(dt);

	return 0;
}