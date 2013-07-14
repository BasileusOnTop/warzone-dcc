#include <stdio.h>
#include "Medic.h"
#include "Environment.h"
#include "Random.h"
#include "OS.h"

using namespace crown;

Medic::Medic(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Agent(pos, team, health, env)
{
	m_dir			= Vec2(0, 0);
	m_force_dir		= Vec2(0, 0);
	m_force_dir_f	= false;
	m_health 		= health;
	m_speed 		= 9.0f;
	m_damage		= 0;
	m_heal 			= 30;
	m_radius		= 150.0f;
	m_type 			= MEDIC;

	m_last_pos		= m_pos;
}

void Medic::set_dir(const Vec2& dir)
{
	m_dir = dir;
}

void Medic::set_pos(const float dt)
{
	m_pos += (m_dir * m_speed) * (dt);

	if( m_pos != m_last_pos)
	{
		m_last_pos = m_pos;
		Log::i("Type: %i | Team: %i | Id: %p | cur_pos: x:%f y:%f | cur_dir: x:%f y:%f", m_type, m_team, (void *) this, m_pos.x, m_pos.y, m_dir.x, m_dir.y);
	}
}

int Medic::move(float dt)
{
	crown::Random random(crown::os::microseconds());

	// SPOSTAMENTO VERSO GLI AMICI
	for(uint32_t i=6; i<m_env->agent_count(); i++)
	{
		if( !m_env->m_agents[i]->is_dead() && m_env->m_agents[i]->get_faction() == m_team)
		{
			this->set_dir( (m_env->m_agents[i]->m_pos - m_pos).normalize());
			set_pos(dt);
			return 0;
		}
	}


	if(m_team == BLUE)
	{
		this->set_dir( (m_env->m_agents[1]->m_pos - m_pos).normalize());

		m_force_dir = m_dir;
		m_force_dir_f = true;
	}

	if(m_team == RED)
	{
		this->set_dir( (m_env->m_agents[0]->m_pos - m_pos).normalize());

		m_force_dir = m_dir;
		m_force_dir_f = true;
	}
}

int Medic::update(float dt)
{

	if (is_dead())
	{
		return -1;
	}

	if( m_cooldown == true)
	{
		m_dt_elapsed += dt;

		if( m_dt_elapsed >= 7.0f)
		{
			m_dt_elapsed = 0.0f;
			m_cooldown = false;
		}
	}
	if( m_cooldown == false)
	{

		for(uint32_t i=6; i<m_env->agent_count(); i++)
		{
			Agent* ith = m_env->m_agents[i];
			Agent* most_wounded = ith;
			// If it's me
			if (ith == this)
			{
				continue;
			}

			// Euclidian norm
			if( (m_pos.x - ith->m_pos.x) * (m_pos.x - ith->m_pos.x) +
				(m_pos.y - ith->m_pos.y) * (m_pos.y - ith->m_pos.y) <= m_radius * m_radius)
			{
				if((!ith->is_dead()) && (ith->get_faction() == m_team))
				{
					ith->heal(m_heal);
					Log::i("Type: %i | Team: %i | Id: %p | Heal: %p", m_type, m_team, (void *) this, (void *) ith);	
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