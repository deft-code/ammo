#include "ammo/input/input_impl.hpp"

#include "ammo/input/input_action.hpp"

namespace ammo
{
    InputImpl::InputImpl()
    {   
    }

    InputImpl::InputImpl(std::vector<InputAction*> actions)
    {
        _state.resize(PLAYER_ACTIONS_COUNT);
        _actions = actions;
        for (std::vector<InputAction*>::iterator it = _actions.begin(); it != _actions.end(); ++it)
        {
            if (*it != NULL)
                (*it)->RegisterImpl(this);
        }
    }

    void InputImpl::Update(const sf::Input& input, float dt)
    {
        for (std::vector<InputAction*>::iterator it = _actions.begin(); it != _actions.end(); ++it)
        {
            if (*it != NULL)
                (*it)->Update(input, dt);
        }
    }

    float InputImpl::GetValue(ammo::enums::enumPlayerAction action) const
    {
        if (_state.size() < action)
        {
            _state.resize(action+1, 0.f);
        }
        return _state[action];
    }

    void InputImpl::SetValue(enums::enumPlayerAction action, float val)
    {
        if (_state.size() < action)
        {
            _state.resize(action+1, 0.f);
        }
        _state[action] = val;
    }
}