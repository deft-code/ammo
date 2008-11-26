#ifndef ENTO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED
#define ENTO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED

#include <boost/shared_ptr.hpp>

namespace sf
{
   class SoundBuffer;
}

namespace ento
{
   class SoundImpl;
   typedef boost::shared_ptr<SoundImpl> SoundPimpl;

   typedef boost::shared_ptr<sf::SoundBuffer> SoundBuffer_ptr;
}

#endif // ENTO_AUDIO_SOUND_IMPL_FWD_HPP_INCLUDED
