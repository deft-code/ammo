#include "graphic.hpp"

#include "graphic_impl.hpp"

namespace // anonymous
{
   /// implements the Null Object Design Pattern for Graphic objects
   class NullGraphicImpl : public ammo::GraphicImpl
   {
   public:
      virtual void update( float dt ) { }
      virtual bool done( void ) const { return true; }
      virtual void draw( sf::RenderWindow& render ) { }
      virtual void storeImage( std::size_t index, ammo::Image_ptr image ) { }
      virtual void show( void ) { }
      virtual void hide( void ) { }
      virtual float GetRotationDegrees(void) const {return 0;}
      virtual void  SetRotationDegrees(const float rot) { }
      virtual void SetRotationRadians(const float rot) { }
      virtual sf::Blend::Mode GetRenderMode( void ) const {return (sf::Blend::Mode)0;}
      virtual void SetRenderMode( const sf::Blend::Mode mode ) { };
      virtual b2Vec2 GetPosition( void ) const { return b2Vec2_zero; }
      virtual void SetPosition( const b2Vec2& pos ) { }
      virtual b2Vec2 GetSize( void ) const { return b2Vec2_zero; }
		virtual void SetSize( const b2Vec2& size ) {	}
		virtual float GetZOrder( void ) const { return 0.f; }
		virtual void SetZOrder( float z ) {	}
		virtual bool Meta_N( int meta, double& n ) { return false; }
		virtual bool Meta_VP( int meta, b2Vec2& v, void* p ) { return false; }
   };

   void do_nothing( ammo::GraphicImpl* unused ) { }

   NullGraphicImpl s_null_graphic;
   ammo::GraphicPimpl s_null_pimpl( &s_null_graphic, do_nothing );
} // anonymous namespace

namespace ammo
{
   Graphic::Graphic( void )
    : m_pimpl(s_null_pimpl)
   { }
   
   Graphic::Graphic( GraphicPimpl pimpl )
    : m_pimpl(pimpl)
   { }
   
   void Graphic::show( void )
   {
      m_pimpl->show();
   }
   
   void Graphic::hide( void )
   {
      m_pimpl->hide();
   }

   float Graphic::GetRotationDegrees( void ) const
   {
     return m_pimpl->GetRotationDegrees();
   }

   void Graphic::SetRotationDegrees(const float rot)
   {
      m_pimpl->SetRotationDegrees(rot);
   }

   void Graphic::SetRotationRadians(const float rot)
   {
      m_pimpl->SetRotationRadians(rot);
   }

   b2Vec2 Graphic::GetPosition( void ) const
   {
      return m_pimpl->GetPosition();
   }

   void Graphic::SetPosition( const b2Vec2& pos )
   {
      m_pimpl->SetPosition( pos );
   }
   
   sf::Blend::Mode Graphic::GetRenderMode( void ) const
   {
     return m_pimpl->GetRenderMode();
   }

   void Graphic::SetRenderMode( const sf::Blend::Mode mode )
   {
     m_pimpl->SetRenderMode(mode);
   }

   void Graphic::SetX( float x )
   {
      m_pimpl->SetPosition( b2Vec2(x, m_pimpl->GetPosition().y));
   }

   void Graphic::SetY( float y )
   {
      m_pimpl->SetPosition( b2Vec2(m_pimpl->GetPosition().x, y));
   }

   void Graphic::Move( const b2Vec2& delta )
   {
      m_pimpl->SetPosition( m_pimpl->GetPosition() + delta );
   }

   b2Vec2 Graphic::GetSize( void ) const
   {
      return m_pimpl->GetSize();
   }

	void Graphic::SetSize( const b2Vec2& size )
	{
      m_pimpl->SetSize(size);
	}

	float Graphic::GetZOrder( void ) const
	{
		return m_pimpl->GetZOrder();
	}

	void Graphic::SetZOrder( float z )
	{
		m_pimpl->SetZOrder(z);
	}

	bool Graphic::Meta_N( unsigned meta, double n )
	{
		return m_pimpl->Meta_N(meta,n);
	}

	bool Graphic::Meta_VP( unsigned meta, b2Vec2 v, const void* p )
	{
		return m_pimpl->Meta_VP(meta,v,const_cast<void*>(p));
	}
}
