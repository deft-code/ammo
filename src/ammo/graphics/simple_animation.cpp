#include "simple_animation.hpp"

#include <Box2D.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>

#include <limits>
#include <iostream>

namespace ammo
{
   SimpleAnimationImpl::SimpleAnimationImpl( float lifetime, const std::vector<float>& times )
    : GraphicImpl(),
      m_times(times),
      m_images( m_times.size() ),
      m_z_order(0.f),
      m_show(false),
      m_time(0.f),
      m_current(0),
      m_life(0.f),
      m_lifetime(lifetime)
   { }

   void SimpleAnimationImpl::update(float dt)
   {
      m_life += dt;
      if( m_life > m_lifetime)
      {
         m_show = false;
      }

      m_time += dt;
      while( m_time > m_times[m_current] )
      {
         m_time -= m_times[m_current++];
         if( m_current >= m_times.size() )
         {
            m_current = 0;
         }
         setFrame( m_current );
         //m_sprite.SetImage( *m_images[m_current] );
         //m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
      }
   }

   void SimpleAnimationImpl::setFrame( std::size_t frame )
   {
      sf::Sprite s( *m_images[frame] );
      m_current = frame;
      b2Vec2 old_size = GetSize();
      m_sprite = s;
      m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
      SetSize( old_size );
   }

   bool SimpleAnimationImpl::done(void) const
   {
      return m_life > m_lifetime || !b2IsValid(m_lifetime);
   }

   void SimpleAnimationImpl::draw( sf::RenderWindow& render)
   {
      if( m_show )
      {
         render.Draw( m_sprite );
      }
   }

   void SimpleAnimationImpl::storeImage(std::size_t index, Image_ptr image)
   {
      assert( index < m_images.size() );
      m_images[index] = image;
      if( index == 0 )
      {
         setFrame(0);
         //sf::Sprite s( *image );
         //m_current = 0;
         //b2Vec2 old_size = GetSize();
         //m_sprite = s;
         //m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
         //SetSize( old_size );
      }
   }

   void SimpleAnimationImpl::show(void)
   {
      m_show = true;
      m_life = 0.f;
      m_time = 0.f;
      m_current = 0;
   }

   void SimpleAnimationImpl::hide(void)
   {
      m_show = false;
   }

   float SimpleAnimationImpl::GetRotationDegrees( void ) const
   {
     return m_sprite.GetRotation();
   }

   void SimpleAnimationImpl::SetRotationDegrees(const float rot)
   {
     m_sprite.SetRotation(rot);
   }

   void SimpleAnimationImpl::SetRotationRadians(const float rot)
   {
      SetRotationDegrees(RAD_TO_DEG_MULTIPLE * rot);
   }

   sf::Blend::Mode SimpleAnimationImpl::GetRenderMode( void ) const
   {
     return m_sprite.GetBlendMode();
   }

   void SimpleAnimationImpl::SetRenderMode(const sf::Blend::Mode mode )
   {
     m_sprite.SetBlendMode(mode);
   }

   b2Vec2 SimpleAnimationImpl::GetPosition( void ) const
   {
      return b2Vec2(m_sprite.GetPosition().x, -m_sprite.GetPosition().y );
   }

   void SimpleAnimationImpl::SetPosition( const b2Vec2& pos )
   {
      m_sprite.SetX(pos.x);
      m_sprite.SetY(-pos.y);
   }

   b2Vec2 SimpleAnimationImpl::GetSize( void ) const
   {
      sf::Vector2f dim = m_sprite.GetSize();
      return b2Vec2( dim.x, dim.y);
   }
   
   void SimpleAnimationImpl::SetSize( const b2Vec2& size )
   {
      const sf::IntRect& sub_rect = m_sprite.GetSubRect();

      float scale_x = size.x / sub_rect.GetWidth();
      m_sprite.SetScaleX( scale_x );

      float scale_y = size.y / sub_rect.GetHeight();
      m_sprite.SetScaleY( scale_y );
   }

	float SimpleAnimationImpl::GetZOrder( void ) const
	{
		return m_z_order;
	}

	void SimpleAnimationImpl::SetZOrder( float z ) 
	{
		m_z_order = z;
	}

   //
   // --- SimpleAnimationDef ---
   //

   SimpleAnimationDef::SimpleAnimationDef( void )
    : GraphicDef(),
      m_lifetime( std::numeric_limits<float>::infinity() )
   { }

   const std::string& SimpleAnimationDef::filename( std::size_t index ) const
   {
      assert( index < m_filenames.size() );
      return m_filenames[index];
   }

   std::size_t SimpleAnimationDef::numFiles( void ) const
   {
      return m_filenames.size();
   }

   GraphicPimpl SimpleAnimationDef::load( void ) const
   {
      return GraphicPimpl( new SimpleAnimationImpl( m_lifetime, m_times ) );
   }
}
