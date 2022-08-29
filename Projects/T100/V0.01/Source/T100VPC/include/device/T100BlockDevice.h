#ifndef T100BLOCKDEVICE_H
#define T100BLOCKDEVICE_H

#include "T100Device.h"


class T100BlockDevice : public T100Device
{
    public:
        T100BlockDevice(T100QU32*);
        virtual ~T100BlockDevice();

        virtual T100BOOL            load(T100Port32*);
        virtual T100BOOL            unload();

        virtual T100BOOL            in(T100WORD, T100WORD&);
        virtual T100BOOL            out(T100WORD, T100WORD);

    protected:
        T100WORD_VECTOR             m_blocks;

    private:

};

#endif // T100BLOCKDEVICE_H
