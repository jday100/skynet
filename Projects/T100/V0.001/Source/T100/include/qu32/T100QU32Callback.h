#ifndef T100QU32CALLBACK_H
#define T100QU32CALLBACK_H

#include "T100Callback.h"


class T100QU32Callback
{
    public:
        T100QU32Callback();
        virtual ~T100QU32Callback();

        static T100BOOL             bindStart(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindStart(T100CALLBACK_HANDLE);
        static T100BOOL             bindStop(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindStop(T100CALLBACK_HANDLE);
        static T100BOOL             bindDone(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDone(T100CALLBACK_HANDLE);
        static T100BOOL             bindHangup();
        static T100BOOL             bindAwaken();
        //
        static T100BOOL             bindStep();
        //
        static T100BOOL             bindDebug(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebug(T100CALLBACK_HANDLE);
        static T100BOOL             bindDebugRom(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebugRom(T100CALLBACK_HANDLE);
        static T100BOOL             bindDebugRam(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebugRam(T100CALLBACK_HANDLE);
        //
        static T100BOOL             bindDebugDevice(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebugDevice(T100CALLBACK_HANDLE);
        static T100BOOL             bindDebugBlock(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebugBlock(T100CALLBACK_HANDLE);
        static T100BOOL             bindDebugPage(T100CALLBACK_HANDLE, void*, void*, void*);
        static T100BOOL             unbindDebugPage(T100CALLBACK_HANDLE);

        static T100BOOL             callStart();
        static T100BOOL             callStop();
        static T100BOOL             callDone();
        static T100BOOL             callHangup();
        static T100BOOL             callAwaken();
        //
        static T100BOOL             callStep();
        //
        static T100BOOL             callDebug();
        static T100BOOL             callDebugRom();
        static T100BOOL             callDebugRam();
        //
        static T100BOOL             callDebugDevice();
        static T100BOOL             callDebugBlock();
        static T100BOOL             callDebugPage();

    protected:

    private:
        static T100Callback         m_start;
        static T100Callback         m_stop;
        static T100Callback         m_done;
        //static T100Callback        m_quit;
        static T100Callback         m_hangup;
        static T100Callback         m_awaken;
        //
        static T100Callback         m_step;
        //
        static T100Callback         m_debug;
        static T100Callback         m_debug_rom;
        static T100Callback         m_debug_ram;
        //
        static T100Callback         m_debug_device;
        static T100Callback         m_debug_block;
        static T100Callback         m_debug_page;

};

#endif // T100QU32CALLBACK_H
