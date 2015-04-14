#ifndef FRAMEWORKTYPES_H
#define FRAMEWORKTYPES_H

#include "stdint.h"
//#include <mgmttypes.h>

/************************************************
FRAMEWORK DATATYPES
************************************************/
class OcaVersion
{
    OcaUint32 Major, Minor, Build;
    OcaComponent Component;

public:
    OcaVersion(){};
    virtual ~OcaVersion(){};
};

class OcaClassIDField
{
    OcaBitstring Proprietary;
    OcaBitstring Index;

public:
    OcaClassIDField(){};
    virtual ~OcaClassIDField(){};
};

class OcaClassID
{
    OcaUint16 FieldCount;
    OcaClassIDField Fields[];

public:
    OcaClassID(){};
    virtual ~OcaClassID(){};
};

typedef OcaUint16 OcaClassVersionNumber;

class OcaClassIdentification
{
    OcaClassID ClassID;
    OcaClassVersionNumber ClassVersion;

public:
    OcaClassIdentification(){};
    virtual ~OcaClassIdentification(){};
};

typedef OcaUint32 OcaONo;

class OcaObjectIdentification
{
    OcaONo ONo;
    OcaClassIdentification ClassIdentification;

public:
    OcaObjectIdentification(){};
    virtual ~OcaObjectIdentification(){};
};

class OcaMethodID
{
    OcaUint16 DefLevel, MethodIndex;

public:
    OcaMethodID(){};
    virtual ~OcaMethodID(){};
};

class OcaPropertyID
{
    OcaUint16 DefLevel, PropertyIndex;

public:
    OcaPropertyID(){};
    virtual ~OcaPropertyID(){};
};

class OcaEventID
{
    OcaUint16 DefLevel, EventIndex;

public:
    OcaEventID(){};
    virtual ~OcaEventID(){};
};

class OcaPropertyDescriptor
{
    OcaPropertyID PropertyID;
    OcaBaseDataType BaseDataType;

public:
    OcaPropertyDescriptor(){};
    virtual ~OcaPropertyDescriptor(){};
};

class OcaProperty
{
    OcaONo ONo;
    OcaPropertyDescriptor Descriptor;

public:
    OcaProperty(){};
    virtual ~OcaProperty(){};
};

enum class OcaStatus : OcaEnumItem
{
    OK = 0,
    ProtocolVersionError,
    DeviceError,
    Locked,
    BadFormat,
    BadONo,
    ParameterError,
    ParameterOutOfRange,
    NotImplemented,
    InvalidRequest,
    ProcessingFailed,
    BadMethod,
    PartiallySucceeded,
    Timeout,
    BufferOverflow
};

#endif // FRAMEWORKTYPES_H
