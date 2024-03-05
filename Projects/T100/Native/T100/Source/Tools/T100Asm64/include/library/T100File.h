#ifndef T100FILE_H
#define T100FILE_H

#include <fstream>
#include "T100Buffer.h"


class T100File
{
    public:
        T100File(T100STRING&);
        virtual ~T100File();

        T100BOOL            open();
        T100BOOL            close();

        T100BOOL            read(T100Buffer&);

    protected:

    private:
        T100STRING&         m_file;
        std::wfstream*      m_wfs           = T100NULL;
};

#endif // T100FILE_H
