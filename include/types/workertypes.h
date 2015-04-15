#ifndef WORKERTYPES_H
#define WORKERTYPES_H

/************************************************
WORKER DATATYPES
************************************************/

/* It would be fair to say that the DB-variants should probably
exist within their own classes at some point, with operator=
overrides... */

typedef OcaFloat32 OcaDB;

typedef OcaDB OcaDBz;

class OcaDBr
{
    OcaDB Value;
    OcaDBz Ref;

public:
    OcaDBr(){};
    virtual ~OcaDBr();
};

typedef OcaDB OcaDBV;

typedef OcaDB OcaDBu;

typedef OcaDB OcaDBfs;

enum class OcaMuteState : OcaEnumItem
{
    Muted = 1,
    Unmuted
};

enum class OcaPolarityState : OcaEnumItem
{
    NonInverted = 1,
    Inverted
};

enum class OcaDelayUnit : OcaEnumItem
{
    Time = 1,
    Distance,
    Samples,
    Microseconds,
    Milliseconds,
    Centimeters,
    Inches,
    Feet
};

class OcaDelayValue
{
    OcaFloat32 DelayValue;
    OcaDelayUnit DelayUnit;

public:
    OcaDelayValue(){};
    virtual ~OcaDelayValue(){};
};

class OcaFrequency
{
    OcaFloat32 Hz;

public:
    OcaFrequency(){};
    virtual ~OcaFrequency(){};
};

class OcaFrequencyResponse
{
    OcaMap<OcaFrequency, OcaDB> Characteristic;

public:
    OcaFrequencyResponse(){};
    virtual ~OcaFrequencyResponse(){};
};

class OcaTransferFunction
{
    OcaList<OcaFrequency> Frequency;
    OcaList<OcaFloat32> Amplitude;
    OcaList<OcaFloat32> Phase;

public:
    OcaTransferFunction(){};
    virtual ~OcaTransferFunction(){};
};

typedef OcaUint64 OcaTimeOfDay;

typedef OcaFloat32 OcaTimeInterval;

class OcaPeriod
{
    OcaUint32 Period;

public:
    OcaPeriod(){};
    virtual ~OcaPeriod(){};
};

enum class OcaClassicalFilterShape : OcaEnumItem
{
    Butterworth = 1,
    Bessel,
    Chebyshev,
    LinkwitzRiley
};

enum class OcaFilterPassBand : OcaEnumItem
{
    HiPass = 1,
    LowPass,
    BandPass,
    BandReject,
    AllPass
};

enum class OcaParametricEQShape : OcaEnumItem
{
    PEQ = 1,
    LowShelv,
    HighShelv,
    LowPass,
    HighPass,
    BandPass,
    AllPass,
    Notch,
    ToneControlLowFixed,
    ToneControlLowSliding,
    ToneControlHighFixed,
    ToneControlHighSliding
};

enum class OcaDynamicsFunction : OcaEnumItem
{
    None = 0,
    Compress,
    Limit,
    Expand,
    Gate,
    AGC
};

class OcaPilotToneDetectorSpec
{
    OcaDBr Threshold;
    OcaFrequency Frequency;
    OcaPeriod PollInterval;

public:
    OcaPilotToneDetectorSpec(){};
    virtual ~OcaPilotToneDetectorSpec(){};
};

enum class OcaWaveformType : OcaEnumItem
{
    None = 0,
    DC,
    Sine,
    Square,
    Impulse,
    NoisePink,
    NoiseWhite,
    PolarityTest
};

enum class OcaSweepType : OcaEnumItem
{
    Linear =        1,
    Logarithmic =   2,
    None =          0
};

enum class OcaUnitOfMeasure : OcaEnumItem
{
    Ampere =        4,
    DegreeCelsius = 2,
    Hertz =         1,
    None =          0,
    Ohm =           5,
    Volt =          3
};

enum class OcaPresentationUnit : OcaEnumItem
{
    dBu = 0,
    dBV,
    V
};

class OcaTemperature
{
    OcaFloat32 degreesCelsius;

public:
    OcaTemperature(){};
    virtual ~OcaTemperature(){};
};

enum class OcaLevelDetectionLaw : OcaEnumItem
{
    None = 0,
    RMS,
    Peak
};

enum class OcaSensorReadingState : OcaEnumItem
{
    Unknown = 0,
    Valid,
    Underrange,
    Overrange,
    Error
};

enum class OcaLevelMeterLaw : OcaEnumItem
{
    VU = 1,
    ClassicVU,
    PPM1,
    PPM2,
    LUFS,
    LKFS,
    RMS,
    Peak
};

#endif // WORKERTYPES_H
