#ifndef T100VPCCOMMON_H
#define T100VPCCOMMON_H

#include "T100Common.h"
#include "T100DeviceTypes.h"
class T100DeviceInfo;


#define     T100DEVICE_VECTOR           std::vector<T100Device*>
#define     T100BLOCK_HASH              std::unordered_map<T100WORD, T100DEVICE_BLOCK*>
#define     T100PAGE_HASH               std::unordered_map<T100WORD, T100DEVICE_PAGE*>

#define     T100DEVICE_INFO_VECTOR      std::vector<T100DeviceInfo*>


#endif // T100VPCCOMMON_H
