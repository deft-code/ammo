#ifndef AMMO_GRAPHICS_PASSIVEGRAPHICSYS_HPP_INCLUDED
#define AMMO_GRAPHICS_PASSIVEGRAPHICSYS_HPP_INCLUDED

#include <string>
#include "ammo/graphics/graphic_sys.hpp"
#include "ammo/graphics/graphic_def.fwd.hpp"

namespace ammo
{
   class Graphic;

   class PassiveGraphicSys : public GraphicSys
   {
   public:
		virtual ~PassiveGraphicSys( void );

      virtual void RemoveBluePrint( const std::string& name );

      virtual bool isGraphic( const std::string& name ) const;
      virtual Graphic getGraphic( const std::string& name );

      virtual void collectGraphics( void );
      virtual void collectVMemory( void );

      virtual void update( float dt );
      virtual void draw( sf::RenderWindow& app );

   private:
      virtual void addDef( const std::string& name, GraphicDef_ptr def );
   };
}

#endif // AMMO_GRAPHICS_PASSIVEGRAPHICSYS_HPP_INCLUDED
