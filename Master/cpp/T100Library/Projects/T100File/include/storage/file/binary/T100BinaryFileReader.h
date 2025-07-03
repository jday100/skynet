#ifndef T100BINARYFILEREADER_H
#define T100BINARYFILEREADER_H

#include "storage/file/T100FileReader.h"

namespace T100LIBRARY{

class T100BinaryFile;

class T100BinaryFileReader : public T100FileReader
{
    public:
        T100BinaryFileReader(const T100BinaryFile&);
        virtual ~T100BinaryFileReader();

        virtual T100VOID            Seek(T100UINT);
        virtual T100INT             Read(T100BYTE*, T100INT);

    protected:
        const T100BinaryFile&       m_binaryFile;
        std::ifstream*              m_ifstream      = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100BINARYFILEREADER_H
