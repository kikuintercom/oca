#ifndef AGENTS_H
#define AGENTS_H

class OcaAgent : OcaRoot
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaString               Label;
    OcaONo                  Owner;

public:
    OcaStatus GetLabel(OcaString);
    OcaStatus SetLabel(OcaString);
    OcaStatus GetOwner(OcaONo);
};

class OcaNetwork : OcaAgent
{
private:
    OcaClassID                              ClassID;
    OcaClassVersionNumber                   ClassVersion;
    OcaNetworkLinkType                      LinkType;
    OcaNetworkNodeID                        IDAdvertised;
    OcaNetworkControlProtocol               ControlProtocol;
    OcaNetworkMediaProtocol                 MediaProtocol;
    OcaNetworkStatus                        Status;
    OcaList<OcaNetworkSystemInterfaceID>    SystemInterfaces;
    OcaList<OcaONo>                         MediaPorts;
    OcaNetworkStatistics                    Statistics;

public:
    OcaStatus GetLinkType(OcaNetworkLinkType);
    OcaStatus GetIDAdvertised(OcaNetworkNodeID);
    OcaStatus SetIDAdvertised(OcaNetworkNodeID);
    OcaStatus GetControlProtocol(OcaNetworkControlProtocol);
    OcaStatus GetMediaProtocol(OcaNetworkMediaProtocol);
    OcaStatus GetStatus(OcaNetworkStatus);
    OcaStatus GetStatistics(OcaNetworkStatistics);
    OcaStatus ResetStatistics();
    OcaStatus GetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceID>);
    OcaStatus SetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceID>);
    OcaStatus GetMediaPorts(OcaList<OcaONo>);
    OcaStatus Startup();
    OcaStatus Shutdown();
};

class OcaGrouper : OcaAgent
{
private:
    OcaClassID                      ClassID;
    OcaClassVersionNumber           ClassVersion;
    OcaBoolean                      ActuatorOrSensor;
    OcaList<OcaGrouperGroup>        Groups[];
    OcaList<OcaGrouperCitizen>      Citizens[];
    OcaList<OcaGrouperEnrollment>   Enrollments[];

public:
    void StatusChange(OcaGrouperStatusChangeEventData);
    OcaStatus AddGroup(OcaString, OcaUint16, OcaONo);
    OcaStatus DeleteGroup(OcaUint16);
    OcaStatus GetGroupCount(OcaUint16);
    OcaStatus GetGroupList(OcaList<OcaGrouperGroup>);
    OcaStatus AddCitizen(OcaGrouperCitizen, OcaUint16);
    OcaStatus DeleteCitizen(OcaUint16);
    OcaStatus GetCitizenCount(OcaUint16);
    OcaStatus GetCitizenList(OcaList<OcaGrouperCitizen>);
    OcaStatus GetEnrollment(OcaGrouperEnrollment, OcaBoolean);
    OcaStatus GetGroupMemberList(OcaUint16, OcaList<OcaGrouperCitizen>);
    OcaStatus GetActuatorOrSensor(OcaBoolean);
    OcaStatus SetActuatorOrSensor(OcaBoolean);
};

class OcaRamper : OcaAgent
{
private:
    OcaClassID                  ClassID;
    OcaClassVersionNumber       ClassVersion;
    OcaRamperState              State;
    OcaProperty                 RampedProperty;
    OcaRamperTimeMode           TimeMode;
    OcaTimeOfDay                StartTime;
    OcaTimeInterval             Duration;
    OcaRamperInterpolationLaw   InterpolationLaw;
    OcaFloat64                  Goal;

public:
    OcaStatus Control(OcaRamperRunCommand);
    OcaStatus GetState(OcaRamperState);
    OcaStatus GetRampedProperty(OcaProperty);
    OcaStatus SetRampedProperty(OcaProperty);
    OcaStatus GetTimeMode(OcaRamperTimeMode);
    OcaStatus SetTimeMode(OcaRamperTimeMode);
    OcaStatus GetStartTime(OcaTimeOfDay);
    OcaStatus SetStartTime(OcaTimeOfDay);
    OcaStatus GetDuration(OcaTimeInterval, OcaTimeInterval
                          OcaTimeInterval);
    OcaStatus SetDuration(OcaTimeInterval);
    OcaStatus GetInterpolationLaw(OcaFloat64);
    OcaStatus SetInterpolationLaw(OcaFloat64);
    OcaStatus GetGoal(OcaFloat64);
    OcaStatus SetGoal(OcaFloat64);
};

class OcaLibrary : OcaAgent
{
private:
    OcaClassID                      ClassID;
    OcaClassVersionNumber           ClassVersion;
    OcaLibVolType                   DataType;
    OcaLibAccess                    Access;
    OcaMap<OcaLibVolID, OcaLibVol<>>  Volumes[];

public:
    OcaStatus AddVolume(OcaLibVol<>, OcaLibVolID);
    OcaStatus ReplaceVolume(OcaLibVolID, OcaLibVol<>);
    OcaStatus DeleteVolume(OcaLibVolID);
    OcaStatus GetVolume(OcaLibVol<>);
    OcaStatus GetVolumeCount(OcaUint16);
    OcaStatus GetVolumes(OcaMap<OcaLibVolID, OcaLibVol<>>);
    OcaStatus GetAccess(OcaLibAccess);
    OcaStatus SetAccess(OcaLibAccess);
};

class OcaMediaClock : OcaAgent
{
private:
    OcaClassID                  ClassID;
    OcaClassVersionNumber       VersionNumber;
    OcaMediaClockType           Type;
    OcaUint16                   DomainID;
    OcaList<OcaMediaClockRate>  RatesSupported;
    OcaMediaClockRate           CurrentRate;
    OcaMediaClockLockState      LockState;

public:
    OcaStatus GetType(OcaMediaClockType);
    OcaStatus SetType(OcaMediaClockType);
    OcaStatus GetDomainID(OcaUint16);
    OcaStatus SetDomainID(OcaUint16);
    OcaStatus GetRatesSupported(OcaList<OcaMediaClockRate>);
    OcaStatus GetRate(OcaMediaClockRate);
    OcaStatus SetRate(OcaMediaClockRate);
    OcaStatus GetLockState(OcaMediaClockLockState);
};

class OcaNumericObserver
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaObserverState        State;
    OcaProperty             ObservedProperty;
    OcaFloat64              Threshold;
    OcaRelationalOperator   Operator;
    OcaBoolean              TwoWay;
    OcaFloat64              Hysteresis;
    OcaTimeInterval         Period;

public:
    void Observation(OcaObservationEventData);
    OcaStatus GetLastObservation(OcaFloat64);
    OcaStatus GetState(OcaObserverState);
    OcaStatus GetObservedProperty(OcaProperty);
    OcaStatus SetObservedProperty(OcaProperty);
    OcaStatus GetThreshold(OcaFloat64);
    OcaStatus SetThreshold(OcaFloat64);
    OcaStatus GetOperator(OcaRelationalOperator);
    OcaStatus SetOperator(OcaRelationalOperator);
    OcaStatus GetTwoWay(OcaBoolean);
    OcaStatus GetHysteresis(OcaFloat64);
    OcaStatus GetPeriod(OcaTimeInterval);
    OcaStatus SetPeriod(OcaTimeInterval);
};

class OcaPowerSupply : OcaAgent
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaPowerSupplyType      Type;
    OcaString               ModelInfo;
    OcaPowerSupplyState     State;
    OcaBoolean              Charging;
    OcaFloat32              LoadFractionAvailable;
    OcaFloat32              StorageFractionAvailable;

public:
    OcaStatus GetType(OcaPowerSupplyType);
    OcaStatus GetModelInfo(OcaString);
    OcaStatus GetState(OcaPowerSupplyState);
    OcaStatus SetState(OcaPowerSupplyState);
    OcaStatus GetCharging(OcaBoolean);
    OcaStatus GetLoadFractionAvailable(OcaFloat32);
    OcaStatus GetStorageFractionAvailable(OcaFloat32);
};

class OcaEventHandler : OcaAgent
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;

public:
    void OnEvent(OcaBlob, OcaEventData);
};

class OcaNumericObserverList : OcaAgent
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaObserverState        State;
    OcaList<OcaProperty>    ObservedProperties;
    OcaFloat64              Threshold;
    OcaRelationalOperator   Operator;
    OcaBoolean              TwoWay;
    OcaFloat64              Hysteresis;
    OcaTimeInterval         Period;

public:
    void Observation(OcaObservationListEventData);
    OcaStatus GetLastObservation(OcaList<OcaFloat64>);
    OcaStatus GetObservedProperties(OcaList<OcaProperty>);
    OcaStatus SetObservedProperties(OcaList<OcaProperty>);
    OcaStatus GetThreshold(OcaFloat64);
    OcaStatus SetThreshold(OcaFloat64);
    OcaStatus GetOperator(OcaRelationalOperator);
    OcaStatus SetOperator(OcaRelationalOperator);
    OcaStatus GetTwoWay(OcaBoolean);
    OcaStatus SetTwoWay(OcaBoolean);
    OcaStatus GetHysteresis(OcaFloat64);
    OcaStatus SetHysteresis(OcaFloat64);
    OcaStatus GetPeriod(OcaTimeInterval);
    OcaStatus SetPeriod(OcaTimeInterval);
};

class OcaStreamNetwork : OcaAgent
{
private:
    OcaClassID                  ClassID;
    OcaClassVersionNumber       VersionNumber;
    OcaNetworkControlProtocol   ControlProtocol;
    OcaNetworkNodeID            IDAdvertised;
    OcaNetworkLinkType          LinkType;
    OcaNetworkMediaProtocol     MediaProtocol;
    OcaList<OcaONo>             SignalChannelsSink;
    OcaList<OcaONo>             SourceChannelsSink;
    OcaNetworkStatistics        Statistics;
    OcaNetworkStatus            Status;
    OcaList<OcaONo>             StreamConnectorsSink;
    OcaList<OcaONo>             StreamConnectorsSource;
    OcaList<OcaNetworkSystemInterfaceID>    SystemInterfaces;

public:
    OcaStatus GetLinkType(OcaNetworkLinkType);
    OcaStatus GetIDAdvertised(OcaNetworkNodeID);
    OcaStatus SetIDAdvertised(OcaNetworkNodeID);
    OcaStatus GetControlProtocol(OcaNetworkControlProtocol);
    OcaStatus GetMediaProtocol(OcaNetworkMediaProtocol);
    OcaStatus GetStatus(OcaNetworkStatus);
    OcaStatus GetStatistics(OcaNetworkStatistics);
    OcaStatus ResetStatistics();
    OcaStatus GetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceID>);
    OcaStatus SetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceID>);
    OcaStatus GetStreamConnectorsSource(OcaList<OcaONo>);
    OcaStatus SetStreamConnectorsSource(OcaList<OcaONo>);
    OcaStatus GetStreamConnectorsSink(OcaList<OcaONo>);
    OcaStatus SetStreamConnectorsSink(OcaList<OcaONo>);
    OcaStatus GetSignalChannelsSource(OcaList<OcaONo>);
    OcaStatus SetSignalChannelsSource(OcaList<OcaONo>);
    OcaStatus GetSignalChannelsSink(OcaList<OcaONo>);
    OcaStatus SetSignalChannelsSink(OcaList<OcaONo>);
    OcaStatus Startup();
    OcaStatus Shutdown();
};

class OcaStreamConnector : OcaAgent
{
private:
    OcaClassID                                  ClassID;
    OcaClassVersionNumber                       VersionNumber;
    OcaStreamConnectorID                        IDAdvertised;
    OcaONo                                      OwnerNetwork;
    OcaMap<OcaStreamConnectorPinIndex, OcaONo>  Pins;
    OcaNetworkMediaSourceOrSink                 SourceOrSink;
    OcaStreamConnectorStatus                    Status;
    OcaMap<OcaStreamIndex, OcaStream>           Streams;

public:
    OcaStatus ConnectStream(OcaStream, OcaStreamIndex);
    OcaStatus DisconnectStream(OcaStreamIndex);
    OcaStatus GetIDAdvertised(OcaStreamConnectorID);
    OcaStatus GetOwnerNetwork(OcaONo);
    OcaStatus GetPins(OcaMap<OcaStreamConnectorPinIndex, OcaONo>);
    OcaStatus GetSourceOrSink(OcaNetworkMediaSourceOrSink);
    OcaStatus GetStatus(OcaStreamConnectorStatus);
    OcaStatus GetStreams(OcaList<OcaStream>);
    OcaStatus SetIDAdvertised(OcaStreamConnectorID);
    OcaStatus SetOwnerNetwork(OcaONo);
    OcaStatus SetSourceOrSink(OcaNetworkMediaSourceOrSink);
};

#endif // AGENTS_H
