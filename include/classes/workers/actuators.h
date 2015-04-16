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
    OcaStatus GetLength(OcaUint32, OcaUint32, OcaUint32);
    OcaStatus GetCoefficients(OcaList<OcaFloat32>);
    OcaStatus SetCoefficients(OcaList<OcaFloat32>);
    OcaStatus GetSampleRate(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetSampleRate(OcaFrequency);
};

class OcaFilterArbitraryCurve : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaTransferFunction     TransferFunction;
    OcaFrequency            SampleRate;

public:
    OcaStatus GetTransferFunction(OcaTransferFunction);
    OcaStatus SetTransferFunction(OcaList<OcaFrequency>,
                                  OcaList<OcaDB>,
                                  OcaList<OcaFloat32>);
    OcaStatus GetSampleRate(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetSampleRate(OcaFrequency);
};

class OcaDynamics : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaBoolean              Triggered;
    OcaDB                   DynamicGain;
    OcaDynamicsFunction     Function;
    OcaFloat32              Ratio;
    OcaDBr                  Threshold;
    OcaPresentationUnit    ThresholdPresentationUnits;
    OcaLevelDetectionLaw     DetectorLaw;
    OcaTimeInterval         AttackTime;
    OcaTimeInterval         ReleaseTime;
    OcaTimeInterval         HoldTime;
    OcaDB                   DynamicGainCeiling;
    OcaDB                   DynamicGainFloor;
    OcaFloat32              KneeParameter;

public:
    OcaStatus GetTriggered(OcaBoolean);
    OcaStatus GetDynamicGain(OcaDB);
    OcaStatus GetFunction(OcaDynamicsFunction);
    OcaStatus SetFunction(OcaDynamicsFunction);
    OcaStatus GetRatio(OcaFloat32, OcaFloat32, OcaFloat32);
    OcaStatus SetRatio(OcaFloat32);
    OcaStatus GetThreshold(OcaDBr, OcaDBz, OcaDBz);
    OcaStatus SetThreshold(OcaDBr);
    OcaStatus GetThresholdPresentationUnits(OcaPresentationUnit);
    OcaStatus SetThresholdPresentationUnits(OcaPresentationUnit);
    OcaStatus GetDetectorLaw(OcaLevelDetectionLaw);
    OcaStatus SetDetectorLaw(OcaLevelDetectionLaw);
    OcaStatus GetAttackTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetAttackTime(OcaTimeInterval);
    OcaStatus GetReleaseTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetReleaseTime(OcaTimeInterval);
    OcaStatus GetHoldTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetHoldTime(OcaTimeInterval);
    OcaStatus GetDynamicGainFloor(OcaDB, OcaDB, OcaDB);
    OcaStatus SetDynamicGainFloor(OcaDB);
    OcaStatus GetDynamicGainCeiling(OcaDB, OcaDB, OcaDB);
    OcaStatus SetDynamicGainCeiling(OcaDB);
    OcaStatus GetKneeParameter(OcaFloat32, OcaFloat32, OcaFloat32);
    OcaStatus SetKneeParameter(OcaFloat32);
};

class OcaDynamicsDetector : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaLevelDetectionLaw    Law;
    OcaTimeInterval         AttackTime;
    OcaTimeInterval         ReleaseTime;
    OcaTimeInterval         HoldTime;

public:
    OcaStatus GetLaw(OcaLevelDetectionLaw);
    OcaStatus SetLaw(OcaLevelDetectionLaw);
    OcaStatus GetAttackTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetAttackTime(OcaTimeInterval);
    OcaStatus GetReleaseTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetReleaseTime(OcaTimeInterval);
    OcaStatus GetHoldTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetHoldTIme(OcaTimeInterval);
};

class OcaDynamicsCurve : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaUint8                nSegments;
    OcaList<OcaDBr>         Threshold[];
    OcaList<OcaFloat32>     Slope[];
    OcaList<OcaFloat32>     KneeParameter;
    OcaDB                   DynamicGainFloor;
    OcaDB                   DynamicGainCeiling;

public:
    OcaStatus GetNSegments(OcaUint8, OcaUint8, OcaUint8);
    OcaStatus SetNSegments(OcaUint8);
    OcaStatus GetThreshold(OcaDBr, OcaDBz, OcaDBz);
    OcaStatus SetThreshold(OcaList<OcaDBr>);
    OcaStatus GetSlope(OcaList<OcaFloat32>,
                       OcaList<OcaFloat32>,
                       OcaList<OcaFloat32>);
    OcaStatus SetSlope(OcaList<OcaFloat32>);
    OcaStatus GetKneeParameter(OcaList<OcaFloat32>,
                               OcaList<OcaFloat32>,
                               OcaList<OcaFloat32>);
    OcaStatus SetKneeParameter(OcaList<OcaFloat32>);
    OcaStatus GetDynamicGainCeiling(OcaDB, OcaDB, OcaDB);
    OcaStatus SetDynamicGainCeiling(OcaDB);
    OcaStatus GetDynamicGainFloor(OcaDB, OcaDB, OcaDB);
    OcaStatus SetDynamicGainFloor(OcaDB);
};

class OcaSignalGenerator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaFrequency            Frequency1;
    OcaFrequency            Frequency2;
    OcaDBz                  Level;
    OcaWaveformType         Waveform;
    OcaSweepType            SweepType;
    OcaTimeInterval         SweepTime;
    OcaBoolean              SweepRepeat;
    OcaBoolean              Generating;

public:
    OcaStatus GetFrequency1(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetFrequency1(OcaFrequency);
    OcaStatus GetFrequency2(OcaFrequency, OcaFrequency, OcaFrequency);
    OcaStatus SetFrequency2(OcaFrequency);
    OcaStatus GetLevel(OcaDBz, OcaDBz, OcaDBz);
    OcaStatus SetLevel(OcaDBz);
    OcaStatus GetWaveform(OcaWaveformType);
    OcaStatus SetWaveform(OcaWaveformType);
    OcaStatus GetSweepType(OcaSweepType);
    OcaStatus SetSweepType(OcaSweepType);
    OcaStatus GetSweepTime(OcaTimeInterval, OcaTimeInterval, OcaTimeInterval);
    OcaStatus SetSweepTime(OcaTimeInterval);
    OcaStatus GetSweepRepeat(OcaBoolean);
    OcaStatus SetSweepRepeat(OcaBoolean);
    OcaStatus GetGenerating(OcaBoolean);
    OcaStatus Start();
    OcaStatus Stop();
};

class OcaSignalInput : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
};

class OcaSignalOutput : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
};

class OcaTemperatureActuator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaTemperature          Temperature;

public:
    OcaStatus GetTemperature(OcaTemperature, OcaTemperature, OcaTemperature);
    OcaStatus SetTemperature(OcaTemperature);
};

class OcaIdentificationActuator : OcaActuator
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaBoolean              active;

public:
    OcaStatus GetActive(OcaBoolean);
    OcaStatus SetActive(OcaBoolean);
};

#endif // ACTUATORS_H
