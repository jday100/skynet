#ifndef T100DIAGRAMCOMMON_H
#define T100DIAGRAMCOMMON_H

#include "T100FileCommon.h"

typedef enum{
    T100DIAGRAM_COMMON          = 1,
    T100DIAGRAM_MAX
}T100DIAGRAM_TYPE;

typedef struct{
    T100FILE_HEAD               COMMON;
    T100WORD                    TYPE;
    T100WORD                    VERSION;
}T100DIAGRAM_HEAD;

typedef struct{
    T100WORD                    TYPE;
}T100ELEMENT;

#endif // T100DIAGRAMCOMMON_H
