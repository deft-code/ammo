#include "ammo/input/input_sys.hpp"

#include "ammo/input/input_impl.hpp"
#include "ammo/input/input_action.hpp"
#include "ammo/input/input.hpp"

namespace ammo
{
    void InputSys::AddInputMap(std::string name, std::vector<InputAction*> inputMap)
    {
        InputImpl impl(inputMap);
        _impls.insert(std::make_pair(name, impl));
    }

    Input InputSys::GetInput(std::string name)
    {
        Input input(&(_impls.find(name)->second));
        return input;
    }

    void InputSys::Update(const sf::Input& input, float dt)
    {
        for (std::map<std::string, InputImpl>::iterator it = _impls.begin(); it != _impls.end(); ++it)
        {
            it->second.Update(input, dt);
        }
    }
}