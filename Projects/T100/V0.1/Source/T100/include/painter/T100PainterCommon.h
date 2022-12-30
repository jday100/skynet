#ifndef T100PAINTERCOMMON_H
#define T100PAINTERCOMMON_H

#include <unordered_map>
#include "T100Common.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"
#include "T100SafeVector.h"

namespace T100Painter{
    class T100ElementBase;
}

#define     T100PAINTER_ELEMENT_VECTOR          T100Library::T100SafeVector<T100ElementBase*>
#define     T100PAINTER_ELEMENT_HASH            std::unordered_map<T100STRING, T100ElementBase*, T100Library::T100StringHash, T100Library::T100StringEqual>

#endif // T100PAINTERCOMMON_H
