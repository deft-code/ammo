#include "sprite.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D.h>

#include <limits>
#include <iostream>

namespace ammo
{
   SpriteImpl::SpriteImpl( float lifetime )
    : GraphicImpl(),
		m_z_order(0.f),
      m_show(false),
      m_life(0.f),
      m_lifetime(lifetime)
   { }

   void SpriteImpl::update(float dt)
   {
      m_life += dt;
      if( m_life > m_lifetime)
      {
			m_show = false;
      }
   }

   bool SpriteImpl::done(void) const
   {
      return m_life > m_lifetime || !b2IsValid(m_lifetime);
   }

   void SpriteImpl::draw( sf::RenderWindow& render)
   {
      if( m_show )
      {
			render.Draw( m_sprite );
      }
   }

   void SpriteImpl::storeImage(std::size_t index, Image_ptr image)
   {
      assert( index == 0 );
      m_image = image;
      m_sprite.SetImage(*m_image);
      m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
   }

   void SpriteImpl::show(void)
   {
      m_show = true;
      m_life = 0.f;
   }

   void SpriteImpl::hide(void)
   {
      m_show = false;
   }

   float SpriteImpl::GetRotationDegrees() const
   {
      return m_sprite.GetRotation();
   }

   void SpriteImpl::SetRotationDegrees(const float rot)
   {
     m_sprite.SetRotation(rot);
   }

   void SpriteImpl::SetRotationRadians(const float rot)
   {
      SetRotationDegrees(RAD_TO_DEG_MULTIPLE * rot);
   }

   b2Vec2 SpriteImpl::GetPosition( void ) const
   {
      return b2Vec2(m_sprite.GetPosition().x, -m_sprite.GetPosition().y );
   }

   void SpriteImpl::SetPosition( const b2Vec2& pos )
   {
      m_sprite.SetX(pos.x);
      m_sprite.SetY(-pos.y);
   }

   sf::Blend::Mode SpriteImpl::GetRenderMode( void ) const
   {
     return m_sprite.GetBlendMode();
   }

   void SpriteImpl::SetRenderMode( const sf::Blend::Mode mode )
   {
     m_sprite.SetBlendMode(mode);
   }

   b2Vec2 SpriteImpl::GetSize( void ) const
   {
      sf::Vector2f dim = m_sprite.GetSize();
      return b2Vec2( dim.x, dim.y);
   }

   void SpriteImpl::SetSize( const b2Vec2& size )
   {
      const sf::IntRect& sub_rect = m_sprite.GetSubRect();

      

      float scale_x = size.x / sub_rect.GetWidth();
      m_sprite.SetScaleX( scale_x );

      float scale_y = size.y / sub_rect.GetHeight();
      m_sprite.SetScaleY( scale_y );      
   }

	float SpriteImpl::GetZOrder( void ) const
	{
		return m_z_order;
	}

	void SpriteImpl::SetZOrder( float z ) 
	{
		m_z_order = z;
	}

   //
   // --- SpriteDef ---
   //

   SpriteDef::SpriteDef( void )
    : GraphicDef(),
      m_lifetime( std::numeric_limits<float>::infinity() )
   { }

   SpriteDef::SpriteDef( const std::string& filename )
    : GraphicDef(),
      m_filename(filename),
      m_lifetime( std::numeric_limits<float>::infinity() )
   { }

   const std::string& SpriteDef::filename( std::size_t index ) const
   {
      return m_filename;
   }

   std::size_t SpriteDef::numFiles( void ) const
   {
      return 1;
   }

   GraphicPimpl SpriteDef::load( void ) const
   {
      return GraphicPimpl( new SpriteImpl( m_lifetime ) );
   }
}
