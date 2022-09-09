#ifndef T100DEBUGFILEWRITER_H
#define T100DEBUGFILEWRITER_H

#include "T100FileWriter.h"
#include "T100ProduceInfo.h"


class T100DebugFileWriter : public T100FileWriter
{
    public:
        T100DebugFileWriter(T100String);
        virtual ~T100DebugFileWriter();

        T100BOOL            write_head();
        T100BOOL            write_variables();
        T100BOOL            write_labels();
        T100BOOL            write_procedures();

    protected:

    private:
};

#endif // T100DEBUGFILEWRITER_H
