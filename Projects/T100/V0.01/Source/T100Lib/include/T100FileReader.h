#ifndef T100FILEREADER_H
#define T100FILEREADER_H

#include <atomic>
#include <fstream>
#include "T100Reader.h"


class T100FileReader : public T100Reader
{
    public:
        T100FileReader(T100WSTRING);
        virtual ~T100FileReader();

        T100BOOL                    open();
        T100BOOL                    close();
        T100BOOL                    opened();

        T100BOOL                    seek(T100DWORD);

        T100BOOL                    read(T100WORD*, T100WORD&);


    protected:
        T100WSTRING                 m_file;
        std::atomic_bool            m_opened;
        std::ifstream*              m_ifs           = T100NULL;

        std::atomic_llong           m_seek;

        T100VOID                    create();
        T100VOID                    destroy();

    private:
};

#endif // T100FILEREADER_H
