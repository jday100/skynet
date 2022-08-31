#ifndef T100DEBUGFILEWRITER_H
#define T100DEBUGFILEWRITER_H

#include "T100FileWriter.h"


class T100DebugFileWriter : public T100FileWriter
{
    public:
        T100DebugFileWriter(T100String);
        virtual ~T100DebugFileWriter();

    protected:

    private:
};

#endif // T100DEBUGFILEWRITER_H
