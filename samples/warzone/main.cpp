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
	if (device()->keyboard()->key_pressed(KC_ESCAPE))
	{
		device()->stop();
	}

	rw.frame();
	m.update();
	Log::i("FPS: %f", 1.0f/device()->last_delta_time());
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
