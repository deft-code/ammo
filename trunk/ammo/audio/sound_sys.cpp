#include "sound_sys.hpp"

#include "../error.hpp"
#include "sound_def.hpp"
#include "sound.hpp"
#include "sound_impl.hpp"

#include <SFML/Audio/SoundBuffer.hpp>

namespace ammo
{

SoundSys::SoundSys( void )
 : m_sounds_time(0.f),
   m_sounds_threshold( 3.f ),
   m_buffers_time(0.f),
   m_buffers_threshold( 1000000.f )
{ }

void SoundSys::aliasDef( const std::string& name, const std::string& alias)
{
   SoundDef_ptr def = getDef(name);
   addDef(alias,def);
}

void SoundSys::removeDef( const std::string& name )
{
   m_definitions.erase(name);
}

bool SoundSys::isSound( std::string const& name ) const
{
   SoundDefs::const_iterator found = m_definitions.find(name);

   return found != m_definitions.end();
}

Sound SoundSys::getSound( std::string const& name )
{
   SoundDef_ptr def = getDef( name );

   std::size_t num_buffers = def->numFiles();
   SoundPimpl sound = def->load();

   for( std::size_t i=0; i<num_buffers; ++i )
   {
      const std::string& filename = def->filename(i);
      SoundBuffer_ptr buffer = loadBuffer(filename);
      sound->storeBuffer(i,buffer);
   }

   m_sounds.push_back( sound );

   return Sound( sound );
}


void SoundSys::collect( void )
{
   collectSounds();
   collectBuffers();
}

void SoundSys::update( float dt )
{
   updateSounds( dt );

   m_sounds_time += dt;
   if( m_sounds_time > m_sounds_threshold )
   {
      collectSounds();
      m_sounds_time -= m_sounds_threshold;
   }

   m_buffers_time += dt;
   if( m_buffers_time > m_buffers_threshold )
   {
      collectBuffers();
      m_buffers_time -= m_buffers_threshold;
   }
}

void SoundSys::addDef( const std::string& name, SoundDef_ptr def )
{
   bool success = m_definitions.insert( std::make_pair(name,def) ).second;

   if( ! success )
   {
      throw Error( Errors::e_Overwrite_Definition );
   }
}

SoundDef_ptr SoundSys::getDef( const std::string& name ) const
{
   SoundDefs::const_iterator found = m_definitions.find(name);

   if( found == m_definitions.end() )
   {
      throw Error( Errors::e_Missing_Definition, name );
   }

   return found->second;
}

namespace // anonymous
{
   struct CallUpdate
   {
      CallUpdate( float dt ) : m_dt(dt) { }
   
      void operator()( SoundPimpl& pimpl )
      {
         pimpl->update(m_dt);
      }
   
   private:
      float m_dt;
   };
} // anonymous namespace

void SoundSys::updateSounds( float dt )
{
   std::for_each( m_sounds.begin(), m_sounds.end(), CallUpdate(dt) );
}

void SoundSys::collectSounds( void )
{
   SoundPimpls::iterator iter = m_sounds.begin();
   SoundPimpls::iterator end = m_sounds.end();

   while( iter != end )
   {   
      if( iter->unique() && (*iter)->done() )
      {
         iter = m_sounds.erase(iter);
      }
      else
      {
         ++iter;
      }
   }
}

void SoundSys::collectBuffers( void )
{
   Buffers::iterator iter = m_buffers.begin();
   Buffers::iterator end = m_buffers.end();

   while( iter != end )
   {
      if( iter->second.unique() )
      {
         m_buffers.erase(iter++);
      }
      else
      {
         ++iter;
      }
   }
}

SoundBuffer_ptr SoundSys::loadBuffer( const std::string& filename )
{
   Buffers::iterator found = m_buffers.find(filename);
   if( found == m_buffers.end() )
   {
      SoundBuffer_ptr buffer( new sf::SoundBuffer );
      const bool success = buffer->LoadFromFile( filename );
      if( !success )
      {
         throw Error( Errors::e_File_Load_Error, filename );
      }

      found = m_buffers.insert( std::make_pair(filename,buffer) ).first;
   }

   return found->second;
}

} // namespace ammo
