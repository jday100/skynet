#ifndef T100LOGFILE_H
#define T100LOGFILE_H

#include "T100LogCommon.h"
#include "T100LogBase.h"
#include "T100TextFileWriter.h"


namespace T100Library{

class T100LogFile : public T100LogBase
{
    public:
        T100LogFile(T100WSTRING);
        virtual ~T100LogFile();

        T100VOID                outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WSTRING             m_file;
        T100TextFileWriter*     m_writer            = T100NULL;

};

}

#endif // T100LOGFILE_H
