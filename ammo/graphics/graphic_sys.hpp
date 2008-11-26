#ifndef ENTO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
#define ENTO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED

#include <list>
#include <string>
#include <map>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "ento/graphics/graphic_def.fwd.hpp"
#include "ento/graphics/graphic_impl.fwd.hpp"

namespace ento
{
   class Graphic;

   class GraphicSys
   {
   public:
      GraphicSys( void );

      template< typename Def >
      void addDef( const std::string& name, const Def& def );
      void aliasDef( const std::string& name, const std::string& alias );
      void removeDef( const std::string& name );

      bool isGraphic( const std::string& name ) const;
      Graphic getGraphic( const std::string& name );

      void collect( void );
      void update( float dt );
      void draw( sf::RenderWindow& app );

   private:
      GraphicDef_ptr getDef( const std::string& name ) const;
      void addDef( const std::string& name, GraphicDef_ptr def );
      void updateGraphics( float dt );
      void collectGraphics( void );
      void collectImages( void );

      Image_ptr loadImage( const std::string& filename );

      typedef std::list<GraphicPimpl> GraphicPimpls;
      GraphicPimpls m_graphics;

      typedef std::map<std::string,GraphicDef_ptr> GraphicDefs;
      GraphicDefs m_definitions;

      typedef std::map<std::string,Image_ptr> Images;
      Images m_images;
   };

   template< typename Def >
   void GraphicSys::addDef( const std::string& name, const Def& def )
   {
      BOOST_STATIC_ASSERT(( boost::is_base_of<GraphicDef,Def>::value ));
      GraphicDef_ptr ptr (new Def(def) );
      addDef( name, ptr );
   }
}

#endif // ENTO_GRAPHICS_GRAPHICSYS_HPP_INCLUDED
