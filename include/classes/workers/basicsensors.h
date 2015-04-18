#ifndef BASICSENSORS_H
#define BASICSENSORS_H

class OcaBasicSensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
};

class OcaBooleanSensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaBoolean              Reading;

public:
    OcaStatus GetReading(OcaBoolean);
};

class OcaInt8Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt8                 Reading;

public:
    OcaStatus GetReading(OcaInt8, OcaInt8, OcaInt8);
};

class OcaInt16Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt16                Reading;

public:
    OcaStatus GetReading(OcaInt16, OcaInt16, OcaInt16);
};

class OcaInt32Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt32                Reading;

public:
    OcaStatus GetReading(OcaInt32, OcaInt32, OcaInt32);
};

class OcaInt64Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaInt64                Reading;

public:
    OcaStatus GetReading(OcaInt64, OcaInt64, OcaInt64);
};

class OcaUint8Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint8                Reading;

public:
    OcaStatus GetReading(OcaUint8, OcaUint8, OcaUint8);
};

class OcaUint16Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint16               Reading;

public:
    OcaStatus GetReading(OcaUint16, OcaUint16, OcaUint16);
};

class OcaUint32Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint32               Reading;

public:
    OcaStatus GetReading(OcaUint32, OcaUint32, OcaUint32);
};

class OcaUint64Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaUint64               Reading;

public:
    OcaStatus GetReading(OcaUint64, OcaUint64, OcaUint64);
};

class OcaFloat32Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaFloat32              Reading;

public:
    OcaStatus GetReading(OcaFloat32, OcaFloat32, OcaFloat32);
};

class OcaFloat64Sensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaFloat64              Reading;

public:
    OcaStatus GetReading(OcaFloat64, OcaFloat64, OcaFloat64);
};

class OcaStringSensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaString               String;
    OcaUint16               MaxLen;

public:
    OcaStatus GetString(OcaString);
    OcaStatus GetMaxLen(OcaUint16);
    OcaStatus SetMaxLen(OcaUint16);
};

class OcaBitstringSensor : OcaBasicSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaBitstring            Bitstring;

public:
    OcaStatus GetNrBits(OcaUint16);
    OcaStatus GetBit(OcaUint16, OcaUint8);
    OcaStatus GetBitstring(OcaBitstring);
};

#endif // BASICSENSORS_H
