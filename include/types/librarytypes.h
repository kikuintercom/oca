#ifndef LIBRARYTYPES_H
#define LIBRARYTYPES_H

/************************************************
LIBRARY DATATYPES
************************************************/

enum class OcaLibVolType : OcaEnumItem
{
    None = 0,
    ParamSet,
    Patch
};

typedef OcaUint32 OcaLibVolID;

class OcaLibVolIdentifier
{
    OcaONo Library;
    OcaLibVolID ID;

public:
    OcaLibVolIdentifier(){};
    virtual ~OcaLibVolIdentifier(){};
};

enum class OcaLibAccess : OcaEnumItem
{
    None = 0,
    ReadOnly,
    ReadExpand,
    Full
};

class OcaLibVolMetadata
{
    OcaString Name;
    OcaLibVolType Type;
    OcaLibAccess Access;
    OcaUint32 Version;
    OcaString Creator;
    OcaTimeOfDay UpDate;

public:
    OcaLibVolMetadata(){};
    virtual ~OcaLibVolMetadata(){};
};

template <class T> class OcaLibVol
{
    OcaLibVolMetadata Metadata;
    T Data;

public:
    OcaLibVol(){};
    virtual ~OcaLibVol(){};
};

class OcaLibParamSetAssignment
{
    OcaLibVolIdentifier ParamSetIdentifier;
    OcaONo TargetBlockNo;

public:
    OcaLibParamSetAssignment(){};
    virtual ~OcaLibParamSetAssignment(){};
};

class OcaLibVolData_ParamSet
{
    OcaONo TargetBlockType;
    OcaBlob ParData;

public:
    OcaLibVolData_ParamSet(){};
    virtual ~OcaLibVolData_ParamSet(){};
};

class OcaLibVolData_Patch
{
    OcaList<OcaLibParamSetAssignment> Assignments;

public:
    OcaLibVolData_Patch(){};
    virtual ~OcaLibVolData_Patch(){};
};

#endif // LIBRARYTYPES_H
