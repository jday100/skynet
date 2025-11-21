#ifndef T100BUFFEREDFILEREADER_H
#define T100BUFFEREDFILEREADER_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100BufferedFileReader
{
    public:
        T100BufferedFileReader(T100WSTRING&);
        virtual ~T100BufferedFileReader();

        T100BOOL                Open();
        T100BOOL                Close();
        T100BOOL                IsOpened();

        T100BOOL                Eof();

        T100BOOL                Seek(T100UINT64);

        T100BOOL                Read(T100BYTE*, T100UINT&);

    protected:
        T100WSTRING             m_path;
        std::atomic_bool        m_opened;
        std::ifstream*          m_ifs       = T100NULL;

        std::atomic_llong       m_seek;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100BUFFEREDFILEREADER_H
