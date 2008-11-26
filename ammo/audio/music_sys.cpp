#include "music_sys.hpp"
#include "../error.hpp"

namespace ammo
{
   void MusicSys::addSong( const std::string& songname, const std::string& filename )
   {
      m_songlist[songname] = filename;
   }

   void MusicSys::playSong( const std::string& songname )
   {
      m_song.Stop();
      std::map<std::string,std::string>::iterator found = m_songlist.find(songname);

      using namespace ammo::Errors;
      if( found == m_songlist.end() )
      {
         throw ammo::Error( e_Missing_Definition, songname );
      }

      if( !m_song.OpenFromFile( found->second ) )
      {
         throw ammo::Error( e_File_Load_Error, found->second );
      }

      //m_song.SetLoop();
      m_song.Play();
   }
   
   void MusicSys::update( float dt ) { }

}
