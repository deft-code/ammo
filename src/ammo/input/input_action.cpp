#include "ammo/input/input_action.hpp"

#include "ammo/input/input_impl.hpp"

namespace ammo
{
    InputAction::InputAction(InputImpl_ptr impl)
    {
        _impl = impl;
    }
}