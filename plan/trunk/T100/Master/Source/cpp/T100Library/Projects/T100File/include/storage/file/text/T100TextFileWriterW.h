#ifndef T100TEXTFILEWRITERW_H
#define T100TEXTFILEWRITERW_H

#include "storage/file/T100FileWriter.h"

namespace T100LIBRARY{

class T100TextFile;

class T100TextFileWriterW : public T100FileWriter
{
    public:
        T100TextFileWriterW(const T100TextFile&);
        virtual ~T100TextFileWriterW();

        virtual T100VOID            Seek(T100UINT);

        std::wofstream& operator<<(const T100WSTRING&);

    protected:
        const T100TextFile&         m_textFile;
        std::wofstream*             m_wofstream         = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100TEXTFILEWRITERW_H
