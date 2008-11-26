#ifndef AMMO_AUDIO_SOUND_DEF_HPP_INCLUDED
#define AMMO_AUDIO_SOUND_DEF_HPP_INCLUDED

#include "ammo/audio/sound_def.fwd.hpp"
#include "ammo/audio/sound_impl.fwd.hpp"
#include <iostream>

namespace ammo
{
   class SoundDef
   {
   public:
      virtual ~SoundDef( void ) { }

      virtual SoundPimpl load( void ) const =0;
      virtual std::size_t numFiles( void ) const =0;
      virtual std::string const& filename( std::size_t index ) const =0;
   };
}

#endif // AMMO_AUDIO_SOUND_DEF_HPP_INCLUDED

