#ifndef AMMO_AUDIO_PASSIVE_SOUND_SYS_HPP_INCLUDED
#define AMMO_AUDIO_PASSIVE_SOUND_SYS_HPP_INCLUDED

#include "ammo/audio/sound_sys.hpp"
#include "ammo/audio/sound_def.fwd.hpp"
#include "ammo/audio/sound_impl.fwd.hpp"

#include <string>

namespace ammo
{
   class Sound;

   class PassiveSoundSys : public SoundSys
   {
   public:
		virtual ~PassiveSoundSys( void );

      virtual void removeDef( const std::string& name );

      virtual bool isSound( const std::string& name ) const;
      virtual Sound getSound( const std::string& name );

      void collectSounds( void );
      void collectBuffers( void );

      virtual void update( float dt );

   private:
      virtual void addDef( const std::string& name, SoundDef_ptr def );
   };
}

#endif // AMMO_AUDIO_PASSIVE_SOUND_SYS_HPP_INCLUDED
