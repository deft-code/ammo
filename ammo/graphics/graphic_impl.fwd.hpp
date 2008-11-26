#ifndef ENTO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
#define ENTO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED

#include <boost/shared_ptr.hpp>

namespace sf
{
   class Image;
   class RenderWindow;
}

namespace ento
{
   class GraphicImpl;
   typedef boost::shared_ptr<GraphicImpl> GraphicPimpl;

   typedef boost::shared_ptr<sf::Image> Image_ptr;
}

#endif // ENTO_GRAPHICS_GRAPHIC_IMPL_FWD_HPP_INCLUDED
