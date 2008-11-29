#include "sound.hpp"

#include "sound_impl.hpp"

namespace // anonymous
{
   /// implements the Null Object Design Pattern for Sound objects
   class NullSoundImpl : public ammo::SoundImpl
   {
   public:
      virtual void update( float dt ) { }
      virtual bool done( void ) const { return true; }
      virtual void play( void ) { }
      virtual void storeBuffer( std::size_t index, ammo::SoundBuffer_ptr buffer ) { }
   };

   void do_nothing( ammo::SoundImpl* unused ) { }

   NullSoundImpl s_null_sound;
   ammo::SoundPimpl s_null_pimpl( &s_null_sound, do_nothing );
} // anonymous namespace


namespace ammo
{
   Sound::Sound( void )
    : m_pimpl(s_null_pimpl)
   { }

   Sound::Sound( SoundPimpl pimpl )
    : m_pimpl(pimpl)
   { }

   void Sound::play( void )
   {
      m_pimpl->play();
   }
}
