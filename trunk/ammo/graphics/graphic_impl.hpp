#ifndef  ENTO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED
#define  ENTO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED

#include "ento/graphics/graphic_impl.fwd.hpp"

namespace ento
{
   class GraphicImpl
   {
   public:
      virtual ~GraphicImpl( void ) { }

      virtual void update( float dt ) =0;

      virtual bool done( void ) const =0;

      virtual void draw( sf::RenderWindow& render ) =0;

      virtual void storeImage( std::size_t index, Image_ptr image ) =0;

      virtual void show( void ) =0;

      virtual void hide( void ) =0;
   };
}

#endif //  ENTO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED
