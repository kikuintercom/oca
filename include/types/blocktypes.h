#ifndef BLOCKTYPES_H
#define BLOCKTYPES_H

/************************************************
BLOCK AND MATRIX DATATYPES
************************************************/

class OcaBlockMember
{
    OcaObjectIdentification MemberObjectIdentification;
    OcaONo ContainerObjectNumber;

public:
    OcaBlockMember(){};
    virtual ~OcaBlockMember(){};
};

enum class OcaPortMode : OcaEnumItem
{
    Input = 1,
    Output
};

class OcaPortID
{
    OcaPortMode Mode;
    OcaUint16 Index;

public:
    OcaPortID(){};
    virtual ~OcaPortID(){};
};

class OcaPort
{
    OcaONo Owner;
    OcaPortID ID;
    OcaString Name;

public:
    OcaPort(){};
    virtual ~OcaPort(){};
};

class OcaSignalPath
{
    OcaPort SourcePort, SinkPort;

public:
    OcaSignalPath(){};
    virtual ~OcaSignalPath(){};
};

typedef OcaUint32 OcaProtoONo;

class OcaProtoMember
{
    OcaProtoONo ProtoMemberPONo;

public:
    OcaProtoMember(){};
    virtual ~OcaProtoMember(){};
};

class OcaProtoObjectIdentification
{
    OcaProtoONo POno;
    OcaClassIdentification ClassIdentification;

public:
    OcaProtoObjectIdentification(){};
    virtual ~OcaProtoObjectIdentification(){};
};

class OcaProtoPortID
{
    OcaPortMode Mode;
    OcaUint16 Index;

public:
    OcaProtoPortID(){};
    virtual ~OcaProtoPortID(){};
};

class OcaProtoPort
{
    OcaProtoONo Owner;
    OcaProtoPortID ProtoID;
    OcaString Name;

public:
    OcaProtoPort(){};
    virtual ~OcaProtoPort(){};
};

class OcaProtoSignalPath
{
    OcaProtoPort SourceProtoPort, SinkProtoPort;

public:
    OcaProtoSignalPath(){};
    virtual ~OcaProtoSignalPath();
};

typedef OcaUint16 OcaMatrixCoordinate;

#endif // BLOCKTYPES_H
