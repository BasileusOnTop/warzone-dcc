#include <stdio.h>
#include "Tank.h"
#include "Environment.h"

Tank::Tank(uint32_t health, uint32_t damage, float speed, const Vec2& pos, float radius, Faction team, Environment* env) 
	:Agent(health, damage, pos, radius, team, env)
{
	m_dir				= Vec2(0, 0);
	m_speed 			= speed;
	m_type 				= TANK; //THIS IS OK
	m_cooldown 			= 10;
	m_cooldown_actual 	= 0;
}

int Tank::move()
{
	m_dir = (Vec2(-350.0f, 150.0f) - m_pos).normalize();
	m_pos += (m_dir * m_speed) * (1.0f/60.0f);
}

int Tank::update()
{
	if(!on_cooldown())
	{
		Agent::update();
		move();
	}
	

	return 0;
}

bool Tank::on_cooldown()
{
	m_cooldown_actual++;
	if( m_cooldown_actual == m_cooldown)
	{
		return false;
	}

	return true;
}