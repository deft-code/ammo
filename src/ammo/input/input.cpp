#include "ammo/input/input.hpp"

#include "ammo/input/input_impl.hpp"

namespace ammo
{
    Input::Input(InputImpl* impl)
    {
        _impl = impl;
    }

    float Input::GetValue(ammo::enums::enumPlayerAction action) const
    {
        return _impl->GetValue(action);
    }

    bool Input::GetBoolValue(ammo::enums::enumPlayerAction action) const
    {
        float val = _impl->GetValue(action);

        if (val > 0.f)
            return true;
        else
            return false;
    }

    void Input::SetValue(ammo::enums::enumPlayerAction action, float val)
    {
        _impl->SetValue(action, val);
    }
}