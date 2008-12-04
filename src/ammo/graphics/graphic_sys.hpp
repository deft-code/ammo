#ifndef AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED

#include <string>

#include "ammo/graphics/graphic_def.fwd.hpp"

namespace ammo
{
   class Graphic;

   class GraphicSys
   {
   public:
		virtual ~GraphicSys() { }

      template< typename Def >
      void AddBluePrint( const std::string& name, const Def& def );

      virtual void RemoveBluePrint( const std::string& name ) =0;

      virtual bool isGraphic( const std::string& name ) const =0;
      virtual Graphic getGraphic( const std::string& name ) =0;

      virtual void collectGraphics( void ) =0;
		virtual void collectVideoMem( void ) =0;

      virtual void update( float dt ) =0;
      virtual void draw( sf::RenderWindow& app ) =0;

   private:
      virtual void addDef( const std::string& name, GraphicDef_ptr def ) =0;
   };

   template< typename BluePrint >
   void GraphicSys::AddBluePrint( const std::string& name, const BluePrint& bp )
   {
      GraphicDef_ptr ptr (new BluePrint(bp) );
      addDef( name, ptr );
   }
}

#endif // AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
