#ifndef AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED
#define AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED

#include "ammo/audio/sound_def.fwd.hpp"
#include "ammo/audio/sound_impl.fwd.hpp"

#include <string>

namespace ammo
{
   class Sound;

   class SoundSys
   {
   public:
		virtual ~SoundSys( void ) { }

      template< typename Def >
      void AddBluePrint( const std::string& name, const Def& def );

      virtual void removeDef( const std::string& name ) =0;

      virtual bool isSound( const std::string& name ) const =0;
      virtual Sound getSound( const std::string& name ) =0;

      virtual void collectSounds( void ) =0;
      virtual void collectBuffers( void ) =0;

      virtual void update( float dt ) =0;

   private:
      virtual void addDef( const std::string& name, SoundDef_ptr def ) =0;
   };

   template< typename Def >
   void SoundSys::AddBluePrint( const std::string& name, const Def& def )
   {
      SoundDef_ptr ptr(new Def(def) );
      addDef( name, ptr );
   }
}

#endif // AMMO_AUDIO_SOUND_SYS_HPP_INCLUDED
