#ifndef T100LOGGERNORMAL_H
#define T100LOGGERNORMAL_H

#include "log/T100LoggerBase.h"
#include "storage/file/text/T100TextFile.h"

namespace T100LIBRARY{

class T100LoggerNormal : public T100LoggerBase
{
    public:
        T100LoggerNormal();
        T100LoggerNormal(const T100WSTRING&);
        virtual ~T100LoggerNormal();

        virtual T100VOID            Out(const T100WSTRING&);

    protected:
        T100TextFile*               m_textFile      = T100NULL;
        T100TextFileWriterW*        m_writer        = T100NULL;

    private:
        T100VOID                    init(const T100WSTRING&);
        T100VOID                    uninit();
};

}

#endif // T100LOGGERNORMAL_H
