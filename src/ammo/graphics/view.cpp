#include "view.hpp"

namespace ammo
{

View::View( sf::RenderWindow& app )
 : m_app(&app), m_is_hud(false),
   //look at origin with native resolution
   m_world_view( sf::Vector2f(0,0), sf::Vector2f(
      m_app->GetWidth() / 2.f, m_app->GetHeight() / 2.f ) )
{
   m_app->SetView( m_world_view );
}

void View::
lookAt( const b2Vec2& pos )
{
   m_world_view.SetCenter( pos.x, -pos.y );
   update_view();
}

b2Vec2 View::
lookingAt( void ) const
{
   const sf::Vector2f& p = m_world_view.GetCenter();
   return b2Vec2( p.x, -p.y );
}

void View::
zoom( float factor )
{
   m_world_view.Zoom( factor );
}

float View::
getWidth( void ) const
{ return m_world_view.GetHalfSize().x * 2.f; }

void View::
setWidth( float width )
{
   const float half_width = width * 0.5f;

   const float height = (m_app->GetHeight()*width) / m_app->GetWidth();
   const float half_height = height * 0.5f;

   m_world_view.SetHalfSize( half_width, half_height );

   update_view();
}

float View::
getHeight( void ) const
{ return m_world_view.GetHalfSize().y * 2.f; }

void View::
setHeight( float height )
{
   const float half_height = height * 0.5f;

   const float width = (m_app->GetWidth()*height) / m_app->GetHeight();
   const float half_width = width * 0.5f;

   m_world_view.SetHalfSize( half_width, half_height );

   update_view();
}

void View::
update_view( void )
{
   if( ! m_is_hud )
   {
      m_app->SetView( m_world_view );
   }
}

void View::
HUDview( bool hud )
{
   if( m_is_hud )
   {
      if( ! hud )
      {
         m_app->SetView( m_world_view );
      }
   }
   else
   {
      if( hud )
      {
         m_app->SetView( m_app->GetDefaultView() );
      }

   }
}

sf::Vector2f View::
world2draw( const b2Vec2& vec ) const
{
   return sf::Vector2f( vec.x, -vec.y );
}

b2Vec2 View::
draw2world( const sf::Vector2f& vec ) const
{
   return b2Vec2( vec.x, -vec.y );
}

b2Vec2 View::
HUD2world( const sf::Vector2f& vec ) const
{
   sf::Vector2f converted = m_app->ConvertCoords(
      static_cast<unsigned>(vec.x), static_cast<unsigned>( vec.y ),
      &m_world_view );

   return b2Vec2( converted.x, -converted.y );
}


} // namespace ammo

