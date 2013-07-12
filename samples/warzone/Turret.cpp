#include <stdio.h>
#include "Turret.h"
#include "Environment.h"

Turret::Turret(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Agent(pos, team, health, env)
{
	m_health	= health;
	m_damage	= 20;
	m_radius	= 200.0f;
	m_type 		= TURRET;
	m_gun_dir	= (Vec2(0, 0) - m_pos).normalize();
}

//-----------------------------------------------------------------------------
const Vec2& Turret::gun_dir()
{
	return m_gun_dir;
}

//-----------------------------------------------------------------------------
int Turret::update(float dt)
{	
	if (is_dead())
	{
		return -1;
	}

	if( m_cooldown == true)
	{
		m_dt_elapsed += dt;

		if( m_dt_elapsed >= 0.5f)
		{
			m_dt_elapsed = 0.0f;
			m_cooldown = false;
		}
	}
	if( m_cooldown == false)
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
				if((!ith->is_dead()) && (ith->get_faction() != m_team))
				{
					m_gun_dir = (ith->m_pos - m_pos).normalize();
					ith->damage(m_damage);
					Log::i("Type: %i | Team: %i | Id: %p | Hit: %p", m_type, m_team, (void *) this, (void *) ith);
					m_cooldown = true;
					break;
				}
			}
		}
	}
}
