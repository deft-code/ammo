#include "ammo/input/input_impl.hpp"

#include "ammo/input/input_action.hpp"

namespace ammo
{
    InputImpl::InputImpl():_active(false)
    {
        _state.resize(PLAYER_ACTIONS_COUNT*2);
    }

    InputImpl::InputImpl(std::vector<InputAction*> actions):_active(false)
    {
        _state.resize(PLAYER_ACTIONS_COUNT*2);
        _actions = actions;
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
        /*if (_state.size() < action)
        {
            _state.resize(action+1, 0.f);
        }*/
        return _state[action];
    }

    void InputImpl::SetValue(enums::enumPlayerAction action, float val)
    {
        /*if (_state.size() < action)
        {
            _state.resize(action+1, 0.f);
        }*/
        _state[action] = val;
    }

    void InputImpl::Activate()
    {
        if (!_active)
        {
            _active = true;    
            for (std::vector<InputAction*>::iterator it = _actions.begin(); it != _actions.end(); ++it)
            {
                if (*it != NULL)
                    (*it)->RegisterImpl(this);
            }
        }
    }

    bool InputImpl::IsActive()
    {
        return _active;
    }
}