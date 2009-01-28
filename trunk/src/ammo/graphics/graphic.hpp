#ifndef AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.fwd.hpp"
#include "ammo/graphics/icameratarget.hpp"
#include <Box2D.h>

namespace ammo
{
  class Graphic : public ICameraTarget
   {
   public:
      Graphic( void );
      Graphic( GraphicPimpl pimpl );

      void show( void );
      void hide( void );
      
      float GetRotationDegrees( void ) const;
      void SetRotationDegrees( const float rot);
      void SetRotationRadians( const float rot);

      sf::Blend::Mode GetRenderMode( void ) const;
      void SetRenderMode( const sf::Blend::Mode mode );

      b2Vec2 GetPosition( void ) const;
  
      void SetPosition( const b2Vec2& pos );

      void SetX( float x );

      void SetY( float y );

      void Move( const b2Vec2& delta );

      b2Vec2 GetSize( void ) const;
		void SetSize( const b2Vec2& size );

		float GetZOrder( void ) const;
		void SetZOrder( float z );

   private:
      GraphicPimpl m_pimpl;
   };

}

#endif // AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
