#include <stdio.h>
#include "Hq.h"
#include "Environment.h"

//-----------------------------------------------------------------------------
Hq::Hq(const Vec2& pos, Faction team, Environment* env) 
	:Agent(pos, team, env)
{
	m_health 	= 5000;
	m_type 		= HQ;
}

//-----------------------------------------------------------------------------
int Hq::update(float dt)
{

}
