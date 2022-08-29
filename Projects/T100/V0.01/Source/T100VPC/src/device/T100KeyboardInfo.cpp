#include "T100KeyboardInfo.h"

T100KeyboardInfo::T100KeyboardInfo()
{
    //ctor
    create();
}

T100KeyboardInfo::~T100KeyboardInfo()
{
    //dtor
    destroy();
}

T100VOID T100KeyboardInfo::create()
{
    name = L"Keyboard";
    type = T100DEVICE_KEYBOARD;
}

T100VOID T100KeyboardInfo::destroy()
{

}
