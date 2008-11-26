#ifndef AMMO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED
#define AMMO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED

#include <boost/shared_ptr.hpp>

namespace sf
{
   class SoundBuffer;
}

namespace ammo
{
   class SoundImpl;
   typedef boost::shared_ptr<SoundImpl> SoundPimpl;

   typedef boost::shared_ptr<sf::SoundBuffer> SoundBuffer_ptr;
}

#endif // AMMO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED
