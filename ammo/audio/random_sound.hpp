#ifndef AMMO_AUDIO_RANDOM_SOUND_HPP_INCLUDED
#define AMMO_AUDIO_RANDOM_SOUND_HPP_INCLUDED

#include "ammo/audio/sound_def.hpp"
#include "ammo/audio/sound_impl.hpp"

#include <SFML/Audio/Sound.hpp>
#include <string>
#include <vector>

namespace ammo
{

   class RandomImpl : public SoundImpl
   {
   public:
      RandomImpl( std::size_t num_sounds );
      virtual ~RandomImpl( void ) { }

      virtual void update( float dt ) {	}

      virtual bool done( void ) const;
     
      virtual void play(void);

      virtual void storeBuffer(std::size_t index, SoundBuffer_ptr buffer);

   private:
      sf::Sound m_sound;
      std::vector<SoundBuffer_ptr> m_buffers;
   };

   class RandomDef : public SoundDef
   {
   public:
      virtual ~RandomDef( void ) { }

      virtual std::size_t numFiles(void) const;
      virtual const std::string& filename(std::size_t index) const;

      virtual SoundPimpl load(void) const;

      std::vector<std::string> m_filenames;
   };

}

#endif // AMMO_AUDIO_RANDOM_SOUND_HPP_INCLUDED
