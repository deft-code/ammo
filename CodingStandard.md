# Introduction #
This standard is by no means set in stone.  It will continue to morph as our coding styles blend of the next month.  After that we'll lock it down.

## Directory Structure ##
The directory structure will mirror SFML's.
  * trunk
    * docs
    * src
      * ammo
        * graphics
        * network
        * audio
        * physics
        * lua
    * build
      * VS2008
      * slickedit
      * others (codeblocks, xcode, whatever you use)
### file naming ###
header files are _name_.hpp

source files are _name_.cpp

Do we want capitals in our names?  Why not so the files set for the class `FooBar` could be _FooBar.hpp_ and _FooBar.cpp_.
### file inclusion ###
cpp file (source.cpp) can include a header files two ways
  * `#include "ammo/header.h"`
  * `#include "header.h"` if source.cpp is in the same directory as header.h
h files can only use the first method


## Example Class ##
look at RakNet for a good example of how to do doxygen comments right.
```

int g_a_global;

static s_a_static;

/// doxygen comment for class
class ClassName
{
public:
   /// silly description, not really needed here
   ClassName( void );

   /// more silly stuff
   ~ClassName( void );

   /// what does this do?
   void MethodOne( void );
   
   /// what does this do?
   /// @param foo what does this parameter do
   /// @returns the results of MethodTwo
   int MethodTwo( int foo );

private:
   /// what this member is for
   int m_privateMembers;

   /// what this member is for
   int m_private_members_alt;
};

ClassName::ClassName( void )
 : _privateMembers(10),
   _private_members_alt(42)
{ }

```

technically prefixing a variable with `_` is reserved for library vendors.  Prefixes with `__` are reserved for compiler vendors.  Because of this prefixing member variables with m