#ifndef T100FILE_H
#define T100FILE_H

#include "T100DirectoryEntry.h"

namespace T100Library{
class T100FileReader;
class T100FileWriter;
class T100FileStream;


class T100File : public T100DirectoryEntry
{
    public:
        T100File(T100WSTRING);
        virtual ~T100File();

        virtual T100BOOL            create();
        virtual T100BOOL            remove();

        virtual T100DWORD           length();

        T100FileReader*             getReader();
        T100FileWriter*             getWriter();
        T100FileStream*             getStream();

    protected:
        T100DWORD                   m_length            = 0;

    private:
};

}

#endif // T100FILE_H
