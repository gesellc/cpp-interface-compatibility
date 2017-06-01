# C++ Interface Versioning

An executable version of [this article](https://accu.org/index.php/journals/1718) and [this talk](https://www.slideshare.net/skillsmatter/cpp-ver-talk).

## Situation

* A shared library called `inventory`
* A client application using this library

## Goal

While the library adds new features to its interface, the clients do not have to recompile. Here, adding features to the interface means adding new methods to a type that is already used by the clients. 

## Challenge

It's still not portable however. The code for realpart_v2 is still dependent upon the implementation specific behaviour of the compiler in laying out the vtable this way. A new version of the same compiler might choose to group the functions in a different way, again resulting in undefined behaviour unless client code recompiles.

## Extending interfaces

The basic premise of this solution is that instead of adding methods to an interface which is part of a deployed library, the new methods are added to a new interface.

The key to this working is that the new interface inherits publicly from the existing one.

# Developing the downward compatible interfac

We follow the changes of the inventory library until it's interface can be safely extended without forcing the client application to recompile.

The quoted text in the following section titles refer to sections of the [source article](https://accu.org/index.php/journals/1718).

## Inventory 1.0.0 - "The Goal"

    class part
        int id()

## Inventory 2.0.0 - "Untying the knot"

    class part
        virtual int id()

    part * create_part()
 
Changes:
* Hide private data in subclass `realpart` which is private to the library `inventory`
* Make pure virtual `part` the public-facing interface of the library
* Add factory function to create new instances

Design Impact:
* The `part` interface hides all the implementation details from clients, such as data members and private or protected member functions.
* `realpart` can change in any way, as long as it correctly implements the `part` interface, without requiring any recompilation on the part of clients.

Compatibility Impact:
* The inventory library breaks its API
* The client application must change code and recompile


## Inventory 3.0.0 - "False hope"

    class part
        virtual int id()
        virtual string name()

    part * create_part()

Changes:
* A new method has been added to the public interface of our library.

Compatibility Impact:
* Even though the client code doesn't use the new method, it must recompile against the new interface definition, and still needs to re-deploy at the same time as the new library is deployed.


## Inventory 4.0.0 - "Extending Interfaces (The True Path)"

    class part  
        virtual int id()
        virtual string name()

    class part_v2 : public part  
        virtual void id(int)  
        virtual void name(string)  

Changes:
* Extend interface with setter methods
* Do so in a second abstract interface class inheriting from the initial one