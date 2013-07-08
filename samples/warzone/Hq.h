#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Vec2.h"

using namespace crown;

class Environment;

class Hq : public Agent
{

public:
					Hq(const Vec2& pos, Faction team, Environment* env);
	virtual int		update(float dt);
};