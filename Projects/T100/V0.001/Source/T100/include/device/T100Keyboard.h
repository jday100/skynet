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
        T100Keyboard();
        virtual ~T100Keyboard();

        T100VOID                key(T100WORD);

        T100WORD                in(T100WORD);
        T100VOID                out(T100WORD, T100WORD);

    protected:
        T100BOOL                read();

    private:
        T100WORD_QUEUE          m_keys;
};

#endif // T100KEYBOARD_H
