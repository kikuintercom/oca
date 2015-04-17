#ifndef BASICACTUATORS_H
#define BASICACTUATORS_H

#include "actuators.h"

class OcaBasicActuator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
};

class OcaBooleanActuator: OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaBoolean              Setting;

public:
    OcaStatus GetSetting(OcaBoolean);
    OcaStatus SetSetting(OcaBoolean);
};

class OcaInt8Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt8                 Setting;

public:
    OcaStatus GetSetting(OcaInt8, OcaInt8, OcaInt8);
    OcaStatus SetSetting(OcaInt8);
};

class OcaInt16Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt16                Setting;

public:
    OcaStatus GetSetting(OcaInt16, OcaInt16, OcaInt16);
    OcaStatus SetSetting(OcaInt16);
};

class OcaInt32Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt32                Setting;

public:
    OcaStatus GetSetting(OcaInt32, OcaInt32, OcaInt32);
    OcaStatus SetSetting(OcaInt32);
};

class OcaInt64Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt64                Setting;

public:
    OcaStatus GetSetting(OcaInt64, OcaInt64, OcaInt64);
    OcaStatus SetSetting(OcaInt64);
};


class OcaUint8Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint8                Setting;

public:
    OcaStatus GetSetting(OcaUint8, OcaUint8, OcaUint8);
    OcaStatus SetSetting(OcaUint8);
};

class OcaUint16Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint16               Setting;

public:
    OcaStatus GetSetting(OcaUint16, OcaUint16, OcaUint16);
    OcaStatus SetSetting(OcaUint16);
};

class OcaUint32Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint32               Setting;

public:
    OcaStatus GetSetting(OcaUint32, OcaUint32, OcaUint32);
    OcaStatus SetSetting(OcaUint32);
};

class OcaUint64Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint64               Setting;

public:
    OcaStatus GetSetting(OcaUint64, OcaUint64, OcaUint64);
    OcaStatus SetSetting(OcaUint64);
};

class OcaFloat32Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaFloat32              Setting;

public:
    OcaStatus GetSetting(OcaFloat32, OcaFloat32, OcaFloat32);
    OcaStatus SetSetting(OcaFloat32);
};

class OcaFloat64Actuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaFloat64              Setting;

public:
    OcaStatus GetSetting(OcaFloat64, OcaFloat64, OcaFloat64);
    OcaStatus SetSetting(OcaFloat64);
};

class OcaStringActuator : OcaBasicActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaString               Setting;
    OcaUint16               MaxLen;

public:
    OcaStatus GetValue(OcaString);
    OcaStatus SetValue(OcaString);
    OcaStatus GetMaxLen(OcaUint16);
};

class OcaBitstringActuator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaBitstring            Bitstring[];

public:
    OcaStatus GetNrBits(OcaUint16);
    OcaStatus GetBit(OcaUint16, OcaBoolean);
    OcaStatus SetBit(OcaUint16, OcaBoolean);
    OcaStatus GetBitstring(OcaBitstring);
    OcaStatus SetBitstring(OcaBitstring);
};

#endif // BASICACTUATORS_H
