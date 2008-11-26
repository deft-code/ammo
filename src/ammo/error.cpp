#include "error.hpp"

namespace ammo
{
   using namespace Errors;

   Error::Error( Enum error )
    : std::runtime_error( "" ),
      m_error(error)
   { }

   Error::Error( Enum error, const std::string& err_str )
    : std::runtime_error( err_str ),
      m_error(error)
   { }

}
