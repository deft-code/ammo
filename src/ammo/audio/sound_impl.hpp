#ifndef  AMMO_AUDIO_SOUND_IMPL_HPP_INCLUDED
#define  AMMO_AUDIO_SOUND_IMPL_HPP_INCLUDED

#include "ammo/audio/sound_impl.fwd.hpp"

namespace ammo
{
   class SoundImpl
   {
   public:
      virtual ~SoundImpl( void ) { }

      virtual void update( float dt ) =0;

      virtual bool done( void ) const =0;

      virtual void play( void ) =0;

		virtual void stop( void ) =0;

      virtual void storeBuffer( std::size_t index, SoundBuffer_ptr buffer ) =0;
   };
}

#endif //  AMMO_AUDIO_SOUND_IMPL_HPP_INCLUDED

