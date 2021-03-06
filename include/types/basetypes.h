#ifndef BASETYPES_H
#define BASETYPES_H

#include <string>
#include "stdint.h"

/************************************************
BASE DATATYPES
************************************************/

typedef bool        OcaBoolean;

typedef int8_t      OcaInt8;
typedef int16_t     OcaInt16;
typedef int32_t     OcaInt32;
typedef int64_t     OcaInt64;

typedef uint8_t     OcaUint8;
typedef uint16_t    OcaUint16;
typedef uint32_t    OcaUint32;
typedef uint64_t    OcaUint64;

typedef float       OcaFloat32;
typedef double      OcaFloat64;

typedef std::string OcaString;

typedef OcaUint8    OcaEnumItem;

enum class          OcaBaseDataType : OcaEnumItem{
    None = 0,  // Undefined
    OcaBoolean,     // Generic 32-bit float
    OcaInt8,        // Generic UINT8
    OcaInt16,       // Generic UINT16
    OcaInt32,       // Generic UINT32
    OcaInt64,       // Generic UINT32
    OcaUint8,       // Generic UINT32
    OcaUint16,      // Generic UINT32
    OcaUint32,      // Generic UINT32
    OcaUint64,      // Generic UINT32
    OcaFloat32,     // Generic 32-bit float
    OcaFloat64,     // Generic 64-bit float
    OcaString,      // Character count + character array (UTF8)
    OcaBitString,   // Bit count + bit array
    OcaBlob,        // Byte count + byte array
    OcaBlobFixedLen // Byte array
};

class OcaBitstring
{
    uint16_t NrBits; // The size of the bitmask in bits.
    OcaUint8 Bitstring; // The bitstring data as an array of bytes with
                        // the most significant bit of the first byte being
                        // bit number 0.
    public:
        OcaBitstring(){}
        virtual ~OcaBitstring(){};

        operator std::string() const { return ""; };
};

class OcaBlob
{
    uint16_t DataSize; // The size of the BLOB data in bytes.
    uint8_t* Data; // The BLOB data.

    public:
        OcaBlob(){}
        virtual ~OcaBlob(){};

        // TODO: Make this work
        operator std::string() const { return ""; };

};

class OcaBlobFixedLen
{
    uint16_t DataSize; // The size of the BLOB data in bytes.
    uint8_t* Data; // The BLOB data.

public:
    OcaBlobFixedLen(){};
    virtual ~OcaBlobFixedLen(){};

    // TODO: Make this work
    operator std::string() const { return ""; };

};

template <class T> class OcaList
{
    OcaUint16 Count;
    T Items[];

public:
    OcaList(){};
    virtual ~OcaList(){};
};

template <class T> class OcaList2D
{
    OcaUint16 nX;
    OcaUint16 nY;
    T Items[0][0];

public:
    OcaList2D(){};
    virtual ~OcaList2D();
};

template <class K, class V> class OcaMapItem
{
    K Key;
    V Value;

public:
    OcaMapItem(){};
    virtual ~OcaMapItem(){};
};

template <class K, class V> class OcaMap
{
    OcaUint16 Count;
    OcaMapItem<K,V> Items[];

public:
    OcaMap(){};
    virtual ~OcaMap(){};
};

#endif // BASETYPES_H
