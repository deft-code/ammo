#ifndef ENTO_ERROR_HPP_INCLUDED
#define ENTO_ERROR_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace ento
{
   namespace Errors
   {
      enum Enum
      {
         e_Overwrite_Definition,
         e_Missing_Definition,
         e_File_Load_Error
      };
   }

   class Error : public std::runtime_error
   {
   public:
      Error( Errors::Enum error );

      Error( Errors::Enum error, const std::string& err_str );

      Errors::Enum get_error( void ) const
      { return m_error; }

   private:
      const Errors::Enum m_error;
   };
}

#endif // ENTO_ERROR_HPP_INCLUDED
