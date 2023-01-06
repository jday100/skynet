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


namespace T100Painter{

typedef enum{
    T100PAINTER_STATE_NONE          = 0,
    T100PAINTER_STATE_ALONE,
    T100PAINTER_STATE_EMBED,
    T100PAINTER_STATE_MAX
}T100PAINTER_STATE;

typedef enum{
    T100CANVAS_STATE_NONE           = 0,
    //
    T100CANVAS_STATE_PAINT,
    T100CANVAS_STATE_SELECTED,
    //
    T100CANVAS_STATE_MAX
}T100CANVAS_STATE;

}

#endif // T100PAINTERCOMMON_H
