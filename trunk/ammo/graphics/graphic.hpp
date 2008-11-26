#ifndef ENTO_GRAPHICS_GRAPHIC_HPP_INCLUDED
#define ENTO_GRAPHICS_GRAPHIC_HPP_INCLUDED

#include "ento/graphics/graphic_impl.fwd.hpp"

namespace ento
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

#endif // ENTO_GRAPHICS_GRAPHIC_HPP_INCLUDED
