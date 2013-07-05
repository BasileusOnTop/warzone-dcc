cmake_minimum_required(VERSION 2.8)

set (SRC
	main.cpp
	RenderWorld.cpp
)

set (HEADERS
	RenderWorld.h
)

add_executable(warzone ${SRC} ${HEADERS})
target_link_libraries(warzone crown)

install (TARGETS warzone DESTINATION warzone)
install (FILES seed.ini DESTINATION warzone)
