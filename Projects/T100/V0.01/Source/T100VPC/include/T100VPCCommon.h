#ifndef T100VPCCOMMON_H
#define T100VPCCOMMON_H

#include "T100Common.h"
#include "T100DeviceTypes.h"
class T100DeviceInfo;

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
    T100EXECUTOR_MODE_NEXT_CALL,
    T100EXECUTOR_MODE_NEXT_RETURN,
    T100EXECUTOR_MODE_RUN,
    T100EXECUTOR_MODE_MAX
}T100EXECUTOR_MODE;

#define     T100DEVICE_VECTOR               std::vector<T100Device*>
#define     T100DEVICE_BLOCK_VECTOR         std::vector<T100BlockDevice*>
#define     T100DEVICE_PAGE_VECTOR          std::vector<T100PageDevice*>
#define     T100DEVICE_HASH                 std::unordered_map<T100WORD, T100Device*>
#define     T100BLOCK_HASH                  std::unordered_map<T100WORD, T100DEVICE_BLOCK*>
#define     T100PAGE_HASH                   std::unordered_map<T100WORD, T100DEVICE_PAGE*>

#define     T100DEVICE_INFO_VECTOR          std::vector<T100DeviceInfo*>

#define     T100MEMORY_RAM_BASE             1024 * 1024 * 1024


#endif // T100VPCCOMMON_H
