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

	const float bound_x[2] = {-400.0f, 400.0f};
	const float bound_y[2] = {-200.0f, 200.0f};

	add_agent(new Turret(10, 8, Vec2(-350.0f,   150.0f), 150.0f, RED, this));
	add_agent(new Turret(10, 8, Vec2(-350.0f, -150.0f), 150.0f, RED, this));

	add_agent(new Turret(10, 8, Vec2(350.0f,  150.0f), 150.0f, BLUE, this));
	add_agent(new Turret(10, 8, Vec2(350.0f, -150.0f), 150.0f, BLUE, this));

	for(uint32_t i=0; i<AGENTS; i++)
	{
		// Generate random x,y in a 400 * 400 pixels area
		// centered at the origin (middle of the window)
		float rand_x = (random.unit_float() - 0.5f) * 400.0f;
		float rand_y = (random.unit_float() - 0.5f) * 400.0f;

		add_agent(new Unit(1000, 8, 10.0f, Vec2(rand_x, rand_y), 50.0f, (Faction)(i%2), this));
	}

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
