#include "passive_sound_sys.hpp"

//#include "sound_def.hpp"
#include "sound.hpp"

namespace ammo
{

PassiveSoundSys::~PassiveSoundSys( void ) { }

void PassiveSoundSys::removeDef( const std::string& name ) { }

bool PassiveSoundSys::isSound( std::string const& name ) const
{ return true; }

Sound PassiveSoundSys::getSound( std::string const& name )
{ return Sound(); }

void PassiveSoundSys::collectSounds( void ) { }

void PassiveSoundSys::collectBuffers( void ) { }

void PassiveSoundSys::update( float dt ) { }

void PassiveSoundSys::addDef( const std::string& name, SoundDef_ptr def ) { }

} // namespace ammo
