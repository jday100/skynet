#ifndef T100TEXTFILEACCESSOR_H
#define T100TEXTFILEACCESSOR_H

#include "storage/file/T100FileAccessor.h"

namespace T100LIBRARY{

class T100TextFile;

class T100TextFileAccessor : public T100FileAccessor
{
    public:
        T100TextFileAccessor(const T100TextFile&);
        virtual ~T100TextFileAccessor();

        virtual T100VOID            SeekRead(T100UINT);
        virtual T100VOID            Read();

        virtual T100VOID            SeekWrite(T100UINT);
        virtual T100VOID            Write();

    protected:
        const T100TextFile&         m_textFile;
        std::fstream*               m_fstream       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100TEXTFILEACCESSOR_H
