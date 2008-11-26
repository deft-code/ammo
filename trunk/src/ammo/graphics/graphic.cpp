#include "graphic.hpp"

#include "graphic_impl.hpp"

namespace ammo
{
   Graphic::Graphic( void ) { }
   
   Graphic::Graphic( GraphicPimpl pimpl )
    : m_pimpl(pimpl)
   { }
   
   void Graphic::show( void )
   {
      m_pimpl->show();
   }
   
   void Graphic::hide( void )
   {
      m_pimpl->hide();
   }
}
