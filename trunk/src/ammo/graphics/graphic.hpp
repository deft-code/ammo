#ifndef AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.fwd.hpp"
#include <Box2D.h>

namespace ammo
{
   class Graphic
   {
   public:
      Graphic( void );
      Graphic( GraphicPimpl pimpl );

      void show( void );
      void hide( void );

      b2Vec2 GetPosition( void ) const;

      void SetPosition( const b2Vec2& pos );

      void Move( const b2Vec2& delta );

   private:
      GraphicPimpl m_pimpl;
   };

}

#endif // AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
