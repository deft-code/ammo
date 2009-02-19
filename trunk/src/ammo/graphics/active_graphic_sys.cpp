#include "active_graphic_sys.hpp"

#include "../error.hpp"
#include "graphic_def.hpp"
#include "graphic.hpp"
#include "graphic_impl.hpp"

#include "ammo/util/profiler.hpp"

#include <SFML/Graphics/Image.hpp>
#include <limits>

namespace ammo
{

ActiveGraphicSys::ActiveGraphicSys( void )
 : m_needs_resort(false)
{ }

void ActiveGraphicSys::RemoveSchema( const std::string& name )
{
   m_definitions.erase(name);
}

bool ActiveGraphicSys::IsGraphic( std::string const& name ) const
{
   GraphicDefs::const_iterator found = m_definitions.find(name);

   return found != m_definitions.end();
}

Graphic ActiveGraphicSys::NewGraphic( std::string const& name )
{
   GraphicSchema_ptr def = getDef( name );

   std::size_t num_images = def->numFiles();
   GraphicPimpl sound = def->load();

   for( std::size_t i=0; i<num_images; ++i )
   {
      const std::string& filename = def->filename(i);
      Image_ptr buffer = loadImage(filename);
      sound->storeImage(i,buffer);
   }

   m_graphics.push_back( sound );

   return Graphic( sound );
}

namespace // anonymous
{
   struct CallUpdate
   {
      CallUpdate( float dt, bool& needs_resort )
       : m_dt(dt),
         m_last_z( -std::numeric_limits<float>::infinity() ),
         m_needs_resort(needs_resort)
       { }
   
      void operator()( GraphicPimpl& pimpl )
      {
         pimpl->update(m_dt);
         if( !m_needs_resort )
         {
            const float z = pimpl->GetZOrder();
            m_needs_resort = z < m_last_z;
            m_last_z = z;
         }
      }
   
   private:
      const float m_dt;
      float m_last_z;
      bool& m_needs_resort;
   };
} // anonymous namespace

void ActiveGraphicSys::Update( float dt )
{
   std::for_each( m_graphics.begin(), m_graphics.end(), CallUpdate(dt, m_needs_resort) );
}

void ActiveGraphicSys::NewSchema( const std::string& name, GraphicSchema_ptr schema )
{
   bool success = m_definitions.insert( std::make_pair(name,schema) ).second;

   if( ! success )
   {
      throw Error( Errors::e_Overwrite_Definition );
   }
}

GraphicSchema_ptr ActiveGraphicSys::getDef( const std::string& name ) const
{
   GraphicDefs::const_iterator found = m_definitions.find(name);

   if( found == m_definitions.end() )
   {
      throw Error( Errors::e_Missing_Definition, name );
   }

   return found->second;
}

namespace // anonymous
{
   struct CallDraw
   {
      CallDraw( sf::RenderWindow& render) : m_render(render) { }
   
      void operator()( GraphicPimpl& pimpl )
      {
         pimpl->draw(m_render);
      }
   
   private:
      sf::RenderWindow& m_render;
   };

   struct ZSort
   {
      bool operator()( const GraphicPimpl& lhs, const GraphicPimpl& rhs ) const
      {
         return lhs->GetZOrder() < rhs->GetZOrder();
      }
   };
} // anonymous namespace

void ActiveGraphicSys::Draw( sf::RenderWindow& app )
{
	PROFILE_TIMER(active_graphics_draw)
	if( m_needs_resort )
	{
		PROFILE_TIMER(active_graphics_resort)
		m_graphics.sort( ZSort() );
	}
	std::for_each( m_graphics.begin(), m_graphics.end(), CallDraw(app) );
}

void ActiveGraphicSys::CollectGraphics( void )
{
   GraphicPimpls::iterator iter = m_graphics.begin();
   GraphicPimpls::iterator end = m_graphics.end();

   while( iter != end )
   {   
      if( iter->unique() && (*iter)->done() )
      {
         iter = m_graphics.erase(iter);
      }
      else
      {
         ++iter;
      }
   }
}

void ActiveGraphicSys::CollectVideoMem( void )
{
   Images::iterator iter = m_images.begin();
   Images::iterator end = m_images.end();

   while( iter != end )
   {
      if( iter->second.unique() )
      {
         m_images.erase(iter++);
      }
      else
      {
         ++iter;
      }
   }
}

Image_ptr ActiveGraphicSys::loadImage( const std::string& filename )
{
   Images::iterator found = m_images.find(filename);
   if( found == m_images.end() )
   {
      Image_ptr buffer( new sf::Image );
      const bool success = buffer->LoadFromFile( filename );
      if( !success )
      {
         throw Error( Errors::e_File_Load_Error, filename );
      }

      found = m_images.insert( std::make_pair(filename,buffer) ).first;
   }

   return found->second;
}

} // namespace ammo
