#ifndef NETWORKTYPES_H
#define NETWORKTYPES_H

/************************************************
NETWORK DATATYPES
************************************************/

/* OcaNetworkHostID defined in frameworktypes.h, because the code won't build
    if we define it here, as it's referred to by a forward definition in
    frameworktypes.h */

typedef OcaBlob OcaNetworkNodeID;

typedef OcaBlob OcaNetworkAddress;

class OcaNetworkSystemInterfaceID
{
    OcaBlob SystemInterfaceHandle;
    OcaNetworkAddress MyNetworkAddress;

public:
    OcaNetworkSystemInterfaceID(){};
    virtual ~OcaNetworkSystemInterfaceID(){};
};

typedef OcaBlob OcaStreamID;

typedef OcaUint16 OcaStreamIndex;

typedef OcaBlob OcaStreamParameters;

typedef OcaBlob OcaStreamConnectorID;

class OcaStreamConnectorIdentification
{
    OcaNetworkHostID HostID;
    OcaNetworkAddress NetworkAddress;
    OcaNetworkNodeID NodeID;
    OcaStreamConnectorID StreamConnectorID;

public:
    OcaStreamConnectorIdentification(){};
    virtual ~OcaStreamConnectorIdentification(){};
};

typedef OcaUint16 OcaStreamConnectorPinIndex;

typedef OcaBlob OcaNetworkSignalChannelID;

class OcaNetworkStatistics
{
    uint32_t txPacketErrors, rxPacketErrors;

public:
    OcaNetworkStatistics(){};
    virtual ~OcaNetworkStatistics(){};
};

enum class OcaNetworkStatus : OcaEnumItem
{
    Unknown = 0,
    Ready,
    StartingUp,
    Stopped
};

enum class OcaNetworkLinkType: OcaEnumItem
{
    None = 0,
    EthernetWired,
    EthernetWireless,
    USB,
    SerialP2P
};

enum class OcaNetworkMediaProtocol : OcaEnumItem
{
    None = 0,
    AV3,
    AVBTP,
    Dante,
    Cobranet
};

enum class OcaNetworkControlProtocol : OcaEnumItem
{
    None = 0,
    OCP01,
    OCP02,
    OCP03
};

enum class OcaStreamType : OcaEnumItem
{
    None = 0,
    Unicast,
    Multicast
};

enum class OcaStreamStatus : OcaEnumItem
{
    NotConnected = 0,
    Connected,
    Paused
};

enum class OcaStreamConnectorStatus : OcaEnumItem
{
    NotAvailable = 0,
    Idle,
    Connected,
    Paused
};

enum class OcaNetworkSignalChannelStatus : OcaEnumItem
{
    NotConnected = 0,
    Connected,
    Muted
};

enum class OcaNetworkMediaSourceOrSink : OcaEnumItem
{
    None = 0,
    Source,
    Sink
};

class OcaStream
{
    OcaUint16 ErrorNumber;
    OcaStreamID IDAdvertised;
    OcaStreamIndex Index;
    OcaString Label;
    OcaONo LocalConnectorONo;
    OcaUint16 Priority;
    OcaStreamConnectorIdentification RemoteConnectorIdentification;
    OcaBoolean Secure;
    OcaStreamStatus Status;
    OcaStreamParameters StreamParameters;
    OcaStreamType StreamType;

public:
    OcaStream(){};
    virtual ~OcaStream(){};
};

#endif // NETWORKTYPES_H
