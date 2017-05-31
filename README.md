# C++ Interface Versioning

https://accu.org/index.php/journals/1718

# Components

* Shared library
* Multiple clients (we have only one)

# Goal

While the library adds new features to its interface, the clients do not have to recompile. Here, adding features to the interface means adding new methods to a type that is already used by the clients. 

# Extending interfaces

The basic premise of this solution is that instead of adding methods to an interface which is part of a deployed library, the new methods are added to a new interface.

The key to this working is that the new interface inherits publicly from the existing one.

# Versioning Guide

We follow the changes of the inventory library until it's interface can be extended without forcing the client application to recompile.

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