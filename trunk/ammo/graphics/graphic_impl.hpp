#ifndef  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED
#define  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.fwd.hpp"

namespace ammo
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

#endif //  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED
