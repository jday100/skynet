#ifndef T100VPCINVOKING_H
#define T100VPCINVOKING_H

#include "T100Common.h"
#include "T100Host.h"

using namespace T100LIBRARY;

class T100VPCFrame;

class T100VPCInvoking
{
    public:
        T100VPCInvoking();
        virtual ~T100VPCInvoking();

        static T100VOID             Init(T100VPCFrame*);
        static T100VOID             Uninit();

        static T100VOID             OnStart();
        static T100VOID             OnStop();

        static HRESULT CALLBACK     OnIoPortCallback(void*, WHV_EMULATOR_IO_ACCESS_INFO*);
        static HRESULT CALLBACK     OnMemoryCallback(void*, WHV_EMULATOR_MEMORY_ACCESS_INFO*);
        static HRESULT CALLBACK     OnGetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, WHV_REGISTER_VALUE*);
        static HRESULT CALLBACK     OnSetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, const WHV_REGISTER_VALUE*);
        static HRESULT CALLBACK     OnTranslateGvaPageCallback(void*, WHV_GUEST_VIRTUAL_ADDRESS, WHV_TRANSLATE_GVA_FLAGS, WHV_TRANSLATE_GVA_RESULT_CODE*, WHV_GUEST_PHYSICAL_ADDRESS*);

    protected:
        static T100VPCFrame*        m_frame;
        static T100Host*            m_host;

    private:
};

#endif // T100VPCINVOKING_H
