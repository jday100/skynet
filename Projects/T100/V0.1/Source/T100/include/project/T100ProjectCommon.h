#ifndef T100PROJECTCOMMON_H
#define T100PROJECTCOMMON_H

#include "T100Common.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"

namespace T100PROJECT{

typedef enum{
    T100PROJECT_STATE_NONE          = 0,
    T100PROJECT_STATE_ALONE,
    T100PROJECT_STATE_EMBED,
    T100PROJECT_STATE_MAX
}T100PROJECT_STATE;

typedef enum{
    T100PROJECT_TYPE_NONE           = 0,
    T100PROJECT_TYPE_EMPTY,
    T100PROJECT_TYPE_C,
    T100PROJECT_TYPE_CPP,
    T100PROJECT_TYPE_NODEJS,
    T100PROJECT_TYPE_MAX
}T100PROJECT_TYPE;

}

#endif // T100PROJECTCOMMON_H
