#include "Environment.h"
#include "Agent.h"


Environment::Environment()
{
	for(uint32_t i=0; i<AGENTS; i++)
	{
		m_agents[i] = new Agent(10, 8, i, 0, 5, (Factions)(i%2), this);
	}
}

int Environment::update()
{
	return 0;
}