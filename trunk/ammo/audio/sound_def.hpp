#ifndef ENTO_AUDIO_SOUND_DEF_HPP_INCLUDED
#define ENTO_AUDIO_SOUND_DEF_HPP_INCLUDED

#include "ento/audio/sound_def.fwd.hpp"
#include "ento/audio/sound_impl.fwd.hpp"

namespace ento
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

#endif // ENTO_AUDIO_SOUND_DEF_HPP_INCLUDED

