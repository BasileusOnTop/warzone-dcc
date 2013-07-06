#include "Environment.h"
#include "Agent.h"
#include "Unit.h"
#include "Random.h"
#include "OS.h"

Environment::Environment()
{
	crown::Random random(crown::os::microseconds());

	for(uint32_t i=0; i<AGENTS; i++)
	{
		// Generate random x,y in a 400 * 400 pixels area
		// centered at the origin (middle of the window)
		float rand_x = (random.unit_float() - 0.5f) * 400.0f;
		float rand_y = (random.unit_float() - 0.5f) * 400.0f;

		m_agents[i] = new Unit(10, 8, 2.0f, rand_x, rand_y, 45.0f, (Factions)(i%2), this);
	}

	m_items = 0;
}

int Environment::update()
{
	for(uint32_t i=0; i<AGENTS; i++)
		m_agents[i]->update();
	return 0;
}

int Environment::add_agent(Agent a)
{
	
}