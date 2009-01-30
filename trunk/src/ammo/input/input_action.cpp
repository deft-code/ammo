#include "ammo/input/input_action.hpp"

#include "ammo/input/input_impl.hpp"

namespace ammo
{
    void InputAction::RegisterImpl(InputImpl* impl)
    {
        _impl = impl;
    }
}