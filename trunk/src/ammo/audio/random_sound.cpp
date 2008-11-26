#include "random_sound.hpp"
#include <SFML/System/Randomizer.hpp>
#include <iostream>
#include <cassert>

namespace ammo
{
   RandomImpl::RandomImpl( std::size_t num_sounds )
    : SoundImpl(),
      m_buffers(num_sounds)
   { }

   bool RandomImpl::done( void ) const
   {
      return m_sound.GetStatus() == sf::Sound::Stopped;
   }

   void RandomImpl::play( void )
   {
      int index = sf::Randomizer::Random(0,m_buffers.size()-1);
      m_sound.Stop();
      m_sound.SetBuffer( *m_buffers[index] );
      m_sound.Play();
   }

   void RandomImpl::storeBuffer( std::size_t index, SoundBuffer_ptr buffer )
   {
      assert( index < m_buffers.size() );
      m_buffers[index] = buffer;
   }

   std::size_t RandomDef::numFiles( void ) const
   {
      return m_filenames.size();
   }

   const std::string& RandomDef::filename( std::size_t index ) const
   {
      assert( index < m_filenames.size() );
      return m_filenames[index];
   }

   SoundPimpl RandomDef::load( void ) const
   {
      return SoundPimpl( new RandomImpl(m_filenames.size()) );
   }

   
}
