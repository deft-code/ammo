

# Introduction #

## Smart Handles ##
Smart pointers are used throughout the engine.  However the implementation
classes only provide a minimal set of methods, to keep the implementation
interfaces small.  To make developers lives easier most smart pointers are
wrapped in smart handles.  They
are essentially lite objects using the pimpl pattern.  Most methods call through
to the underlying pimpl object, but a few perform processing and/or call multiple interface methods.

In the future it would nice to provide property like accessors to the smart handle classes.
C++ doesn't have very good native support for properties.  They can be faked with
Objects that have their operators overloaded to look like the represented type.

## Dynamic Factory ##

The ammo engine makes use of a dynamic factory pattern.
### Code Overview ###
```
class Fruit_impl
{
  // pure virtual methods defining interface
};

class Fruit_schema
{
public:
   virtual Fruit_impl* instantiate( void ) const =0;
};

class Apple : public Fruit_impl
{
public:
  Apple( const Apple_schema& schema ) :
    m_size(schema.size)
  { }

  // Apple specific implementation

private:
  int m_size;
};

class Apple_schema : public Fruit_schema
{
public:
  int size;

  virtual Fruit_impl* instantiate( void )
  { return new Apple(*this); }
};

class Fruit_system
{
public:
	void addSchema( const std::string& name, const Fruit_schema& schema );

	Fruit_impl* newFruit( const std::string& name );
};

```
### Benefits ###
This design allows maximum flexibility.
#### Named Preset Instantiations ####
The key feature is that Apple\_schema can be added multiple times with different sizes.  e.g
  * "small" -> size 1
  * "medium" -> size 2
  * "large" -> size 4

In the code when a medium sized apple is required, `fruit_sys.newFruit("medium")` is used.  Medium sized fruit can be defined at runtime.  It could later be replaced with a tiny grape fruit class.

#### Object Lifetime Management ####
The lifetime of fruit objects is encapsulated in the System and smart handle.
The handles tell the system when there are no more user references to the
object.  The system can then at its leisure clean up the memory for the no longer
referenced objects.  Like a crazy blending of reference counting and a garbage collector.

Each impl, chooses when it ready to be collected (after all user references are lost).
This allows for objects to exist as long as they are needed (possible indefinitely).
The key problem this solves is when creates a sound objects, plays it, then
immediately lets it leave scope.  Internally the impl doesn't let the system
collect it until it finished playing.

#### Dynamically load new schemas ####
Another, not really needed, feature is that, the various kinds of fruit are not defined until runtime.  A new fruits could be added via dynamic loading.  In practice this is less useful, as dynamic behavior will generally be done via Lua.  e.g.class Lua_fruit : public Fruit_impl
{
   // code to forward Fruit_impl calls to a lua object
};
```