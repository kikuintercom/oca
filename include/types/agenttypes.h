#ifndef AGENTTYPES_H
#define AGENTTYPES_H

/************************************************
AGENT DATATYPES
************************************************/

class OcaGrouperGroup
{
    OcaUint16 Index;
    OcaString Name;
    OcaONo ProxyONo;

public:
    OcaGrouperGroup(){};
    virtual ~OcaGrouperGroup(){};
};

class OcaGrouperCitizen
{
    int Index;
    OcaOPath ObjectPath;
    OcaBoolean Online;

public:
    OcaGrouperCitizen(){};
    virtual ~OcaGrouperCitizen(){};
};

class OcaGrouperEnrollment
{
    uint16_t GroupIndex, CitizenIndex;

public:
    OcaGrouperEnrollment(){};
    virtual ~OcaGrouperEnrollment(){};
};

enum class OcaRamperTimeMode : OcaEnumItem
{
    Absolute = 1,
    Relative
};

enum class OcaRamperInterpolationLaw : OcaEnumItem
{
    Linear = 1,
    ReverseLinear,
    Sine,
    Exponential
};

enum class OcaRamperRunCommand : OcaEnumItem
{
    Enable = 1,
    Start,
    Halt
};

enum class OcaRamperState : OcaEnumItem
{
    NotInitialized = 1,
    Initialized,
    Scheduled,
    Enabled,
    Ramping
};

enum class OcaObserverState : OcaEnumItem
{
    NotTriggered = 0,
    Triggered
};

enum class OcaRelationalOperator
{
    None = 0,
    Equality,
    Inequality,
    GreaterThan,
    GreaterThanOrEqual,
    LessThan,
    LessThanOrEqual
};

/*
FIXME: Strangely, OcaObservationEventData is defined twice in the
official spec - once in Event & Subscription Datatypes and once here.
The one in E&S is intended to hold data about an event as it is emitted,
whereas this one is intended to be returned as the result of a getter
query.

class OcaObservationEventData
{
    OcaFloat64 Reading;

public:
    OcaObservationEventData(){};
    virtual ~OcaObservationEventData(){};
};
*/


#endif // AGENTTYPES_H
