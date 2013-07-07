#include "Environment.h"
#include "Agent.h"
#include "Unit.h"
#include "Turret.h"
#include "Random.h"
#include "OS.h"

Environment::Environment()
{
	m_items = 0;

	crown::Random random(crown::os::microseconds());

	for(uint32_t i=0; i<AGENTS; i++)
	{
		// Generate random x,y in a 400 * 400 pixels area
		// centered at the origin (middle of the window)
		float rand_x = (random.unit_float() - 0.5f) * 400.0f;
		float rand_y = (random.unit_float() - 0.5f) * 400.0f;

		add_agent(new Unit(10, 8, (float)i*2, rand_x, rand_y, 100.0f, (Factions)(i%2), this));
		//add_agent(new Turret(10, 8, rand_x, rand_y, 45.0f, (Factions)(i%2), this));
	}

	
}

int Environment::update()
{
	for(uint32_t i=0; i<AGENTS; i++)
		m_agents[i]->update();

	return 0;
}

int Environment::add_agent(Agent* a)
{
	if( m_items == AGENTS)
		return -1;

	m_agents[m_items] = a;
	m_items++;

	return 0; //TODO
}

int Environment::add_agent(Unit* a)
{
	if( m_items == AGENTS)
		return -1;

	m_agents[m_items] = a;
	m_items++;

	return 0; //TODO
}

int Environment::add_agent(Turret* a)
{
	if( m_items == AGENTS)
		return -1;

	m_agents[m_items] = a;
	m_items++;

	return 0; //TODO
}