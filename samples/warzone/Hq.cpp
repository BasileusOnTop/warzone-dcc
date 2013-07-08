#include <stdio.h>
#include "Hq.h"
#include "Environment.h"

//-----------------------------------------------------------------------------
Hq::Hq(const Vec2& pos, Faction team, int32_t health, Environment* env) 
	:Agent(pos, team, health, env)
{
	m_health 	= health;
	m_type 		= HQ;
}

//-----------------------------------------------------------------------------
int Hq::update(float dt)
{

}
