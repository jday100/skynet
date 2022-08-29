#ifndef T100PAGEDEVICE_H
#define T100PAGEDEVICE_H

#include "T100Device.h"


class T100PageDevice : public T100Device
{
    public:
        T100PageDevice(T100QU32*);
        virtual ~T100PageDevice();

        virtual T100BOOL            load(T100Port32*);
        virtual T100BOOL            unload();

        virtual T100BOOL            in(T100WORD, T100WORD&);
        virtual T100BOOL            out(T100WORD, T100WORD);

    protected:

    private:
};

#endif // T100PAGEDEVICE_H
