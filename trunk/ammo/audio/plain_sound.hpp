#ifndef AMMO_AUDIO_PLAIN_SOUND_HPP_INCLUDED
#define AMMO_AUDIO_PLAIN_SOUND_HPP_INCLUDED

#include "ammo/audio/sound_def.hpp"
#include "ammo/audio/sound_impl.hpp"

#include <SFML/Audio/Sound.hpp>
#include <string>

namespace ammo
{

   class PlainImpl : public SoundImpl
   {
   public:
      virtual ~PlainImpl( void ) { }

      virtual void update( float dt ) {	}

      virtual bool done( void ) const;

      virtual void play(void);

      virtual void storeBuffer( std::size_t index, SoundBuffer_ptr buffer );

   private:
      sf::Sound m_sound;
      SoundBuffer_ptr m_buffer;
   };

   class PlainDef : public SoundDef
   {
   public:
      virtual ~PlainDef( void ) { }

      virtual std::size_t numFiles( void ) const;
      virtual const std::string& filename( std::size_t index) const;
      virtual SoundPimpl load(void) const;

      std::string m_filename;
   };

}

#endif //  AMMO_AUDIO_PLAIN_SOUND_HPP_INCLUDED
