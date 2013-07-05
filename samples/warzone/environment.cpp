#include "environment.h"
#include "agent.h"


Environment::Environment()
{
	for(uint32_t i=0; i<AGENTS; i++)
	{
		m_agents[i] = new Agent(10, 10, 1, 0, 0, 3, *this);
	}
}

int Environment::update()
{
	return 0;
}