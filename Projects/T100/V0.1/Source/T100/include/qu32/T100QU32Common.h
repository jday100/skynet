#ifndef T100QU32COMMON_H
#define T100QU32COMMON_H

#include "T100Common.h"
#include "T100DeviceTypes.h"
#include "T100String.h"


namespace T100QU32{
    class T100T100Device;
}

#define     T100GDT_VECTOR                      std::vector<T100GDT_ITEM*>

#define     T100PRELOAD_VECTOR                  std::vector<T100PRELOAD_ITEM*>

#define     T100DEVICE_VECTOR                   std::vector<T100Device*>
#define     T100DEVICE_BLOCK_VECTOR             std::vector<T100BlockDevice*>
#define     T100DEVICE_PAGE_VECTOR              std::vector<T100PageDevice*>

#define     T100DEVICE_HASH                     std::unordered_map<T100WORD, T100Device*>
#define     T100DEVICE_BLOCK_HASH               std::unordered_map<T100WORD, T100Component::T100DEVICE_BLOCK*>
#define     T100DEVICE_PAGE_HASH                std::unordered_map<T100WORD, T100Component::T100DEVICE_PAGE*>

#define     T100MEMORY_RAM_BASE                 1024 * 1024 * 1024

namespace T100QU32{

typedef enum{
    T100EXECUTOR_STATE_NONE         = 1,
    T100EXECUTOR_STATE_STOP,
    T100EXECUTOR_STATE_RUNNING,
    T100EXECUTOR_STATE_PAUSE,
    T100EXECUTOR_STATE_MAX
}T100EXECUTOR_STATE;

typedef enum{
    T100EXECUTOR_MODE_NONE          = 1,
    T100EXECUTOR_MODE_STEP,
    T100EXECUTOR_MODE_NEXT,
    T100EXECUTOR_MODE_NEXT_COMMENT,
    T100EXECUTOR_MODE_NEXT_CALL,
    T100EXECUTOR_MODE_NEXT_RETURN,
    T100EXECUTOR_MODE_RUN,
    T100EXECUTOR_MODE_MAX
}T100EXECUTOR_MODE;

typedef struct{
    T100STRING          FILE;
    T100WORD            OFFSET;
    T100WORD            LENGTH;
    T100BOOL            ISRUN;
}T100PRELOAD_ITEM;

typedef struct{
    T100WORD            OFFSET;
    T100WORD            VALUE;
}T100GDT_ITEM;

}


#endif // T100QU32COMMON_H
