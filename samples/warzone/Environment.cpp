#include "Environment.h"
#include "Agent.h"
#include "Unit.h"


Environment::Environment()
{
	for(uint32_t i=0; i<AGENTS; i++)
	{
		m_agents[i] = new Unit(10, 8, 0, i, 0, 5, (Factions)(i%2), this);
	}
}

int Environment::update()
{
	for(uint32_t i=0; i<AGENTS; i++)
		m_agents[i]->update();
	return 0;
}