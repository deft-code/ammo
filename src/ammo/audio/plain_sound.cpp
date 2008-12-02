#include "plain_sound.hpp"

namespace ammo
{

   bool PlainImpl::done( void ) const
   {
      return m_sound.GetStatus() == sf::Sound::Stopped;
   }

   void PlainImpl::play( void )
   {
      m_sound.Play();
   }

   void PlainImpl::stop( void )
   {
      m_sound.Stop();
   }

   void PlainImpl::storeBuffer( std::size_t index, SoundBuffer_ptr buffer )
   {
      m_buffer = buffer;
      m_sound.SetBuffer( *m_buffer );
   }

   PlainDef::PlainDef( void )
    : SoundDef()
   { }

   PlainDef::PlainDef( const std::string& filename )
    : SoundDef(),
      m_filename(filename)
   { }

   std::size_t PlainDef::numFiles( void ) const
   { return 1; }

   const std::string& PlainDef::filename( std::size_t index ) const
   {
      assert( index == 0 );
      return m_filename;
   }

   SoundPimpl PlainDef::load( void ) const
   {
      return SoundPimpl( new PlainImpl );
   }
}
