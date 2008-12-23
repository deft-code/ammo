#ifndef AMMO_AUDIO_ACTIVE_SOUND_SYS_HPP_INCLUDED
#define AMMO_AUDIO_ACTIVE_SOUND_SYS_HPP_INCLUDED

#include "ammo/audio/sound_sys.hpp"
#include "ammo/audio/sound_def.fwd.hpp"
#include "ammo/audio/sound_impl.fwd.hpp"

#include <list>
#include <map>
#include <string>

namespace ammo
{
   class Sound;

   class ActiveSoundSys : public SoundSys
   {
   public:
      ActiveSoundSys( void );
		virtual ~ActiveSoundSys( void );

      virtual void removeDef( const std::string& name );

      virtual bool isSound( const std::string& name ) const;
      virtual Sound getSound( const std::string& name );

      virtual void collectSounds( void );
      virtual void collectBuffers( void );

      virtual void update( float dt );

   private:
      virtual void addDef( const std::string& name, SoundDef_ptr def );

      SoundDef_ptr getDef( const std::string& name ) const;
      void updateSounds( float dt );

      SoundBuffer_ptr loadBuffer( const std::string& filename );

      typedef std::list<SoundPimpl> SoundPimpls;
      SoundPimpls m_sounds;
      float m_sounds_time;
      float m_sounds_threshold;

      typedef std::map<std::string,SoundDef_ptr> SoundDefs;
      SoundDefs m_definitions;

      typedef std::map<std::string,SoundBuffer_ptr> Buffers;
      Buffers m_buffers;
      float m_buffers_time;
      float m_buffers_threshold;
   };
}

#endif // AMMO_AUDIO_ACTIVE_SOUND_SYS_HPP_INCLUDED
