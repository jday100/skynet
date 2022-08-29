#ifndef T100LOGAPPENDERFILE_H
#define T100LOGAPPENDERFILE_H

#include <fstream>
#include "T100LogAppender.h"


class T100LogAppenderFile : public T100LogAppender
{
    public:
        T100LogAppenderFile(T100STDSTRING);
        virtual ~T100LogAppenderFile();

        T100VOID            out(T100LOG_TYPE, T100STDSTRING);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100STDSTRING       m_file;
        std::ofstream*      m_ofs       = T100NULL;
};

#endif // T100LOGAPPENDERFILE_H
