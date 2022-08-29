#ifndef T100BLOCKDEVICE_H
#define T100BLOCKDEVICE_H

#include "IBlockDevice.h"
class T100Manager32;


class T100BlockDevice : public IBlockDevice
{
    public:
        T100BlockDevice();
        virtual ~T100BlockDevice();

        T100Manager32*      getManager32();

        virtual T100BOOL    load(IManager*);

        virtual bool        load(T100Manager32*);
        virtual bool        unload();

        virtual T100WORD    in(T100WORD, T100WORD);
        virtual void        out(T100WORD, T100WORD, T100WORD);

    protected:
        T100WORD_VECTOR     m_block;

    private:
};

#endif // T100BLOCKDEVICE_H
