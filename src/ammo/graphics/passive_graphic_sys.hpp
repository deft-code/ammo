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
   };
}

#endif // AMMO_GRAPHICS_PASSIVEGRAPHICSYS_HPP_INCLUDED
