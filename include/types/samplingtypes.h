#ifndef SAMPLINGTYPES_H
#define SAMPLINGTYPES_H

/************************************************
SAMPLING DATATYPES
************************************************/

enum class OcaMediaClockLockState : OcaEnumItem
{
    Undefined = 0,
    Locked,
    Synchronizing,
    FreeRun,
    Stopped
};

class OcaMediaClockRate
{
    OcaFrequency NominalRate;
    OcaFrequency PullRange;
    OcaFloat32 Accuracy;
    OcaFloat32 JitterMax;

public:
    OcaMediaClockRate(){};
    virtual ~OcaMediaClockRate(){};
};

enum class OcaMediaClockType : OcaEnumItem
{
    None = 0,
    Internal,
    Network,
    External
};

#endif // SAMPLINGTYPES_H
