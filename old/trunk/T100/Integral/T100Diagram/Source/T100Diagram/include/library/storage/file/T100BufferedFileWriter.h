#ifndef T100BUFFEREDFILEWRITER_H
#define T100BUFFEREDFILEWRITER_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100BufferedFileWriter
{
    public:
        T100BufferedFileWriter(T100WSTRING&);
        virtual ~T100BufferedFileWriter();

        T100BOOL                Open();
        T100BOOL                Close();
        T100BOOL                IsOpened();

        T100BOOL                Eof();

        T100BOOL                Seek(T100UINT64);

        T100BOOL                Write(T100BYTE*, T100UINT);

    protected:
        T100WSTRING             m_path;
        std::atomic_bool        m_opened;
        std::ofstream*          m_ofs       = T100NULL;

        std::atomic_llong       m_seek;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100BUFFEREDFILEWRITER_H
