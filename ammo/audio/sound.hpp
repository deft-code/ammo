#ifndef AMMO_AUDIO_SOUND_HPP_INCLUDED
#define AMMO_AUDIO_SOUND_HPP_INCLUDED

#include "ammo/audio/sound_impl.fwd.hpp"

namespace ammo
{
   class Sound
   {
   public:
      Sound( void );
      Sound( SoundPimpl pimpl );
   
      void play( void );
   
   private:
      SoundPimpl m_pimpl;
   };
} // namespace ammo

#endif // AMMO_AUDIO_SOUND_HPP_INCLUDED
