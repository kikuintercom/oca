#ifndef ACTUATORS_H
#define ACTUATORS_H

class OcaActuator : OcaWorker
{
private:
    OcaClassID            ClassID;
    OcaClassVersionNumber ClassVersion;
};

class OcaMute : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;

public:
    OcaStatus GetState(OcaMuteState);
    OcaStatus SetState(OcaMuteState);
};

class OcaPolarity : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaPolarityState        State;

public:
    OcaStatus GetState(OcaPolarityState);
    OcaStatus SetState(OcaPolarityState);
};

class OcaSwitch : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaUint16               Position;
    OcaList<OcaString>      PositionNames[];
    OcaList<OcaBoolean>     PositionEnable[];

public:
    OcaStatus GetPosition(OcaUint16, OcaUint16, OcaUint16);
    OcaStatus SetPosition(OcaUint16);
    OcaStatus GetPositionName(OcaUint16, OcaString);
    OcaStatus SetPositionName(OcaUint16, OcaString);
    OcaStatus GetPositionNames(OcaList<OcaString>);
    OcaStatus SetPositionNames(OcaList<OcaString>);
    OcaStatus GetPositionEnabled(OcaUint16, OcaBoolean);
    OcaStatus SetPositionEnabled(OcaUint16, OcaBoolean);
    OcaStatus GetPositionEnableds(OcaList<OcaBoolean>);
    OcaStatus SetPositionEnableds(OcaList<OcaBoolean>);
};

class OcaPanBalance : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaFloat32              Position;
    OcaDB                   MidpointGain;

public:
    OcaStatus GetPosition(OcaFloat32, OcaFloat32, OcaFloat32);
    OcaStatus SetPosition(OcaFloat32);
    OcaStatus GetMidpointGain(OcaDB, OcaDB, OcaDB);
    OcaStatus SetMidpointGain(OcaDB);
};

class OcaDelay : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaTimeInterval         DelayTime;

public:
    OcaStatus GetDelayTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetDelayTime(OcaTimeInterval);
};

class OcaDelayExtended : OcaDelay
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaDelayValue           DelayValue;

public:
    OcaStatus GetDelayValue(OcaDelayValue, OcaDelayValue, OcaDelayValue);
    OcaStatus SetDelayValue(OcaDelayValue);
    OcaStatus GetDelayValueConverted(OcaDelayUnit, OcaDelayValue);
};

class OcaFrequencyActuator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaFrequency            Frequency;

public:
    OcaStatus GetFrequency(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetFrequency(OcaFrequency);
};

class OcaFilterClassical : OcaActuator
{
private:
    OcaClassID                  ClassID;
    OcaClassVersionNumber       ClassVersion;
    OcaFrequency                Frequency;
    OcaFilterPassband           Passband;
    OcaClassicalFilterShape     Shape;
    OcaUint16                   Order;
    OcaFloat32                  Parameter;

public:
    OcaStatus GetFrequency(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetFrequency(OcaFrequency);
    OcaStatus GetPassband(OcaFilterPassband);
    OcaStatus SetPassband(OcaFilterPassband);
    OcaStatus GetShape(OcaClassicalFilterShape);
    OcaStatus SetShape(OcaClassicalFilterShape);
    OcaStatus GetOrder(OcaUint16, OcaUint16, OcaUint16);
    OcaStatus SetOrder(OcaUint16);
    OcaStatus GetParameter(OcaFloat32, OcaFloat32, OcaFloat32);
    OcaStatus SetParameter(OcaFloat32);
};

class OcaFilterParametric : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaFrequency            Frequency;
    OcaParametricEQShape    Shape;
    OcaFloat32              WidthParameter;
    OcaDB                   InBandGain;
    OcaFloat32              ShapeParameter;

public:
    OcaStatus GetFrequency(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetFrequency(OcaFrequency);
    OcaStatus GetShape(OcaParametricEQShape);
    OcaStatus SetShape(OcaParametricEQShape);
    OcaStatus GetQ(OcaFloat32);
    OcaStatus SetQ(OcaFloat32);
    OcaStatus GetPassbandGain(OcaDB, OcaDB, OcaDB);
    OcaStatus SetPassbandGain(OcaDB);
};

class OcaFilterPolynomial : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaList<OcaFloat32>     A[];
    OcaList<OcaFloat32>     B[];
    OcaFrequency            SampleRate;
    OcaUint8                MaxOrder;

public:
    OcaStatus GetCoefficients(OcaList<OcaFloat32>, OcaList<OcaFloat32>);
    OcaStatus SetCoeffecients(OcaList<OcaFloat32>, OcaList<OcaFloat32>);
    OcaStatus GetSampleRate(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetSampleRate(OcaFrequency);
    OcaStatus GetMaxOrder(OcaUint8);
};

class OcaFilterFIR : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaUint32               Length;
    OcaList<OcaFloat32>     Coefficients;
    OcaFrequency            SampleRate;

public:
    OcaStatus
};

#endif // ACTUATORS_H
