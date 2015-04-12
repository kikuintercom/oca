#include "OcaRoot.h"

/*
Tree Level: 01
Package: Control Classes
Stereotype: <<abstract>>
Parent: (none)

The abstract root class of which all OCA classes derive. It offers basic OCA functionality such as locking
an object and generalized data access.
*/

OcaRoot::OcaRoot()
{
    OcaClassID              ClassID = 1;
    OcaClassVersionNumber   ClassVersion    = 1;
    OcaONo                  ObjectNumber;
    OcaBoolean              Lockable;
    OcaString               Role;
}

OcaRoot::~OcaRoot()
{
    //dtor
}
