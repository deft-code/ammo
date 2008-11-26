#ifndef ENTO_AUDIO_SOUND_HPP_INCLUDED
#define ENTO_AUDIO_SOUND_HPP_INCLUDED

#include "ento/audio/sound_impl.fwd.hpp"

namespace ento
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
} // namespace ento

#endif // ENTO_AUDIO_SOUND_HPP_INCLUDED
