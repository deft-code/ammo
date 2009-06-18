#include "angle.hpp"

namespace ammo
{
	const float Angle::pi = 3.14159265f;
	
	Degrees& Degrees::normalize( void )
	{
		while( m_angle >= 360.f )
			m_angle -= 360.f;
	
		while( m_angle < 0.f )
			m_angle += 360.f;
	
		return *this;
	}
	
	Radians& Radians::normalize( void )
	{
		while( m_angle > Angle::pi )
			m_angle -= 2*Angle::pi;
	
		while( m_angle <= -Angle::pi )
			m_angle += 2*Angle::pi;
	
		return *this;
	}
}
