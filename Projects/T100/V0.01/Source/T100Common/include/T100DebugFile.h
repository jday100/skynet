#ifndef T100DEBUGFILE_H
#define T100DEBUGFILE_H

#include "T100File.h"
class T100DebugFileReader;
class T100DebugFileWriter;


class T100DebugFile : public T100File
{
    public:
        T100DebugFile(T100String);
        virtual ~T100DebugFile();

        T100DebugFileReader*            getReader();
        T100DebugFileWriter*            getWriter();

    protected:

    private:
};

#endif // T100DEBUGFILE_H
