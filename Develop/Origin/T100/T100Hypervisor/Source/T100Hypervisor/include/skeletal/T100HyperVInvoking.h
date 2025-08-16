#ifndef T100HYPERVINVOKING_H
#define T100HYPERVINVOKING_H

#include "T100Common.h"
#include "T100HyperV.h"

using namespace T100LIBRARY;

class T100HyperVInvoking
{
    public:
        T100HyperVInvoking();
        virtual ~T100HyperVInvoking();

        static HRESULT CALLBACK         OnIoPortCallback(void*, WHV_EMULATOR_IO_ACCESS_INFO*);
        static HRESULT CALLBACK         OnMemoryCallback(void*, WHV_EMULATOR_MEMORY_ACCESS_INFO*);
        static HRESULT CALLBACK         OnGetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, WHV_REGISTER_VALUE*);
        static HRESULT CALLBACK         OnSetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, const WHV_REGISTER_VALUE*);
        static HRESULT CALLBACK         OnTranslateGvaPageCallback(void*, WHV_GUEST_VIRTUAL_ADDRESS, WHV_TRANSLATE_GVA_FLAGS, WHV_TRANSLATE_GVA_RESULT_CODE*, WHV_GUEST_PHYSICAL_ADDRESS*);

    protected:

    private:
};

#endif // T100HYPERVINVOKING_H
