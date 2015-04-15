#ifndef MGMTDATATYPES_H
#define MGMTDATATYPES_H

/************************************************
MANAGEMENT DATATYPES
************************************************/

class OcaManagerDescriptor
{
    OcaONo ObjectNumber;
    OcaString Name;
    OcaClassID ClassID;
    OcaClassVersionNumber ClassVersion;

public:
    OcaManagerDescriptor(){};
    virtual ~OcaManagerDescriptor(){};
};

enum class OcaManagerDefaultObjectNumbers : OcaONo
{
    DeviceManager = 1,
    SecurityManager,
    FirmwareManager,
    SubscriptionManager,
    PowerManager,
    NetworkManager,
    MediaClockManager,
    LibraryManager,
    AudioProcessingManager,
    DeviceTimeManager
};

enum class OcaDeviceState : OcaEnumItem
{
    Operational =   0x0001,
    Disabled =      0x0002,
    Error =         0x0004,
    Initializing =  0x0008,
    Updating =      0x0010
};

class OcaModelGUID
{
    OcaBlobFixedLen Reserved;
    OcaBlobFixedLen MtrCode;
    OcaBlobFixedLen ModelCode;

public:
    OcaModelGUID(){};
    virtual ~OcaModelGUID();
};

class OcaModelDescription
{
    OcaString Manufacturer;
    OcaString Name;
    OcaString Version;

public:
    OcaModelDescription(){};
    virtual ~OcaModelDescription(){};
};

enum class OcaPowerState : OcaEnumItem
{
    None = 0,
    Working,
    Standby,
    Off
};

enum class OcaPowerSupplyType : OcaEnumItem
{
    None = 0,
    Mains,
    Battery,
    Phnatom,
    Solar
};

enum class OcaPowerSupplyState : OcaEnumItem
{
    Off = 1,
    Unavailable,
    Available,
    Active
};

enum class OcaResetCause : OcaEnumItem
{
    PowerOn = 0,
    InternalError,
    Upgrade,
    ExternalRequest
};

/* OcaComponent defined in frameworktypes.h, because the code won't build
    if we define it here, as it's referred to by a forward definition in
    frameworktypes.h */

#endif // MGMTDATATYPES_H
