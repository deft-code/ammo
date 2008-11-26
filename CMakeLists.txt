#!/usr/bin/cmake

cmake_minimum_required(VERSION 2.6)

Project( AMMO )

include_directories( src/ ../sfml/include  . ../box2d/Include ../cegui/include ../cegui/RendererModules/OpenGLGUIRenderer )
link_directories( /home/nick/projects/sfml/lib /home/nick/projects/box2d/Source/Gen/float /home/nick/projects/cegui/install/lib )

set( CMAKE_CXX_FLAGS "-Wall" )

file( GLOB ammo_files src/ammo/*.cpp )
file( GLOB ammo_files_subs src/ammo/*/*.cpp )

add_executable( ammo ${ammo_files} ${ammo_files_subs} )

target_link_libraries( ammo sfml-system sfml-audio sfml-graphics sfml-window )
