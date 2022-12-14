#ifndef T100KEYBOARD_H
#define T100KEYBOARD_H

#include "T100Device.h"

namespace T100VPC{

typedef enum{
    T100KEYBOARDMODE_NONE           = T100Component::T100DEVICEMODE_MAX,
    T100KEYBOARDMODE_TYPE,
    T100KEYBOARDMODE_SET,
    T100KEYBOARDMODE_GET,
    T100KEYBOARDMODE_READ,
    T100KEYBOARDMODE_MAX
}T100KEYBOARD_MODE;

class T100Keyboard : public T100QU32::T100Device
{
    public:
        T100Keyboard(T100QU32::T100QU32*);
        virtual ~T100Keyboard();

        T100BOOL            load(T100QU32::T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

}

#endif // T100KEYBOARD_H
