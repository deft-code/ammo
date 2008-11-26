#ifndef  ENTO_AUDIO_SOUND_IMPL_HPP_INCLUDED
#define  ENTO_AUDIO_SOUND_IMPL_HPP_INCLUDED

#include "ento/audio/sound_impl.fwd.hpp"

namespace ento
{
   class SoundImpl
   {
   public:
      virtual ~SoundImpl( void ) { }

      virtual void update( float dt ) =0;

      virtual bool done( void ) const =0;

      virtual void play( void ) =0;

      virtual void storeBuffer( std::size_t index, SoundBuffer_ptr buffer ) =0;
   };
}

#endif //  ENTO_AUDIO_SOUND_IMPL_HPP_INCLUDED

