#include "Crown.h"
#include "RenderWorld.h"

using namespace crown;

RenderWorld rw;

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
