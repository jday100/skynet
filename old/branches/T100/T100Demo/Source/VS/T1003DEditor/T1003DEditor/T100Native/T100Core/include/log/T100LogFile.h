#ifndef T100LOGFILE_H
#define T100LOGFILE_H

#include "common/T100LogCommon.h"
#include "log/T100LogBase.h"
#include "file/T100TextFileWriter.h"

namespace T100NATIVE{

class T100LogFile : public T100LogBase
{
    public:
        T100LogFile(T100WSTRING);
        virtual ~T100LogFile();

        T100VOID                Outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE);

    protected:
        T100WSTRING             m_file;
        T100TextFileWriter*     m_writerPtr         = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

}

#endif // T100LOGFILE_H
