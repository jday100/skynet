#ifndef T100BINARYFILEWRITER_H
#define T100BINARYFILEWRITER_H

#include "storage/file/T100FileWriter.h"

namespace T100LIBRARY{

class T100BinaryFile;

class T100BinaryFileWriter : public T100FileWriter
{
    public:
        T100BinaryFileWriter(const T100BinaryFile&);
        virtual ~T100BinaryFileWriter();

        virtual T100VOID            Seek(T100UINT);
        virtual T100VOID            Write(T100BYTE*, T100UINT);

    protected:
        const T100BinaryFile&       m_binaryFile;
        std::ofstream*              m_ofstream      = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100BINARYFILEWRITER_H
