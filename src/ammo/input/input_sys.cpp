#include "ammo/input/input_sys.hpp"

#include "ammo/input/input_impl.hpp"
#include "ammo/input/input_action.hpp"
#include "ammo/input/input.hpp"

namespace ammo
{
    void InputSys::AddInputMap(SystemAddress owner, std::vector<InputAction*> inputMap)
    {
        InputImpl impl(inputMap);
        _impls.insert(std::make_pair(owner, impl));
    }

    Input InputSys::GetInput(SystemAddress owner)
    {
        InputImpl* impl = &(_impls.find(owner)->second);
        impl->Activate();
        Input input(impl);
        return input;
    }

    void InputSys::Update(const sf::Input& input, float dt)
    {
        for (std::map<SystemAddress, InputImpl>::iterator it = _impls.begin(); it != _impls.end(); ++it)
        {
            if (it->second.IsActive())
                it->second.Update(input, dt);
        }
    }
}