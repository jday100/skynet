#ifndef T1003DRENDERERCOMMON_H
#define T1003DRENDERERCOMMON_H

#include <windows.h>
#include "T100Common.h"

typedef union{
    HWND            HWND;
}T1003DWindowHandle;

typedef enum{
    T1003D_HEAP_SMALL,
    T1003D_HEAP_MEDIUM,
    T1003D_HEAP_BIG,
    T1003D_HEAP_LARGE
}T1003D_HEAP_SIZE;

#endif // T1003DRENDERERCOMMON_H
