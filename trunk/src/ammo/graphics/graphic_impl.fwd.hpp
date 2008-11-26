#ifndef AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED

#include <boost/shared_ptr.hpp>

namespace sf
{
   class Image;
   class RenderWindow;
}

namespace ammo
{
   class GraphicImpl;
   typedef boost::shared_ptr<GraphicImpl> GraphicPimpl;

   typedef boost::shared_ptr<sf::Image> Image_ptr;
}

#endif // AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
