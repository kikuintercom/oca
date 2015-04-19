#ifndef MANAGERS_H
#define MANAGERS_H

class OcaManager : OcaRoot
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
};

class OcaDeviceManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaModelGUID            ModelGUID;
    OcaString               SerialNumber;
    OcaModelDescription     ModelDescription;
    OcaString               DeviceName;
    OcaUint16               OcaVersion;
    OcaString               Role;
    OcaString               UserInventoryCode;
    OcaBoolean              Enabled;
    OcaDeviceState          State;
    OcaBoolean              Busy;
    OcaResetCause           ResetCause;
    OcaString               Message;
    OcaList<OcaManagerDescriptor>   Managers;

public:
    OcaStatus ClearResetCause();
    OcaStatus GetDeviceName(OcaString);
    OcaStatus GetEnabled(OcaBoolean);
    OcaStatus GetManagers(OcaList<OcaManagerDescriptor>);
    OcaStatus GetMessage(OcaString);
    OcaStatus GetModelDescription(OcaModelDescription);
    OcaStatus GetModelGUID(OcaModelGUID);
    OcaStatus GetOcaVersion(OcaUint16);
    OcaStatus GetResetCause(OcaResetCause);
    OcaStatus GetRole(OcaString);
    OcaStatus GetSerialNumber(OcaString);
    OcaStatus GetState(OcaDeviceState);
    OcaStatus GetUserInventoryCode(OcaString);
    OcaStatus SetDeviceName(OcaString);
    OcaStatus SetEnabled(OcaBoolean);
    OcaStatus SetMessage(OcaString);
    OcaStatus SetResetKey(OcaBlobFixedLen, OcaNetworkAddress);
    OcaStatus SetRole(OcaString);
    OcaStatus SetUserInventoryCode(OcaString);
};

class OcaSecurityManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    bool                    secureControlData;

public:
    OcaStatus AddPreSharedKey(OcaString, OcaBlob);
    OcaStatus ChangePreSharedKey(OcaString, OcaBlob);
    OcaStatus DeletePreSharedKey(OcaString);
    OcaStatus DisableControlSecurity();
    OcaStatus EnableControlSecurity();
};

class OcaFirmwareManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaList<OcaVersion>        ComponentVersions;

public:
    OcaStatus GetComponentVersions(OcaList<OcaVersion>);
    OcaStatus StartUpdateProcess();
    OcaStatus BeginActiveImageUpdate(OcaComponent);
    OcaStatus AddImageData(OcaUint32, OcaBlob);
    OcaStatus VerifyImage(OcaBlob);
    OcaStatus EndActiveImageUpdate();
    OcaStatus BeginPassiveComponentUpdate(OcaComponent, OcaNetworkAddress,
                                          OcaString);
    OcaStatus EndUpdateProcess();
};

class OcaSubscriptionManager : OcaManager
{
private:
    OcaClassID                  ClassID;
    OcaClassVersionNumber       VersionNumber;
    OcaSubscriptionManagerState State;

public:
    void NotificationsDisabled(OcaEventData);
    void SynchronizeState(OcaObjectListEventData);
    OcaStatus AddSubscription(OcaEvent, OcaMethod, OcaBlob,
                              OcaNotificationDeliveryMode,
                              OcaNetworkAddress);
    OcaStatus RemoveSubscription(OcaEvent, OcaMethod);
    OcaStatus DisableNotifications();
    OcaStatus ReEnableNotifications();
};

class OcaPowerManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaPowerState           State;
    OcaList<OcaONo>         PowerSupplies;
    OcaList<OcaONo>         ActivePowerSupplies;
    OcaBoolean              AutoState;
    OcaPowerState           TargetState;

public:
    OcaStatus GetState(OcaPowerState);
    OcaStatus SetState(OcaPowerState);
    OcaStatus GetPowerSupplies(OcaList<OcaONo>);
    OcaStatus GetActivePowerSupplies(OcaList<OcaONo>);
    OcaStatus ExchangePowerSupply(OcaONo, OcaONo, OcaBoolean);
    OcaStatus GetAutoState(OcaBoolean);
};

class OcaNetworkManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaList<OcaONo>         Networks;
    OcaList<OcaONo>         StreamNetworks;

public:
    OcaStatus GetNetworks(OcaList<OcaONo>);
    OcaStatus GetStreamNetworks(OcaList<OcaONo>);
};

class OcaMediaClockManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaList<OcaMediaClockType> ClockSourceTypesSupported;
    OcaList<OcaONo>         Clocks;

public:
    OcaStatus GetClocks(OcaList<OcaONo>);
    OcaStatus GetClockSourceTypesSupported(OcaList<OcaMediaClockType>);
};

class OcaLibraryManager : OcaManager
{
    /* A few of the methods here use the class 'OcaLibVolType',
    even though the docs specify a class 'OcaLibraryType', which
    yet again, does not exist and has not been specified as a
    datatype. OcaLibVolType seems to be the closest match for the
    purpose - it's probably another docs inconsistency. */
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaList<OcaONo>         PatchLibraries;
    OcaList<OcaONo>         ParsetLibraries;
    OcaLibVolIdentifier     CurrentPatch;

public:
    OcaStatus AddLibrary(OcaLibVolType, OcaONo);
    OcaStatus DeleteLibrary(OcaONo);
    OcaStatus GetLibraryCount(OcaLibVolType, OcaUint16);
    OcaStatus GetLibraryList(OcaLibVolType, OcaList<OcaONo>);
    OcaStatus GetCurrentPatch(OcaLibVolIdentifier);
    OcaStatus SetCurrentPatch(OcaLibVolIdentifier);
};

class OcaAudioProcessingManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaDB                   Headroom;

public:
    OcaStatus GetHeadroom(OcaDB);
    OcaStatus SetHeadroom(OcaDB);
};

class OcaDeviceTimeManager : OcaManager
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;

public:
    OcaStatus GetDeviceTime(OcaTimeOfDay);
    OcaStatus SetDeviceTime(OcaTimeOfDay);
};

#endif // MANAGERS_H
