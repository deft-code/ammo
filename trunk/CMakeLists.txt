#!/usr/bin/cmake

cmake_minimum_required(VERSION 2.6)

Project( AMMO )

include_directories(
	src/
	../box2d/Include
	extlibs/CEGUI/include
	extlibs/RakNet/include
	extlibs/SFML/include )

link_directories(
	/home/nick/projects/box2d/Source/Gen/float
	/home/nick/projects/raknet/install/lib
	${PROJECT_SOURCE_DIR}/extlibs/SFML/lib/linux
	${PROJECT_SOURCE_DIR}/extlibs/CEGUI/lib/linux
	)

set( CMAKE_CXX_FLAGS "-Wall" )

file( GLOB ammo_files src/ammo/*.cpp )
file( GLOB ammo_files_subs src/ammo/*/*.cpp src/ammo/*/*/*.cpp )

set( AMMO_LIBS box2d RakNet
	CEGUI
	GLU dl pcre freetype
	sfml-graphics
	sfml-audio
	sfml-window
	sfml-system
	)

add_library( engine STATIC src/ammo/error.cpp ${ammo_files_subs} )

add_executable( ammo src/ammo/main.cpp )
target_link_libraries( ammo engine ${AMMO_LIBS} )

add_executable( pong examples/pong/pong.cpp )
target_link_libraries( pong engine ${AMMO_LIBS} )

add_executable( ski examples/ski/ski_physics.cpp )
target_link_libraries( ski engine ${AMMO_LIBS} )

