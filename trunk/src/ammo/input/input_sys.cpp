#include "ammo/input/input_sys.hpp"

#include "ammo/input/input_impl.hpp"
#include "ammo/input/input_action.hpp"
#include "ammo/input/input.hpp"

namespace ammo
{
    Input_ptr InputSys::AddInputMap(std::vector<InputAction_ptr> inputMap)
    {
        InputImpl_ptr impl(new InputImpl(inputMap));
        _inputs.push_back(impl);
        Input_ptr input(new Input(impl));
        return input;
    }
}