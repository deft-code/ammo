#ifndef AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED
#define AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED

#include "ammo/audio/sound_def.fwd.hpp"
#include "ammo/audio/sound_impl.fwd.hpp"

#include <list>
#include <map>
#include <string>
//#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

namespace ammo
{
   class Sound;

   class SoundSys
   {
   public:
      SoundSys( void );
		~SoundSys( void );

      template< typename Def >
      void addDef( const std::string& name, const Def& def );
      void aliasDef( const std::string& name, const std::string& alias );
      void removeDef( const std::string& name );

      bool isSound( const std::string& name ) const;
      Sound getSound( const std::string& name );

      void collect( void );
      void update( float dt );

   private:
      SoundDef_ptr getDef( const std::string& name ) const;
      void addDef( const std::string& name, SoundDef_ptr def );
      void updateSounds( float dt );
      void collectSounds( void );
      void collectBuffers( void );

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

   template< typename Def >
   void SoundSys::addDef( const std::string& name, const Def& def )
   {
//      BOOST_STATIC_ASSERT(( boost::is_base_of<SoundDef,Def>::value ));
      SoundDef_ptr ptr(new Def(def) );
      addDef( name, ptr );
   }
}

#endif // AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED
