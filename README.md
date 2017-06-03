# Interface versioning in C++

This repo aims to provide an executable version of the article [Interface Versioning in C++](https://accu.org/index.php/journals/1718) by Steve Love, also covered in [this talk](https://skillsmatter.com/skillscasts/1599-interface-versioning-in-c-plus-plus) using [these slides](https://www.slideshare.net/skillsmatter/cpp-ver-talk).

* [ ] Implement all steps of the article as separate versions of a dynamic library and a consuming application
* [ ] Demonstrate described incompatibilities on `properties` classes
* [ ] Demonstrate described incompatibilities by combining and running different combinations of libraries and applications (maybe even compilers and compiler versions) in automated tests. Some should result in runtime errors.

## Situation

A shared library called `inventory` and a client `application` using this library.

## Goal

The goal is that our library can extend its interface, while the client does not have to recompile. Here, extending the interface means adding new methods to a type that is already used by the client.

## Challenge

At various points the article comes back to the problem that the layout of vtables depends upon the implementation of the compiler that is used. Also a new version of the same compiler might choose to group the functions in a different way, again resulting in undefined behaviour unless client code recompiles.

## Solution

The premise of the solution the article proposes is that instead of adding methods to an interface which is part of a deployed library, the new methods are added to a new interface.

The key to this working is that the new interface inherits publicly from the existing one.

# Steps towards a downward compatible interface

We follow the changes of the `inventory` library until its interface can be safely extended without forcing the client `application` to recompile.

The quoted text in the following titles refers to sections of the [source article](https://accu.org/index.php/journals/1718).

## Inventory 1.0.0 - "The Goal"

Inventory Interface and Implementation:

    class part
        int id()

## Inventory 2.0.0 - "Untying the knot"

Inventory Interface:

    part * create_part( return realpart )
 
    virtual class part
        virtual int id()

Inventory Implementation:

    class realpart : public part
        int id()


Changes:
* Hide private data in subclass `realpart` which is private to the library `inventory`
* Make pure virtual `part` the public-facing interface of the library
* Add factory function to create new instances

Design Evolution:
* The `part` interface hides all the implementation details from clients, such as data members and private or protected member functions.
* `realpart` can change in any way, as long as it correctly implements the `part` interface, without requiring any recompilation on the part of clients.

Compatibility Impact:
* The inventory library breaks its API
* The client application must change code and recompile


## Inventory 3.0.0 - "False hope"

Inventory Interface:

    part * create_part( return realpart )

    virtual class part
        virtual int id()
        virtual string name()

Inventory Implementation:

    class realpart : pulic part
        int id()
        string name()


Changes:
* A new method has been added to the public interface of our library.

Design Evolution:
* Not really, just another method.

Compatibility Impact:
* Even though the client code doesn't use the new method, it must recompile against the new interface definition, and still needs to re-deploy at the same time as the new library is deployed.


## Inventory 4.0.0 - "Extending interfaces and a wrong turn"

Inventory Interface:

    part * create_part( return realpart)
    
    virtual class part  
        virtual int id()
        virtual string name()

    virtual class part_v2 : public part  
        virtual void id(int)  
        virtual void name(string)  

Inventory Implementation:

    class realpart : public part_v2
        int id()
        string name()
        id(int)
        name(string)

Changes:
* Add setter methods to interface
* Do so by adding a second abstract interface class inheriting from the existing one.
* A single class implements the second abstract interface class

Design Evolution:
* The interface is formed by an inheritance structure of pure virtual classes.

Compatibility Impact:


## "Virtually done"

## "Ambiguity banishment"

## "Finishing polish"
