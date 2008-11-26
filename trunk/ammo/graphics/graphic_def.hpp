#ifndef ENTO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED
#define ENTO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED

#include "ento/graphics/graphic_def.fwd.hpp"
#include "ento/graphics/graphic_impl.fwd.hpp"

namespace ento
{
   class GraphicDef
   {
   public:
      virtual ~GraphicDef( void ) { }

      virtual GraphicPimpl load( void ) const =0;
      virtual std::size_t numFiles( void ) const =0;
      virtual const std::string& filename( std::size_t index ) const =0;
   };
}

#endif // ENTO_GRAPHICS_GRAPHIC_DEF_HPP_INCLUDED

