#ifndef T100CALLBACKCOMMON_H
#define T100CALLBACKCOMMON_H

#include "T100Common.h"

typedef     T100BOOL (*T100CALLBACK_HANDLE)(void*, void*, void*, void*, void*);

typedef struct{
    void*                   OBJECT;
    void*                   VALUE;
    T100CALLBACK_HANDLE     HANDLE;
}T100CALLBACK_ENTRY;


#define     T100CALLBACK_VECTOR         std::vector<T100CALLBACK_ENTRY*>


#endif // T100CALLBACKCOMMON_H
