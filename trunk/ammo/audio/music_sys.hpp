#ifndef ENTO_AUDIO_MUSIC_SYS_HPP_INCLUDED
#define ENTO_AUDIO_MUSIC_SYS_HPP_INCLUDED

#include <SFML/Audio/Music.hpp>

#include <string>
#include <map>

namespace ento
{
   class MusicSys
   {
   public:
      void addSong( const std::string& songname, const std::string& filename );
      void playSong( const std::string& songname );

      void update( float dt );

   private:
      sf::Music m_song;
      std::map<std::string,std::string> m_songlist;
   };
}

#endif // ENTO_AUDIO_MUSIC_SYS_HPP_INCLUDED
