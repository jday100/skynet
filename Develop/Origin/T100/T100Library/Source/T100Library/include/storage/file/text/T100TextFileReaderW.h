#ifndef T100TEXTFILEREADERW_H
#define T100TEXTFILEREADERW_H

#include "storage/file/T100FileReader.h"

namespace T100LIBRARY{

class T100TextFile;

class T100TextFileReaderW : public T100FileReader
{
    public:
        T100TextFileReaderW(const T100TextFile&);
        virtual ~T100TextFileReaderW();

        virtual T100VOID            Seek(T100UINT);

        virtual T100VOID            Load(T100WSTRING&);

        std::wifstream& operator>>(T100WSTRING&);

    protected:
        const T100TextFile&         m_textFile;
        std::wifstream*             m_wifstream     = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100TEXTFILEREADERW_H
