#include "sound.hpp"

#include "sound_impl.hpp"

namespace ento
{
   Sound::Sound( void ) { }

   Sound::Sound( SoundPimpl pimpl )
    : m_pimpl(pimpl)
   { }

   void Sound::play( void )
   {
      m_pimpl->play();
   }
}
