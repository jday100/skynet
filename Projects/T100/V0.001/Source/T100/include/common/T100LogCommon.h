#ifndef T100LOGCOMMON_H
#define T100LOGCOMMON_H

#include "T100Common.h"
class T100LogAppender;


enum T100LOG_TYPE{
    T100LOG_TYPE_NONE       = 0,
    T100LOG_TYPE_FATAL,
    T100LOG_TYPE_ERROR,
    T100LOG_TYPE_WARN,
    T100LOG_TYPE_DEBUG,
    T100LOG_TYPE_TRACE,
    T100LOG_TYPE_INFO,
    T100LOG_TYPE_ALL,
    T100LOG_TYPE_MAX
};


#define     T100LOG_QUEUE                   std::queue<T100STDSTRING>

#define     T100LOG_APPENDER_VECTOR         std::vector<T100LogAppender*>

typedef     void(*T100LOG_CALLBACK)(void*);
#define     T100LOG_CALLBACK_VECTOR         std::vector<T100LOG_CALLBACK>


#endif // T100LOGCOMMON_H
