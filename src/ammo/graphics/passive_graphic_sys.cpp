#include "passive_graphic_sys.hpp"

#include "../error.hpp"
#include "graphic_def.hpp"
#include "graphic.hpp"
#include "graphic_impl.hpp"

#include <SFML/Graphics/Image.hpp>
#include <limits>

namespace ammo
{

PassiveGraphicSys::~PassiveGraphicSys( void ) { }

void PassiveGraphicSys::RemoveSchema( const std::string& name ) { }

bool PassiveGraphicSys::IsGraphic( std::string const& name ) const
{ return true; }

Graphic PassiveGraphicSys::NewGraphic( const std::string& name )
{ return Graphic(); }

Graphic PassiveGraphicSys::NewGraphic( const GraphicSchema& schema )
{ return Graphic(); }

void PassiveGraphicSys::CollectGraphics( void ) { }

void PassiveGraphicSys::CollectVideoMem( void ) { }

void PassiveGraphicSys::Update( float dt ) { }

void PassiveGraphicSys::Draw( sf::RenderWindow& app ) { }

void PassiveGraphicSys::NewSchema( const std::string& name, GraphicSchema_ptr schema ) { }

} // namespace ammo
