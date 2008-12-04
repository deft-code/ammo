#ifndef AMMO_GRAPHICS_ACTIVEGRAPHICSYS_HPP_INCLUDED
#define AMMO_GRAPHICS_ACTIVEGRAPHICSYS_HPP_INCLUDED

#include <list>
#include <string>
#include <map>

#include "ammo/graphics/graphic_def.fwd.hpp"
#include "ammo/graphics/graphic_impl.fwd.hpp"
#include "ammo/graphics/graphic_sys.hpp"

namespace ammo
{
   class Graphic;

   class ActiveGraphicSys : public GraphicSys
   {
   public:
      ActiveGraphicSys( void );

      virtual void RemoveBluePrint( const std::string& name );

      virtual bool isGraphic( const std::string& name ) const;
      virtual Graphic getGraphic( const std::string& name );

      virtual void collectGraphics( void );
      virtual void collectVideoMem( void );

      virtual void update( float dt );
      virtual void draw( sf::RenderWindow& app );

   private:
      virtual void addDef( const std::string& name, GraphicDef_ptr def );

      GraphicDef_ptr getDef( const std::string& name ) const;

      Image_ptr loadImage( const std::string& filename );

		bool m_needs_resort;

      typedef std::list<GraphicPimpl> GraphicPimpls;
      GraphicPimpls m_graphics;

      typedef std::map<std::string,GraphicDef_ptr> GraphicDefs;
      GraphicDefs m_definitions;

      typedef std::map<std::string,Image_ptr> Images;
      Images m_images;
   };
}

#endif // AMMO_GRAPHICS_ACTIVEGRAPHICSYS_HPP_INCLUDED
