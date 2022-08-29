#include "T100VPCServe.h"

#include "T100Disk.h"
#include "T100Display.h"
#include "T100Keyboard.h"
#include "T100Mouse.h"
#include "T100VPCSetup.h"
#include "T100VPCCallbackNew.h"
#include "T100VPCView.h"

#include "T100QU32Setup.h"
#include "T100QU32Callback.h"


T100VPCServe::T100VPCServe()
{
    //ctor
}

T100VPCServe::~T100VPCServe()
{
    //dtor
}

/*
T100VOID T100VPCServe::create()
{
    T100Log::trace(T100VPC_HINT_SERVE_START);

    m_host          = T100NEW T100QU32;

    ///*
    T100String      file(T100VPCSetup::getVDiskFile());
    T100Disk*       disk        = T100NEW T100Disk(file);
    T100Keyboard*   keyboard    = T100NEW T100Keyboard();
    T100Mouse*      mouse       = T100NEW T100Mouse();

    m_display       = T100NEW T100Display(T100VPCSetup::getFontFile());

    m_host->getManager32()->addDevice(m_disk_id, disk);
    m_host->getManager32()->addDevice(m_display_id, m_display);
    m_host->getManager32()->addDevice(m_keyboard_id, keyboard);
    m_host->getManager32()->addDevice(m_mouse_id, mouse);
    //* /
}
*/

T100BOOL T100VPCServe::create(T100VPCView* view, void* data)
{
    T100Log::trace(T100VPC_HINT_SERVE_START);

    T100BOOL    result;

    if(m_running || m_host){
        return T100FALSE;
    }

    m_host  = T100NEW T100QU32;
    if(!m_host){
        return T100FALSE;
    }

    if(m_host){
        //m_host->bind(T100VPCCallback::callback_stop, view, serve, data);
    }else{
        return T100FALSE;
    }

    m_display   = T100NEW T100Display(T100VPCSetup::getFontFile());
    if(!m_display || !m_display->isInited()){
        T100DELETE(m_host);
        m_host = T100NULL;
        return T100FALSE;
    }

    result = m_host->getManager32()->addDevice(m_display_id, m_display);


    if(result){
        T100Disk* disk = T100NEW T100Disk(T100VPCSetup::getVDiskFile());
        if(!disk || !disk->isInited()){
            T100DELETE(m_host);
            m_host = T100NULL;
            return T100FALSE;
        }

        result = m_host->getManager32()->addDevice(m_disk_id, disk);
    }

    if(result){
        if(!bind(view, data)){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100VPCServe::bind(T100VPCView* view, T100VPCServe* serve, void* data)
{
    return T100TRUE;
}

T100BOOL T100VPCServe::destroy()
{
    T100DELETE(m_host);
    m_host = T100NULL;

    T100Log::trace(T100VPC_HINT_SERVE_STOP);

    return T100TRUE;
}

T100BOOL T100VPCServe::run()
{
    if(m_running || !m_host){
        return T100FALSE;
    }

    return start();
}

T100BOOL T100VPCServe::start()
{
    T100BOOL    value;

    if(m_running || !m_host){
        return T100FALSE;
    }

    T100Log::info("starting...");

    if(!m_host->getMemory32()){
        T100Log::info("Host error!");
    }

    if(m_rom_load_default){
        T100STRING   file;

        if(m_file.empty()){
            file        = T100String(T100VPCSetup::getRomFile());
            m_offset    = 0;
        }else{
            file        = m_file;
        }

        value = m_host->getMemory32()->load(file, m_offset);
        if(!value){
            return T100FALSE;
        }
    }

    T100Log::info("starting...");

    if(m_host->start()){
        m_running = T100TRUE;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VPCServe::stop()
{
    if(m_host){
        m_host->stop();
        return destroy();
    }
    return T100FALSE;
}

T100BOOL T100VPCServe::running()
{
    if(m_host){
        return m_host->isRunning();
    }
    return T100FALSE;
}

T100VOID T100VPCServe::wait()
{
    if(m_host){
        m_host->wait();
    }
}

T100VOID T100VPCServe::resume()
{
    if(m_host){
        m_host->resume();
    }
}

T100VOID T100VPCServe::pause()
{
    if(m_host){
        m_host->pause();
    }
}

T100VOID T100VPCServe::step()
{
    if(m_host){
        m_host->step();
    }
}

T100VOID T100VPCServe::next()
{
    if(m_host){
        m_host->next();
    }
}

T100QU32* T100VPCServe::getHost()
{
    return m_host;
}

T100WORD* T100VPCServe::getScreen()
{
    if(!m_running){
        return T100NULL;
    }

    if(0 == m_display_id){
        return T100NULL;
    }

    return m_display->getScreen();
}

T100BOOL T100VPCServe::load(T100WORD_VECTOR& app, T100DWORD offset)
{
    T100BOOL    value;

    if(m_running || !m_host){
        return T100FALSE;
    }

    value = m_host->getMemory32()->load(app, offset);
    if(value){
        m_rom_load_default = T100FALSE;
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VPCServe::setFile(T100STDSTRING file)
{
    T100QU32Setup::m_file   = file;
    m_file = file;
    return T100TRUE;
}

T100BOOL T100VPCServe::setOffset(T100WORD offset)
{
    T100QU32Setup::m_base   = T100TRUE;
    T100QU32Setup::m_offset = offset;
    m_offset = offset;
    return T100TRUE;
}

T100WORD T100VPCServe::getReturn()
{
    if(m_host){
        return T100QU32Setup::m_return;
    }

    return m_return;
}

T100BOOL T100VPCServe::quit()
{
    stop();
    wait();
    return T100TRUE;
}

T100BOOL T100VPCServe::stop_callback(void* v, void* s, void* t, void* d)
{
    if(s){
        T100VPCServe* serve = (T100VPCServe*)s;
        if(serve){
            serve->m_return = serve->getReturn();
        }
    }

    if(v){
        //T100VPCView* view = dynamic_cast<T100VPCView*>(v);
        T100VPCView* view = (T100VPCView*)v;
        if(view){
            view->quit();
        }
    }
    return T100FALSE;
}

T100BOOL T100VPCServe::bind(T100VPCView* view, void* data)
{
    T100BOOL        result          = T100TRUE;
    T100VPCServe*   serve;

    serve   = this;
    data    = view->getFrame();


    result = T100QU32Callback::bindStart(&T100VPCCallback::callback_start, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindStop(&T100VPCCallback::callback_stop, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDone(&T100VPCCallback::callback_done, view, serve, data);
    if(!result)return T100FALSE;


    result = T100QU32Callback::bindDebug(&T100VPCCallback::callback_debug, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDebugRom(&T100VPCCallback::callback_debug_rom_base_update, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDebugRam(&T100VPCCallback::callback_debug_ram_base_update, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDebugDevice(&T100VPCCallback::callback_debug_device_update, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDebugBlock(&T100VPCCallback::callback_debug_block_update, view, serve, data);
    if(!result)return T100FALSE;

    result = T100QU32Callback::bindDebugPage(&T100VPCCallback::callback_debug_page_update, view, serve, data);
    if(!result)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100VPCServe::unbind()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = T100QU32Callback::unbindStart(&T100VPCCallback::callback_start);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindStop(&T100VPCCallback::callback_stop);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDone(&T100VPCCallback::callback_done);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebug(&T100VPCCallback::callback_debug);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebugRom(&T100VPCCallback::callback_debug_rom_base_update);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebugRam(&T100VPCCallback::callback_debug_ram_base_update);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebugDevice(&T100VPCCallback::callback_debug_device_update);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebugBlock(&T100VPCCallback::callback_debug_block_update);
    if(!value){
        result = T100FALSE;
    }

    value = T100QU32Callback::unbindDebugPage(&T100VPCCallback::callback_debug_page_update);
    if(!value){
        result = T100FALSE;
    }

    return result;
}
