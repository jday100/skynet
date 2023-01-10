#ifndef T100ELEMENTCOMMON_H
#define T100ELEMENTCOMMON_H

#include <unordered_map>
#include <wx/propgrid/propgrid.h>
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"


#define     T100ELEMENT_PROPERTY_HASH           std::unordered_map<T100STRING, T100WORD, T100Library::T100StringHash, T100Library::T100StringEqual>


namespace T100Painter{

typedef enum{
    T100ELEMENT_NONE            = 0,
    //
    T100ELEMENT_GRAPHICS_CIRCLE,
    T100ELEMENT_GRAPHICS_RECTANGLE,
    //
    T100ELEMENT_DIAGRAM_MODULE,
    //
    T100ELEMENT_TEXT,
    //
    T100ELEMENT_MAX
}T100ELEMENT_TYPE;

}


#endif // T100ELEMENTCOMMON_H
