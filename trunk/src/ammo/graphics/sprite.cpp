#include "sprite.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D.h>

#include <limits>

namespace ammo
{
   SpriteImpl::SpriteImpl( const SpriteSchema& schema ) :
		m_z_order(0.f),
      m_show(false),
      m_life(0.f),
      m_lifetime(schema.m_lifetime),
		m_subrect(schema.m_subrect),
		m_size(schema.m_size)
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
		if( m_subrect.GetWidth() > 0 && m_subrect.GetHeight() > 0 )
		{
			m_sprite.SetSubRect( m_subrect );
		}
      m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );

		if( m_size.x > 0 )
		{
			SetSize( m_size );
		}
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

   Degrees SpriteImpl::GetAngle() const
   {
      return Degrees(m_sprite.GetRotation());
   }

   void SpriteImpl::SetAngle(Degrees angle)
   {
     m_sprite.SetRotation(angle.asDegrees());
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

	bool SpriteImpl::Meta( int meta, ... ) { return false; }

   //
   // --- SpriteDef ---
   //

   SpriteSchema::SpriteSchema( void )
    : GraphicSchema(),
      m_lifetime( std::numeric_limits<float>::infinity() ),
		m_subrect(0,0,0,0),
		m_size(b2Vec2_zero)
   { }

   SpriteSchema::SpriteSchema( const std::string& filename )
    : GraphicSchema(),
      m_filename(filename),
      m_lifetime( std::numeric_limits<float>::infinity() ),
		m_subrect(0,0,0,0),
		m_size(b2Vec2_zero)
   { }

   const std::string& SpriteSchema::filename( std::size_t index ) const
   {
      return m_filename;
   }

   std::size_t SpriteSchema::numFiles( void ) const
   {
      return 1;
   }

   GraphicPimpl SpriteSchema::Instantiate( void ) const
   {
      return GraphicPimpl( new SpriteImpl( *this ) );
   }
}
