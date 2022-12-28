#ifndef T100PAINTERCOMMON_H
#define T100PAINTERCOMMON_H

#include "T100Common.h"
#include "T100SafeVector.h"

namespace T100Painter{
    class T100ElementBase;
}

#define     T100PAINTER_ELEMENT_VECTOR          T100Library::T100SafeVector<T100ElementBase*>

#endif // T100PAINTERCOMMON_H
