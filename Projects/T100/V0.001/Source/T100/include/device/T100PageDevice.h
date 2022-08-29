#ifndef T100PAGEDEVICE_H
#define T100PAGEDEVICE_H

#include "IPageDevice.h"
class T100Manager32;


class T100PageDevice : public IPageDevice
{
    public:
        T100PageDevice();
        virtual ~T100PageDevice();

        virtual T100BOOL        load(T100Manager32*);
        virtual T100BOOL        unload();

        T100WORD                in(T100WORD, T100WORD);
        T100VOID                out(T100WORD, T100WORD, T100WORD);

    protected:
        T100WORD_VECTOR         m_page;

    private:
};

#endif // T100PAGEDEVICE_H
