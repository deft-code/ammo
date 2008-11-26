#include "simple_animation.hpp"

#include <Box2D.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>

#include <limits>
#include <iostream>

namespace ento
{
   SimpleAnimationImpl::SimpleAnimationImpl( float lifetime, const std::vector<float>& times )
    : GraphicImpl(),
      m_times(times),
      m_images( m_times.size() ),
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
         m_sprite.SetImage( *m_images[m_current] );
         m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
      }
   }

   bool SimpleAnimationImpl::done(void) const
   {
      return m_life > m_lifetime ||  !b2IsValid(m_lifetime);
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
         m_current = 0;
         m_sprite.SetImage( *image );
         m_sprite.SetCenter( m_sprite.GetSize() * 0.5f );
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
