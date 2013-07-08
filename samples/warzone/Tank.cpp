#include <stdio.h>
#include "Tank.h"
#include "Environment.h"

Tank::Tank(const Vec2& pos, Faction team, Environment* env) 
	:Unit(pos, team, env)
{

	m_health			= 1000;
	m_damage			= 30;
	m_radius			= 75.0f;
	m_speed 			= 8.0f;
	m_type 				= TANK;
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
	m_cooldown_actual++;

	if(!on_cooldown())
	{
		Agent::update();
		move();
	}
	

	return 0;
}

bool Tank::on_cooldown()
{
	if( m_cooldown_actual == m_cooldown)
	{
		m_cooldown_actual = 0;
		return false;
	}

	return true;
}