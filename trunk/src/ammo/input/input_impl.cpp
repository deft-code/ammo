#include "ammo/input/input_impl.hpp"

#include "ammo/input/input_action.hpp"

namespace ammo
{
    InputImpl::InputImpl()
    {   
    }

    InputImpl::InputImpl(std::vector<InputAction*> actions)
    {
        _actions = actions;
    }

    void InputImpl::Update(sf::Input& input)
    {
        for (std::vector<InputAction*>::iterator it = _actions.begin(); it != _actions.end(); ++it)
        {
            (*it)->Update(input);
        }
    }

    float InputImpl::GetValue(ammo::enums::enumPlayerAction action) const
    {
        return _state[action];
    }

    void InputImpl::SetValue(enums::enumPlayerAction action, float val)
    {
        _state[action] = val;
    }
}