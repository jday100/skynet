#ifndef T100IDECOMMON_H
#define T100IDECOMMON_H

#include "T100Common.h"


namespace T100IDE{

typedef enum{
    T100IDE_TYPE_NONE           = 0,
    //
    T100IDE_TYPE_DEFAULT,
    T100IDE_TYPE_EDITOR,
    T100IDE_TYPE_PAINTER,
    //
    T100IDE_TYPE_MAX
}T100IDE_TYPE;

}

#endif // T100IDECOMMON_H
