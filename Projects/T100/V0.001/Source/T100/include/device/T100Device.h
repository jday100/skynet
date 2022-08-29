#ifndef T100DEVICE_H
#define T100DEVICE_H

#include "T100VPCCommon.h"
#include "T100DeviceTypes.h"
#include "IDevice.h"
class IManager;
class T100Manager32;


#define     T100DEVICE_VECTOR       std::vector<IDevice*>
#define     T100BLOCK_HASH          std::unordered_map<T100WORD, T100DEVICE_BLOCK*>
#define     T100PAGE_HASH           std::unordered_map<T100WORD, T100DEVICE_PAGE*>


class T100Device : public IDevice
{
    public:
        T100Device();
        virtual ~T100Device();

        virtual T100Manager32*      getManager32();

        virtual T100BOOL            load(IManager*);
        virtual T100BOOL            unload();

        virtual T100WORD            in(T100WORD);
        virtual T100VOID            out(T100WORD, T100WORD);

    protected:
        T100WORD                    m_data[4];

    private:
        T100WORD                    m_size          = 4;
};

#endif // T100DEVICE_H
