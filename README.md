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

## Inventory 1.0.0

## Inventory 2.0.0

Changes:
* 
* 

Reasons:
* 
* 

Compatibility to last version:
* __Inventory breaks API__
* __Application must change code and recompile__
