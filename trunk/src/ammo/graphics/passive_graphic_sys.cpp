#include "graphic_sys.hpp"

#include "../error.hpp"
#include "graphic_def.hpp"
#include "graphic.hpp"
#include "graphic_impl.hpp"

#include <SFML/Graphics/Image.hpp>
#include <limits>

namespace ammo
{

PassiveGraphicSys::~PassiveGraphicSys( void ) { }

void PassiveGraphicSys::RemoveBluePrint( const std::string& name ) { }

bool PassiveGraphicSys::isGraphic( std::string const& name ) const
{ return true; }

Graphic PassiveGraphicSys::getGraphic( std::string const& name )
{ return Graphic(); }

void PassiveGraphicSys::collectGraphics( void ) { }

void PassiveGraphicSys::collectVideoMem( void ) { }

void PassiveGraphicSys::update( float dt ) { }

void PassiveGraphicSys::draw( sf::RenderWindow& app ) { }

void PassiveGraphicSys::addDef( const std::string& name, GraphicDef_ptr def ) { }

} // namespace ammo
