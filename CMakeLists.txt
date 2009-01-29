#!/usr/bin/cmake

cmake_minimum_required(VERSION 2.6)

Project( AMMO )

include_directories( src/
	../box2d/Include
	../cegui/include
	../cegui/RendererModules/OpenGLGUIRenderer
	../raknet/install/include/raknet
	extlibs/SFML/include )

link_directories(
	/home/nick/projects/box2d/Source/Gen/float
	/home/nick/projects/cegui/install/lib
	/home/nick/projects/raknet/install/lib
	/home/nick/projects/ammo/extlibs/SFML/lib/linux )

set( CMAKE_CXX_FLAGS "-Wall" )

file( GLOB ammo_files src/ammo/*.cpp )
file( GLOB ammo_files_subs src/ammo/*/*.cpp src/ammo/*/*/*.cpp )

add_executable( ammo ${ammo_files} ${ammo_files_subs} )
target_link_libraries( ammo
	box2d
	RakNet
	sfml-system
	sfml-audio
	sfml-graphics
	sfml-window )

add_executable( pong examples/pong/pong.cpp src/ammo/error.cpp ${ammo_files_subs} )
target_link_libraries( pong
	box2d
	RakNet
	sfml-system
	sfml-audio
	sfml-graphics
	sfml-window )

