#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Vec2.h"

using namespace crown;

class Environment;

class Turret : public Agent
{


private:

	Vec2						m_gun_dir;


public:
	Turret(const Vec2& pos, Faction team, Environment* env);

	const Vec2&					gun_dir();
};

