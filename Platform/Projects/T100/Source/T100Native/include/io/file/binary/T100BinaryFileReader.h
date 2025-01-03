#ifndef T100BINARYFILEREADER_H
#define T100BINARYFILEREADER_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100BinaryFileReader
{
    public:
        T100BinaryFileReader();
        virtual ~T100BinaryFileReader();

        T100BOOL                open(T100WString);
        T100BOOL                close();

        T100BOOL                read(T100BYTE*, T100WORD&);

        T100BOOL                opened();
        T100BOOL                eof();
        T100BOOL                seek(T100DWORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WString             m_filename;
        std::atomic_bool        m_opened;
        std::atomic_llong       m_seek;

        std::ifstream*          m_stream            = T100NULL;
};

#endif // T100BINARYFILEREADER_H
