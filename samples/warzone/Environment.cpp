#include "Environment.h"
#include "Agent.h"
#include "Unit.h"
#include "Turret.h"
#include "Tank.h"
#include "Random.h"
#include "OS.h"
#include "Hq.h"
#include "Circle.h"
#include "Intersection.h"

using namespace crown;

//-----------------------------------------------------------------------------
Environment::Environment() :
	m_agent_count(0)
{
	// Red team
	m_spawn_points[0] = Vec2(-250.0f,  125.0f);
	m_spawn_points[1] = Vec2(-200.0f,    0.0f);
	m_spawn_points[2] = Vec2(-250.0f, -125.0f);

	// Blue team
	m_spawn_points[3] = Vec2(250.0f,  125.0f);
	m_spawn_points[4] = Vec2(200.0f,    0.0f);
	m_spawn_points[5] = Vec2(250.0f, -125.0f);

	// Heahquarters
	add_agent(new Hq(Vec2(-400.0f, 0.0f), RED,  3000, this));
	add_agent(new Hq(Vec2( 400.0f, 0.0f), BLUE, 3000, this));

	// Spawn turrets
	add_agent(new Turret(Vec2(-325.0f,  150.0f), RED, 1000, this));
	add_agent(new Turret(Vec2(-325.0f, -150.0f), RED, 1000, this));

	add_agent(new Turret(Vec2(325.0f,  150.0f), BLUE, 1000, this));
	add_agent(new Turret(Vec2(325.0f, -150.0f), BLUE, 1000, this));
}

//-----------------------------------------------------------------------------
uint32_t Environment::agent_count()
{
	return m_agent_count;
}

//-----------------------------------------------------------------------------
int Environment::update(float dt)
{
	for(uint32_t i=0; i<m_agent_count; i++)
	{
		m_agents[i]->update(dt);
	}

	return 0;
}

void Environment::update_physics(float dt)
{
	for (uint32_t i = 6; i < m_agent_count; i++)
	{
		for (uint32_t j = 6; j < m_agent_count; j++)
		{
			Agent* agent_i = m_agents[i];
			Agent* agent_j = m_agents[j];

			if (i == j)
			{
				continue;
			}

			Circle circle_i;
			Circle circle_j;

			switch (agent_i->get_type())
			{
				case UNIT:
				case TANK:
				{
					circle_i.set_center(agent_i->m_pos);
					circle_i.set_radius(16.0f);
					break;
				}
				default:
					continue;
			}

			switch (agent_j->get_type())
			{
				case UNIT:
				case TANK:
				{
					circle_j.set_center(agent_j->m_pos);
					circle_j.set_radius(16.0f);
					break;
				}
				default:
					continue;
			}
			Vec2 penetration;
			if (Intersection::test_circle_circle(circle_i, circle_j, penetration))
			{
				agent_i->m_pos += penetration;
			}
		}
	}
}

//-----------------------------------------------------------------------------
int Environment::add_agent(Agent* a)
{
	if( m_agent_count == AGENTS)
		return -1;

	m_agents[m_agent_count] = a;
	m_agent_count++;

	return 0; //TODO
}

//-----------------------------------------------------------------------------
void Environment::spawn_red_units()
{
	//crown::Random random(crown::os::microseconds());

	// 0 or 1
	//uint32_t blue_seed = (random.integer() % 2) + 4;
	Unit* red_a = new Unit(m_spawn_points[0], RED, 200, this);
	      //red_a->set_dir((m_agents[blue_seed]->m_pos - red_a->m_pos).normalize());

	//blue_seed = (random.integer() % 2) + 4;
	Unit* red_b = new Tank(m_spawn_points[1], RED, 200, this);
	      //red_b->set_dir((m_agents[blue_seed]->m_pos - red_b->m_pos).normalize());

	//blue_seed = (random.integer() % 2) + 4;
	Unit* red_c = new Unit(m_spawn_points[2], RED, 200, this);
	      //red_c->set_dir((m_agents[blue_seed]->m_pos - red_c->m_pos).normalize());

	add_agent(red_a);
	add_agent(red_b);
	add_agent(red_c);
}

//-----------------------------------------------------------------------------
void Environment::spawn_blue_units()
{
	//crown::Random random(crown::os::microseconds());

	//uint32_t red_seed = (random.integer() % 2) + 2;
	Unit* blue_a = new Unit(m_spawn_points[3], BLUE, 200, this);
	      //blue_a->set_dir((m_agents[red_seed]->m_pos - blue_a->m_pos).normalize());

	//red_seed = (random.integer() % 2) + 2;
	Unit* blue_b = new Tank(m_spawn_points[4], BLUE, 200, this);
	      //blue_b->set_dir((m_agents[red_seed]->m_pos - blue_b->m_pos).normalize());

	//red_seed = (random.integer() % 2) + 2;
	Unit* blue_c = new Unit(m_spawn_points[5], BLUE, 200, this);
	      //blue_c->set_dir((m_agents[red_seed]->m_pos - blue_c->m_pos).normalize());

	add_agent(blue_a);
	add_agent(blue_b);
	add_agent(blue_c);
}

//-----------------------------------------------------------------------------
void Environment::spawn_units()
{
	crown::Random random(crown::os::microseconds());

	// 0 or 1
	//uint32_t blue_seed = (random.integer() % 2) + 4;
	Unit* red_a = new Unit(m_spawn_points[0], RED, 200, this);
	      //red_a->set_dir((m_agents[blue_seed]->m_pos - red_a->m_pos).normalize());

	//blue_seed = (random.integer() % 2) + 4;
	Unit* red_b = new Tank(m_spawn_points[1], RED, 200, this);
	      //red_b->set_dir((m_agents[blue_seed]->m_pos - red_b->m_pos).normalize());

	//blue_seed = (random.integer() % 2) + 4;
	Unit* red_c = new Unit(m_spawn_points[2], RED, 200, this);
	      //red_c->set_dir((m_agents[blue_seed]->m_pos - red_c->m_pos).normalize());

	//uint32_t red_seed = (random.integer() % 2) + 2;
	Unit* blue_a = new Unit(m_spawn_points[3], BLUE, 200, this);
	      //blue_a->set_dir((m_agents[red_seed]->m_pos - blue_a->m_pos).normalize());

	//red_seed = (random.integer() % 2) + 2;
	Unit* blue_b = new Tank(m_spawn_points[4], BLUE, 200, this);
	      //blue_b->set_dir((m_agents[red_seed]->m_pos - blue_b->m_pos).normalize());

	//red_seed = (random.integer() % 2) + 2;
	Unit* blue_c = new Unit(m_spawn_points[5], BLUE, 200, this);
	      //blue_c->set_dir((m_agents[red_seed]->m_pos - blue_c->m_pos).normalize());

	add_agent(red_a);
	add_agent(red_b);
	add_agent(red_c);
	add_agent(blue_a);
	add_agent(blue_b);
	add_agent(blue_c);
}