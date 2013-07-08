cmake_minimum_required(VERSION 2.8)

set (SRC
	main.cpp
	RenderWorld.cpp
	Agent.cpp
	Unit.cpp
	Turret.cpp
	Environment.cpp
	Tank.cpp
	Hq.cpp
)

set (HEADERS
	RenderWorld.h
	Agent.h
	Unit.h
	Turret.h
	Environment.h
	Tank.h
	Hq.h
)

add_definitions(-g -pg)
add_executable(warzone ${SRC} ${HEADERS})
target_link_libraries(warzone crown)

install (TARGETS warzone DESTINATION warzone)
install (FILES seed.ini DESTINATION warzone)
