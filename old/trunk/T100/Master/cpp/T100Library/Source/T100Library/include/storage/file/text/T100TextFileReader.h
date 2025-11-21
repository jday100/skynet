#ifndef T100TEXTFILEREADER_H
#define T100TEXTFILEREADER_H

#include "storage/file/T100FileReader.h"

namespace T100LIBRARY{

class T100TextFile;

class T100TextFileReader : public T100FileReader
{
    public:
        T100TextFileReader(const T100TextFile&);
        virtual ~T100TextFileReader();

        virtual T100VOID            Seek(T100UINT);
        virtual T100INT             Read(T100WSTRING&);
        virtual T100VOID            Load(T100WSTRING&);

    protected:
        const T100TextFile&         m_textFile;
        std::ifstream*              m_ifstream      = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100TEXTFILEREADER_H
