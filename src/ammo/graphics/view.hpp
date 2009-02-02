#ifndef AMMO_GRAPHICS_VIEW_HPP_INCLUDED
#define AMMO_GRAPHICS_VIEW_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <Box2D.h>

namespace ammo
{
   class View
   {
   public:
      View( sf::RenderWindow& app );

      void lookAt( const b2Vec2& pos );
      b2Vec2 lookingAt( void ) const;

      void zoom( float factor );

      float getWidth( void ) const;
      void setWidth( float width );

      float getHeight( void ) const;
      void setHeight( float height );

      void HUDview( bool hud );

      void update_view( void );

      sf::Vector2f world2draw( const b2Vec2& vec ) const;
      b2Vec2 draw2world( const sf::Vector2f& vec ) const;

      sf::Vector2f world2HUD( const b2Vec2& vec ) const;
      b2Vec2 HUD2world( const sf::Vector2f& vec ) const;

   private:
      

      sf::RenderWindow* m_app;
      bool m_is_hud;
      sf::View m_world_view;
   };
}//namespace ammo

#endif // AMMO_GRAPHICS_VIEW_HPP_INCLUDED
