#ifndef T100BINARYFILEREADER_H
#define T100BINARYFILEREADER_H

#include <fstream>
#include "T100File.h"
#include "T100FileReader.h"

class T100BinaryFileReader : public T100FileReader
{
    public:
        T100BinaryFileReader(T100File&);
        virtual ~T100BinaryFileReader();

        virtual T100BOOL            open();
        virtual T100BOOL            close();

        virtual T100BOOL            read(T100BYTE*, T100INTEGER&);

    protected:
        T100VOID                    create(T100File&);
        T100VOID                    destroy();

    private:
        std::ifstream*              m_stream        = T100NULL;
};

#endif // T100BINARYFILEREADER_H
