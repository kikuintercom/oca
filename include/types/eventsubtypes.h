#ifndef EVENTSUBTYPES_H
#define EVENTSUBTYPES_H

/************************************************
EVENT & SUBSCRIPTION DATATYPES
************************************************/

class OcaEvent{
public:
    OcaEvent(){};
    virtual ~OcaEvent(){};
};

template <class T>
class OcaPropertyChangedEventData{
public:
    uint16_t PropertyID;
    T PropertyValue;
    uint16_t ChangeType;
    T PropertyKey;
// TODO figure this out
    OcaPropertyChangedEventData(){};
};

#endif // EVENTSUBTYPES_H
