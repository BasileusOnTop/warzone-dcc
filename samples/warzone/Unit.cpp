#include <stdio.h>
#include "Unit.h"
#include "Environment.h"

Unit::Unit(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Agent(pos, team, health, env)
{
	m_dir		= Vec2(0, 0);

	m_health 	= health;
	m_speed 	= 5.0f;
	m_damage	= 10;
	m_radius	= 50.0f;
	m_type 		= UNIT;
}

int Unit::move(float dt)
{
	if (m_team == RED)
	{
		m_dir = Vec2(1, 0);
	}
	else
	{
		m_dir = Vec2(-1, 0);
	}

	m_pos += (m_dir * m_speed) * (dt);
}

int Unit::update(float dt)
{
	bool hit = false;

	for(uint32_t i=0; i<m_env->agent_count(); i++)
	{
		Agent* ith = m_env->m_agents[i];

		// If it's me
		if (ith == this)
		{
			continue;
		}

		// Euclidian norm
		if( (m_pos.x - ith->m_pos.x) * (m_pos.x - ith->m_pos.x) +
			(m_pos.y - ith->m_pos.y) * (m_pos.y - ith->m_pos.y) <= m_radius * m_radius)
		{
			if((!ith->is_dead()) && (ith->get_faction() != m_team))
			{
				ith->damage(m_damage);
				hit = true;
			}
		}
	}

	if (!hit)
	{
		move(dt);
	}
}