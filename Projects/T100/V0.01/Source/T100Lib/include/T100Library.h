#ifndef T100LIBRARY_H
#define T100LIBRARY_H

#include "T100File.h"


class T100Library : public T100File
{
    public:
        T100Library(T100WSTRING);
        virtual ~T100Library();

        T100BOOL            load();

        T100VOID*           getMethod(T100WSTRING);

        T100BOOL            unload();

    protected:

    private:
        T100VOID*           m_handle            = T100NULL;

};

#endif // T100LIBRARY_H
