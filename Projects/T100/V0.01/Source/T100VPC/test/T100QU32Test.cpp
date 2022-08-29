#include "T100QU32Test.h"
#include "T100QU32.h"

#include "T100Display.h"
#include "T100Disk.h"
#include "T100Keyboard.h"
#include "T100Mouse.h"


T100WSTRING         T100QU32Test::m_name                    = L"vpc.qu32";


T100QU32Test::T100QU32Test(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100QU32Test::~T100QU32Test()
{
    //dtor
}

T100BOOL T100QU32Test::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_qu32();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100QU32Test::test_qu32()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100QU32            host;

    T100BYTE            display_id;
    T100BYTE            disk_id;
    T100BYTE            keyboard_id;
    T100BYTE            mouse_id;

    T100Display         display(&host);
    T100Disk            disk(&host);
    T100Keyboard        keyboard(&host);
    T100Mouse           mouse(&host);

    host.getPort32()->appendDevice(display_id, &display);

    host.getPort32()->appendDevice(disk_id, &disk);

    host.getPort32()->appendDevice(keyboard_id, &keyboard);

    host.getPort32()->appendDevice(mouse_id, &mouse);

    value = host.start();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = host.stop();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}
