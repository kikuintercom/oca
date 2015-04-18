#ifndef SENSORS_H
#define SENSORS_H

class OcaSensor : OcaWorker
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaSensorReadingState   ReadingState;

public:
    OcaStatus GetReadingState(OcaSensorReadingState);
};

class OcaLevelSensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaDB                   Reading;

public:
    OcaStatus GetReading(OcaDB, OcaDB, OcaDB);
};

class OcaAudioLevelSensor : OcaLevelSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaLevelMeterLaw        Law;

public:
    OcaStatus GetLaw(OcaLevelMeterLaw);
    OcaStatus SetLaw(OcaLevelMeterLaw);
};

class OcaTimeIntervalSensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaTimeInterval         Reading;

public:
    OcaStatus GetReading(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
};

class OcaFrequencySensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaFrequency            Reading;

public:
    OcaStatus GetReading(OcaFrequency, OcaFrequency, OcaFrequency);
};

class OcaTemperatureSensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaTemperature          Reading;

public:
    OcaStatus GetReading(OcaTemperature, OcaTemperature, OcaTemperature);
};

class OcaIdentificationSensor : OcaSensor
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;

public:
    void Identify(OcaEventData);
};

#endif // SENSORS_H
