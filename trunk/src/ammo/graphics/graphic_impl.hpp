#ifndef  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED
#define  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.fwd.hpp"
#include <Box2D.h>

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

      virtual b2Vec2 GetPosition( void ) const =0;
      virtual void SetPosition( const b2Vec2& pos ) =0;

      virtual b2Vec2 GetSize( void ) const =0;
		virtual void SetSize( const b2Vec2& size ) =0;

		virtual float GetZOrder( void ) const =0;
		virtual void SetZOrder( float z ) =0;
		

   };
}

#endif //  AMMO_GRAPHICS_SOUND_IMPL_HPP_INCLUDED