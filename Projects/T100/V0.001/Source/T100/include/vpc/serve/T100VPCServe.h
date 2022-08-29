#ifndef T100VPCSERVE_H
#define T100VPCSERVE_H

#include "IServe.h"
#include "T100VPCCommon.h"
#include "T100Qu32.h"
#include "T100Display.h"
class T100VPCView;


class T100VPCServe : public IServe
{
    public:
        T100VPCServe();
        virtual ~T100VPCServe();

        T100BOOL            quit();

        T100BOOL            create(T100VPCView*, void*);
        T100BOOL            setFile(T100STDSTRING);
        T100BOOL            setOffset(T100WORD);

        T100BOOL            run();
        T100BOOL            start();
        T100BOOL            stop();
        //
        T100VOID            pause();
        T100VOID            next();
        T100VOID            step();
        T100VOID            resume();

        T100VOID            wait();
        T100BOOL            running();

        T100QU32*           getHost();
        T100WORD*           getScreen();
        T100WORD            getReturn();

        T100BOOL            bind(T100VPCView*, T100VPCServe*, void*);
        T100BOOL            unbind();
        T100BOOL            clear();
        T100BOOL            load(T100WORD_VECTOR&, T100DWORD);

    protected:
        T100BOOL            destroy();

        T100BOOL            bind(T100VPCView*, void*);

        static T100BOOL     stop_callback(void*, void*, void*, void*);

    private:
        T100QU32*           m_host          = T100NULL;
        T100Display*        m_display       = T100NULL;

        T100BYTE            m_disk_id;
        T100BYTE            m_display_id    = 0;
        T100BYTE            m_keyboard_id;
        T100BYTE            m_mouse_id;

        T100BOOL            m_running               = T100FALSE;
        T100BOOL            m_rom_load_default      = T100TRUE;
        T100STDSTRING       m_file;
        T100WORD            m_offset                = 0;

        T100BOOL            m_exit                  = T100FALSE;

        T100WORD            m_return                = 0;

};

#endif // T100VPCSERVE_H
