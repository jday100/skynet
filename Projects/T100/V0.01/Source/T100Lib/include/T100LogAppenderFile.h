#ifndef T100LOGAPPENDERFILE_H
#define T100LOGAPPENDERFILE_H

#include "T100LogAppender.h"
#include "T100TextFileWriter.h"


class T100LogAppenderFile : public T100LogAppender
{
    public:
        T100LogAppenderFile(T100WSTRING);
        virtual ~T100LogAppenderFile();

        T100VOID                outline(T100WORD, T100WSTRING);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WSTRING             m_file;
        T100TextFileWriter*     m_writer        = T100NULL;

};

#endif // T100LOGAPPENDERFILE_H
