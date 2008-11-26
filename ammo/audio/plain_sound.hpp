#ifndef ENTO_AUDIO_PLAIN_SOUND_HPP_INCLUDED
#define ENTO_AUDIO_PLAIN_SOUND_HPP_INCLUDED

#include "ento/audio/sound_def.hpp"
#include "ento/audio/sound_impl.hpp"

#include <SFML/Audio/Sound.hpp>
#include <string>

namespace ento
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

#endif //  ENTO_AUDIO_PLAIN_SOUND_HPP_INCLUDED
