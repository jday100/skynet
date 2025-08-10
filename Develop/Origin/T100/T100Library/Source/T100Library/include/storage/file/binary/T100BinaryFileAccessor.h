#ifndef T100BINARYFILEACCESSOR_H
#define T100BINARYFILEACCESSOR_H

#include "storage/file/T100FileAccessor.h"

namespace T100LIBRARY{

class T100BinaryFile;

class T100BinaryFileAccessor : public T100FileAccessor
{
    public:
        T100BinaryFileAccessor(const T100BinaryFile&);
        virtual ~T100BinaryFileAccessor();

        virtual T100VOID            SeekRead(T100UINT);
        virtual T100VOID            Read();

        virtual T100VOID            SeekWrite(T100UINT);
        virtual T100VOID            Write();

    protected:
        const T100BinaryFile&       m_binaryFile;
        std::fstream*               m_fstream       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100BINARYFILEACCESSOR_H
