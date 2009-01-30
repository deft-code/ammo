#ifndef AMMO_INPUT_INPUT_HPP
#define AMMO_INPUT_INPUT_HPP

#include <boost/shared_ptr.hpp>
#include "ammo/enums/playeractions.hpp"

namespace ammo
{
    class InputImpl;
    typedef boost::shared_ptr<InputImpl> InputImpl_ptr;

    class Input
    {
    public:
        Input(InputImpl_ptr impl);
        float GetValue(enums::enumPlayerAction action) const;
        bool GetBoolValue(enums::enumPlayerAction action) const;
        void SetValue(enums::enumPlayerAction action, float val);

    private:
        InputImpl_ptr _impl;
    };
    typedef boost::shared_ptr<Input> Input_ptr;
}

#endif // AMMO_INPUT_INPUT_H