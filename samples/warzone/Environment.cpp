#include "Environment.h"
#include "Agent.h"
#include "Unit.h"
#include "Turret.h"
#include "Random.h"
#include "OS.h"

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

	const float bound_x[2] = {-400.0f, 400.0f};
	const float bound_y[2] = {-200.0f, 200.0f};

	add_agent(new Turret(10, 8, Vec2(-350.0f,   150.0f), 150.0f, RED, this));
	add_agent(new Turret(10, 8, Vec2(-350.0f, -150.0f), 150.0f, RED, this));

	add_agent(new Turret(10, 8, Vec2(350.0f,  150.0f), 150.0f, BLUE, this));
	add_agent(new Turret(10, 8, Vec2(350.0f, -150.0f), 150.0f, BLUE, this));

	// Spawn units
	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[0], 50.0f, RED, this));
	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[1], 50.0f, RED, this));
	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[2], 50.0f, RED, this));

	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[3], 50.0f, BLUE, this));
	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[4], 50.0f, BLUE, this));
	add_agent(new Unit(1000, 8, 10.0f, m_spawn_points[5], 50.0f, BLUE, this));


	// add_agent(new Unit(1000, 8, 0.0f, 10, 10, 50.0f, RED, this));
	// add_agent(new Unit(1000, 8, 0.0f, 20, 10, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));
	// add_agent(new Unit(10, 8, 0.0f, 100, 100, 50.0f, BLUE, this));

}

//-----------------------------------------------------------------------------
uint32_t Environment::agent_count()
{
	return m_agent_count;
}

//-----------------------------------------------------------------------------
int Environment::update()
{
	for(uint32_t i=0; i<m_agent_count; i++)
	{
		m_agents[i]->update();
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
