#ifndef AMMO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED

#include "ammo/graphics/graphic_def.fwd.hpp"
#include "ammo/graphics/graphic_impl.fwd.hpp"
#include <string>

namespace ammo
{
   class GraphicSchema
   {
   public:
      virtual ~GraphicSchema( void ) { }

      virtual GraphicPimpl load( void ) const =0;
      virtual std::size_t numFiles( void ) const =0;
      virtual const std::string& filename( std::size_t index ) const =0;
   };
}

#endif // AMMO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED

