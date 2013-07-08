#include "Environment.h"
#include "Agent.h"
#include "Unit.h"
#include "Turret.h"
#include "Tank.h"
#include "Random.h"
#include "OS.h"
#include "Hq.h"

using namespace crown;

//-----------------------------------------------------------------------------
Environment::Environment() :
	m_agent_count(0)
{
	crown::Random random(crown::os::microseconds());

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
	add_agent(new Turret(Vec2(-350.0f,  150.0f), RED, 1000, this));
	add_agent(new Turret(Vec2(-350.0f, -150.0f), RED, 1000, this));

	add_agent(new Turret(Vec2(350.0f,  150.0f), BLUE, 1000, this));
	add_agent(new Turret(Vec2(350.0f, -150.0f), BLUE, 1000, this));

	// Spawn units
	add_agent(new Unit(m_spawn_points[0], RED, 200, this));
	add_agent(new Tank(m_spawn_points[1], RED, 200, this));
	add_agent(new Unit(m_spawn_points[2], RED, 200, this));

	add_agent(new Unit(m_spawn_points[3], BLUE, 200, this));
	add_agent(new Tank(m_spawn_points[4], BLUE, 200, this));
	add_agent(new Unit(m_spawn_points[5], BLUE, 200, this));
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
void Environment::spawn_units()
{
	// add_agent(new Unit(m_spawn_points[0], RED, this));
	// add_agent(new Tank(m_spawn_points[1], RED, this));
	// add_agent(new Unit(m_spawn_points[2], RED, this));

	add_agent(new Unit(m_spawn_points[3], BLUE, 300, this));
	add_agent(new Tank(m_spawn_points[4], BLUE, 300, this));
	add_agent(new Unit(m_spawn_points[5], BLUE, 300, this));	
}