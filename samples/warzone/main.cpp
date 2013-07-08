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
	if (keyb->key_pressed(KC_ESCAPE))
	{
		device()->stop();
	}

	// Debug mode on/off
	if (keyb->key_pressed(KC_d))
	{
		rw.enable_debug(!rw.debug());
	}

	m.update();
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

	// Main loop
	while (engine->is_running())
	{
		engine->frame(frame);
	}

	engine->shutdown(shutdown);

	return 0;
}
