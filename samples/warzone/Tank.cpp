#include <stdio.h>
#include "Tank.h"
#include "Environment.h"

Tank::Tank(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Unit(pos, team, health, env)
{
	m_gun_dir			= Vec2(1, 0);
	m_health			= health;
	m_damage			= 30;
	m_radius			= 75.0f;
	m_speed 			= 8.0f;
	m_type 				= TANK;
	m_cooldown			= false;

}

int Tank::update(float dt)
{
	if (is_dead())
	{
		return -1;
	}

	if( m_cooldown == true)
	{
		m_dt_elapsed += dt;

		if( m_dt_elapsed >= 10.0f)
		{
			m_dt_elapsed = 0.0f;
			m_cooldown = false;
		}
	}
	if( m_cooldown == false)
	{
		uint32_t start_fetch = 0;

		if( m_team == BLUE && (!m_env->m_agents[2]->is_dead() || !m_env->m_agents[3]->is_dead()))
		{
			start_fetch = 2;
		}

		if( m_team == RED && (!m_env->m_agents[4]->is_dead() || !m_env->m_agents[5]->is_dead()))
		{
			start_fetch = 2;
		}

		for(uint32_t i=start_fetch; i<m_env->agent_count(); i++)
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
					m_gun_dir = (ith->m_pos - m_pos).normalize();
					Log::i("Type: %i | Team: %i | Id: %p | Hit: %p", m_type, m_team, (void *) this, (void *) ith);
					ith->damage(m_damage);
					m_cooldown = true;
					break;
				}
			}
		}
	}
	
	if (m_cooldown == false)
	{
		move(dt);
	}
}

Vec2 Tank::gun_dir()
{
	return m_gun_dir;
}
