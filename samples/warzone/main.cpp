#include "Crown.h"
#include "RenderWorld.h"
#include "Environment.h"
#include "Agent.h"

using namespace crown;

Environment m;
RenderWorld rw(&m);

//-----------------------------------------------------------------------------
void init()
{
	rw.init();
}

//-----------------------------------------------------------------------------
void frame(float dt)
{
	Keyboard* keyb = device()->keyboard();

	// Exit game
	if (keyb->key_released(KC_ESCAPE))
	{
		device()->stop();
	}

	if (keyb->key_released(KC_F5))
	{
		m.spawn_units();
	}

	if (keyb->key_released(KC_F6))
	{
		m.spawn_red_units();
	}

	if (keyb->key_released(KC_F7))
	{
		m.spawn_blue_units();
	}

	if (keyb->key_released(KC_F8))
	{
		m.spawn_red_medic();
	}

	if (keyb->key_released(KC_F9))
	{
		m.spawn_blue_medic();
	}

	// Debug mode on/off
	if (keyb->key_released(KC_d))
	{
		rw.enable_debug(!rw.debug());
	}

	static float scale = 1.0f;
	if (keyb->key_pressed(KC_F1))
	{
		scale += 0.3f;
	}
	if (keyb->key_pressed(KC_F2))
	{
		scale -= 0.3f;
	}

	if (scale < 1.0f)
	{
		scale = 1.0f;
	}

	m.update(dt * scale);
	m.update_physics(dt * scale);

	rw.frame();
}

//-----------------------------------------------------------------------------
void shutdown()
{
	rw.shutdown();
}

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	crown::os::init_os();

	crown::Device* engine = crown::device();

	if (!engine->init(argc, argv, init))
	{
		exit(-1);
	}

	uint32_t frames = 0;

	// Main loop
	while (engine->is_running())
	{
		engine->frame(frame);
		Log::i("Frame: %i", ++frames);
	}

	engine->shutdown(shutdown);

	return 0;
}

