#ifndef AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
#define AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED

#include <string>

#include "ammo/graphics/graphic_def.fwd.hpp"

namespace sf
{
	class RenderWindow;
}

namespace ammo
{
   class Graphic;

   class GraphicSys
   {
   public:
		virtual ~GraphicSys() { }

      template< typename Schema >
      void AddSchema( const std::string& name, const Schema& schema );

      virtual void RemoveSchema( const std::string& name ) =0;

      virtual bool IsGraphic( const std::string& name ) const =0;

		/// create a named graphic
      virtual Graphic NewGraphic( const std::string& name ) =0;

		/// create an anonymous graphic
      virtual Graphic NewGraphic( const GraphicSchema& schema ) =0;

      virtual void CollectGraphics( void ) =0;
		virtual void CollectVideoMem( void ) =0;

      virtual void Update( float dt ) =0;
      virtual void Draw( sf::RenderWindow& app ) =0;

   private:
      virtual void NewSchema( const std::string& name, GraphicSchema_ptr def ) =0;
   };

   template< typename Schema >
   void GraphicSys::AddSchema( const std::string& name, const Schema& schema )
   {
      GraphicSchema_ptr ptr (new Schema(schema) );
      NewSchema( name, ptr );
   }
}

#endif // AMMO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
