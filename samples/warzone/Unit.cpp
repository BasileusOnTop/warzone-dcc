#include <stdio.h>
#include "Unit.h"
#include "Environment.h"
#include "Random.h"
#include "OS.h"

using namespace crown;

Unit::Unit(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Agent(pos, team, health, env)
{
	m_dir			= Vec2(0, 0);
	m_force_dir		= Vec2(0, 0);
	m_force_dir_f	= false;
	m_health 		= health;
	m_speed 		= 5.0f;
	m_damage		= 10;
	m_radius		= 50.0f;
	m_type 			= UNIT;
}

void Unit::set_dir(const Vec2& dir)
{
	m_dir = dir;
}

int Unit::move(float dt)
{
	crown::Random random(crown::os::microseconds());

	// SPOSTAMENTO VERSO I NEMICI
	for(uint32_t i=6; i<m_env->agent_count(); i++)
	{
		if( !m_env->m_agents[i]->is_dead() && m_env->m_agents[i]->get_faction() != m_team)
		{
			this->set_dir( (m_env->m_agents[i]->m_pos - m_pos).normalize());
			m_pos += (m_dir * m_speed) * (dt);
			return 0;
		}
	}


	if(m_team == BLUE)
	{
		if(!m_env->m_agents[2]->is_dead() && !m_env->m_agents[3]->is_dead())
		{
			if(m_force_dir_f == true)
			{
				this->set_dir(m_force_dir);
				m_pos += (m_dir * m_speed) * (dt);
				return 0;
			}


			uint32_t blue_seed = (random.integer() % 2) + 2;
			this->set_dir((m_env->m_agents[blue_seed]->m_pos - m_pos).normalize());

			m_force_dir = m_dir;
			m_force_dir_f = true;
		}
		else
		{
			if(!m_env->m_agents[2]->is_dead())
			{
				this->set_dir( (m_env->m_agents[2]->m_pos - m_pos).normalize());
				m_pos += (m_dir * m_speed) * (dt);
				return 0;
			}
			
			if(!m_env->m_agents[3]->is_dead())
			{
				this->set_dir( (m_env->m_agents[3]->m_pos - m_pos).normalize());
				m_pos += (m_dir * m_speed) * (dt);
				return 0;
			}

		}

		if( m_env->m_agents[2]->is_dead() && m_env->m_agents[3]->is_dead())
		{
			this->set_dir( (m_env->m_agents[0]->m_pos - m_pos).normalize());
			m_pos += (m_dir * m_speed) * (dt);
			return 0;
		}

	}

	if(m_team == RED)
	{
		if(!m_env->m_agents[4]->is_dead() && !m_env->m_agents[5]->is_dead())
		{
			if(m_force_dir_f == true)
			{
				this->set_dir(m_force_dir);
				m_pos += (m_dir * m_speed) * (dt);
				return 0;
			}


			uint32_t blue_seed = (random.integer() % 2) + 4;
			this->set_dir( (m_env->m_agents[blue_seed]->m_pos - m_pos).normalize());

			m_force_dir = m_dir;
			m_force_dir_f = true;
		}
		else
		{
			if(!m_env->m_agents[4]->is_dead())
			{
				this->set_dir( (m_env->m_agents[4]->m_pos - m_pos).normalize());
				m_pos += (m_dir * m_speed) * (dt);
				return 0;

			}

			if(!m_env->m_agents[5]->is_dead())
			{
				this->set_dir( (m_env->m_agents[5]->m_pos - m_pos).normalize());
				m_pos += (m_dir * m_speed) * (dt);
				return 0;

			}
		}

		if( m_env->m_agents[4]->is_dead() && m_env->m_agents[5]->is_dead())
		{
			this->set_dir( (m_env->m_agents[1]->m_pos - m_pos).normalize());
			m_pos += (m_dir * m_speed) * (dt);
			return 0;
		}
	}


}

int Unit::update(float dt)
{

	if (is_dead())
	{
		return -1;
	}

	if( m_cooldown == true)
	{
		m_dt_elapsed += dt;

		if( m_dt_elapsed >= 3.0f)
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