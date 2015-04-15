#ifndef EVENTSUBTYPES_H
#define EVENTSUBTYPES_H

/************************************************
EVENT & SUBSCRIPTION DATATYPES
************************************************/

class OcaEvent{
    OcaONo EmitterONo;
    OcaEventID EventID;

public:
    OcaEvent(){};
    virtual ~OcaEvent(){};
};

class OcaMethod
{
    OcaONo ONo;
    OcaMethodID MethodID;

public:
    OcaMethod(){};
    virtual ~OcaMethod(){};
};

class OcaEventData
{
    OcaEvent Event;

public:
    OcaEventData(){};
    virtual ~OcaEventData(){};
};

class OcaObjectListEventData: public OcaEventData
{
    OcaList<OcaONo> objectList;

public:
    OcaObjectListEventData(){};
    virtual ~OcaObjectListEventData(){};
};

enum class OcaPropertyChangeType : OcaEnumItem
{
    CurrentChanged = 1,
    MinChanged,
    MaxChanged,
    ItemAdded,
    ItemChanged,
    ItemDeleted
};

template <class T> class OcaPropertyChangedEventData : OcaEventData
{
    OcaPropertyID PropertyID;
    T PropertyValue;
    OcaPropertyChangeType ChangeType;
    T PropertyKey;

public:
    OcaPropertyChangedEventData(){};
    virtual ~OcaPropertyChangedEventData(){};
};

class OcaObservationEventData
{
    OcaEvent Event;
    OcaFloat64 Reading;

public:
    OcaObservationEventData(){};
    virtual ~OcaObservationEventData(){};
};

class OcaObservationListEventData
{
    OcaEvent Event;
    OcaList<OcaFloat64> Reading;

public:
    OcaObservationListEventData(){};
    virtual ~OcaObservationListEventData(){};
};

enum class OcaGrouperStatusChangeType : OcaEnumItem
{
    citizenAdded = 1,
    citizenDeleted,
    citizenConnectionLost,
    citizenConnectionReEstablished,
    citizenError,
    enrollment,
    unEnrollment
};

class OcaGrouperStatusChangeEventData : OcaEventData
{
    OcaUint16 groupIndex, citizenIndex;
    OcaGrouperStatusChangeType changeType;

public:
    OcaGrouperStatusChangeEventData(){};
    virtual ~OcaGrouperStatusChangeEventData(){};
};

enum class OcaNotificationDeliveryMode : OcaEnumItem
{
    Reliable = 1,
    Fast
};

enum class OcaSubscriptionManagerState : OcaEnumItem
{
    Normal = 1,
    EventsDisabled
};

#endif // EVENTSUBTYPES_H
