#ifndef AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED

#include <boost/shared_ptr.hpp>
//#include <SFML/Graphics/Drawable.hpp>

namespace sf
{
   class Image;
   class RenderWindow;
   namespace Blend
    {
        enum Mode;
    }
}

namespace ammo
{
   class GraphicImpl;
   typedef boost::shared_ptr<GraphicImpl> GraphicPimpl;

   typedef boost::shared_ptr<sf::Image> Image_ptr;
}

#endif // AMMO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
