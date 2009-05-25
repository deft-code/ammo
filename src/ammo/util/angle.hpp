#ifndef ANGLE_HPP_INCLUDED
#define ANGLE_HPP_INCLUDED

namespace ammo
{
	/// Eventually Angle could be a class that can mimic either a Radians
	///  or Degrees at runtime.
	class Angle
	{
	public:
		enum Units
		{
			degrees,
			radians
		};

		/// a constant value for \f$\pi\f$
		static const float pi = 3.14159265f;
	};

	class Radians;

	/// represents an angle measured in degrees
	/// more operators will be added as needed (YAGNI)
	class Degrees
	{
	public:
		/// don't allow implicit casting with this constructor
		explicit Degrees( float angle ) :
			m_angle(angle)
		{ }

		/// Allow implicit casting from Radians
		inline Degrees( const Radians& angle );

		/// @returns angle measured in degrees
		float asDegrees( void ) const
		{ return m_angle;	}

		/// @returns angle measured in radians
		float asRadians( void ) const
		{ return m_angle * Angle::pi / 180.f; }

		/// normalize Degree angle to the range \f$[0,360)\f$
		/// @return reference to self, for call chaining
   	Degrees& normalize( void );

	private:
		/// angle measured in degrees
		float m_angle;
	};

	/// represents an angle measured in radians
	/// more operators will be added as needed (YAGNI)
	class Radians
	{
	public:
		/// don't allow implicit casting from float number
		explicit Radians( float angle ) :
			m_angle(angle)
		{ }

		/// allow implicit casting from Degrees
		Radians( const Degrees& angle ) :
			m_angle(angle.asRadians())
		{ }

		/// @returns angle measured in degrees
		inline float asDegrees( void ) const
		{ return  m_angle * 180.f / Angle::pi; }

		/// @returns angle measured in radians
		inline float asRadians( void ) const
		{ return m_angle;	}

		/// normalize Radian angle to the range \f$(-\pi,\pi]\f$
		/// @return reference to self, for call chaining
		Radians& normalize( void );

	private:
		/// angle measured in radians
		float m_angle;
	};

	inline Degrees::Degrees( const Radians& rads ) :
		m_angle( rads.asDegrees() )
	{ }

	// add new operators here
	
}
#endif
