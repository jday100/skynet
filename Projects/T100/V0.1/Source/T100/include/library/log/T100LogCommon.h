#ifndef T100LOGCOMMON_H
#define T100LOGCOMMON_H

#include "T100Class.h"
#include "T100Common.h"
#include "T100DataStructure.h"

#define         T100LOG_QUEUE                       std::queue<T100WSTRING>

#define         T100LOG_VECTOR                      std::vector<T100LogBase*>

namespace T100Library{
class T100LogBase;

typedef enum{
    T100LOG_TYPE_NONE           = 0,
    T100LOG_TYPE_OFF,
    T100LOG_TYPE_FATAL,
    T100LOG_TYPE_ERROR,
    T100LOG_TYPE_WARN,
    T100LOG_TYPE_INFO,
    T100LOG_TYPE_DEBUG,
    T100LOG_TYPE_TRACE,
    T100LOG_TYPE_ALL,
    T100LOG_TYPE_MAX
}T100LOG_TYPE;

}

#endif // T100LOGCOMMON_H
