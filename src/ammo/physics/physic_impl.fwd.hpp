#ifndef AMMO_PHYSICS_PHYSICS_IMPL_FWD_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSICS_IMPL_FWD_HPP_INCLUDED

#include <boost/intrusive_ptr.hpp>

namespace ammo
{
	class PhysicImpl;
	void intrusive_ptr_add_ref( PhysicImpl* ptr );
	void intrusive_ptr_release( PhysicImpl* ptr );
	typedef boost::intrusive_ptr<PhysicImpl> PhysicPimpl;
}

#endif // AMMO_PHYSICS_PHYSICS_IMPL_FWD_HPP_INCLUDED
