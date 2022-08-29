#ifndef T100KEYBOARD_H
#define T100KEYBOARD_H

#include "T100Device.h"

enum T100KEYBOARD_MODE{
    T100KEYBOARDMODE_NONE           = T100DEVICEMODE_MAX,
    T100KEYBOARDMODE_TYPE,
    T100KEYBOARDMODE_SET,
    T100KEYBOARDMODE_GET,
    T100KEYBOARDMODE_READ,
    T100KEYBOARDMODE_MAX
};


class T100Keyboard : public T100Device
{
    public:
        T100Keyboard(T100QU32*);
        virtual ~T100Keyboard();

        T100BOOL            load(T100Port32*);
        T100BOOL            unload();

        T100BOOL            in(T100WORD, T100WORD&);
        T100BOOL            out(T100WORD, T100WORD);

    protected:

    private:
};

#endif // T100KEYBOARD_H
