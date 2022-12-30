#ifndef T100DIAGRAMV1COMMON_H
#define T100DIAGRAMV1COMMON_H

#include "T100FileCommon.h"

namespace T100Painter{

typedef struct{
    T100FILE_HEAD           COMMON;
}T100DIAGRAM_V1_HEAD;

typedef struct{
    T100WORD                TYPE;
}T100DIAGRAM_V1_ELEMENT;

typedef struct{
    T100WORD                RADIUS;
}T100DIAGRAM_V1_ELEMENT_CIRCLE;

}

#endif // T100DIAGRAMV1COMMON_H
