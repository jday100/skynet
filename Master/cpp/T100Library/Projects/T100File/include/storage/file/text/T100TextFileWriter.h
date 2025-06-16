#ifndef T100TEXTFILEWRITER_H
#define T100TEXTFILEWRITER_H

#include "storage/file/T100FileWriter.h"

namespace T100LIBRARY{

class T100TextFile;

class T100TextFileWriter : public T100FileWriter
{
    public:
        T100TextFileWriter(const T100TextFile&);
        virtual ~T100TextFileWriter();

        virtual T100VOID            Seek(T100UINT);
        virtual T100VOID            Write();

    protected:
        const T100TextFile&         m_textFile;
        std::ofstream*              m_ofstream      = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100TEXTFILEWRITER_H
