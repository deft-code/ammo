#ifndef AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.fwd.hpp"

namespace ammo
{
   class Graphic
   {
   public:
      Graphic( void );
      Graphic( GraphicPimpl pimpl );

      void show( void );
      void hide( void );

   private:
      GraphicPimpl m_pimpl;
   };

}

#endif // AMMO_GRAPHICS_GRAPHIC_HPP_INCLUDED
