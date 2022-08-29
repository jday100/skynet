#ifndef T100FILEWRITER_H
#define T100FILEWRITER_H

#include <atomic>
#include <fstream>
#include "T100Writer.h"


class T100FileWriter : public T100Writer
{
    public:
        T100FileWriter(T100WSTRING);
        virtual ~T100FileWriter();

        T100BOOL                    open();
        T100BOOL                    close();
        T100BOOL                    opened();

        T100BOOL                    seek(T100DWORD);

        T100BOOL                    write(T100WORD*, T100WORD);

    protected:
        T100WSTRING                 m_file;
        std::atomic_bool            m_opened;
        std::ofstream*              m_ofs               = T100NULL;

        std::atomic_llong           m_seek;

        T100VOID                    create();
        T100VOID                    destroy();

    private:

};

#endif // T100FILEWRITER_H
