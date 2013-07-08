#include "Agent.h"
#include "Log.h"
#include <stdio.h>

using namespace crown;

Agent::Agent(const Vec2& pos, Faction team, Environment* env) 
{
	m_type 		= NONE;

	m_health 	= 0;
	m_damage 	= 0;
	m_radius 	= 0.0f;

	m_pos		= pos;
	m_team 		= team;
	m_env 		= env;
}

int Agent::damage(uint32_t damage)
{
	m_health -= damage;
	return 0;
}

float Agent::area_of_effect()
{
	return m_radius;
}


int Agent::update(float dt)
{
	if (is_dead())
	{
		return -1;
	}

	search_and_destroy();

	return 0;
}

Type Agent::get_type()
{
	return m_type;
}

Faction Agent::get_faction()
{
	return m_team;
}

int Agent::search_and_destroy()
{
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
			if((!ith->is_dead()) && (ith->m_team != m_team))
			{
				ith->damage(m_damage);
			}
		}
	}
	return 0;
}

bool Agent::is_dead() const
{
	return m_health <= 0;
}
