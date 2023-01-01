#ifndef T100DIAGRAMV1COMMON_H
#define T100DIAGRAMV1COMMON_H

#include "T100FileCommon.h"

namespace T100Painter{

typedef struct{
}T100DIAGRAM_V1_HEAD;

typedef struct{
    T100WORD                X;
    T100WORD                Y;
    T100FLOAT               RADIUS;
}T100DIAGRAM_V1_ELEMENT_CIRCLE;

}

#endif // T100DIAGRAMV1COMMON_H
