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

      virtual void RemoveSchema( const std::string& name );

      virtual bool IsGraphic( const std::string& name ) const;
      virtual Graphic NewGraphic( const std::string& name );
		virtual Graphic NewGraphic( const GraphicSchema& schema );

      virtual void CollectGraphics( void );
      virtual void CollectVideoMem( void );

      virtual void Update( float dt );
      virtual void Draw( sf::RenderWindow& app );

   private:
      virtual void NewSchema( const std::string& name, GraphicSchema_ptr schema );

      GraphicSchema_ptr getDef( const std::string& name ) const;

      Image_ptr loadImage( const std::string& filename );

		bool m_needs_resort;

      typedef std::list<GraphicPimpl> GraphicPimpls;
      GraphicPimpls m_graphics;

      typedef std::map<std::string,GraphicSchema_ptr> GraphicDefs;
      GraphicDefs m_definitions;

      typedef std::map<std::string,Image_ptr> Images;
      Images m_images;
   };
}

#endif // AMMO_GRAPHICS_ACTIVEGRAPHICSYS_HPP_INCLUDED
