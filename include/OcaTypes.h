#ifndef OCATYPES_H
#define OCATYPES_H

#include "string"
#include "stdint.h"

typedef uint16_t    OcaClassID;
typedef uint16_t    OcaClassVersionNumber;
typedef uint16_t    OcaONo;
typedef bool        OcaBoolean;
typedef std::string OcaString;

typedef bool        OcaPropertyChangedEventData;
enum class          OcaStatus;// {} OcaStatus;
//enum OcaStatus;
enum class          OcaClassIdentification;//{ClassID, ClassVersion} OcaClassIdentification;
//enum OcaClassIdentification;

#endif
