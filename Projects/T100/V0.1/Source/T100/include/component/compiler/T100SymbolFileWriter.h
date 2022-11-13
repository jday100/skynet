#ifndef T100SYMBOLFILEWRITER_H
#define T100SYMBOLFILEWRITER_H

#include "T100Common.h"
#include "T100String.h"
#include "T100FileWriter.h"

namespace T100Component{

class T100SymbolFileWriter : public T100Library::T100FileWriter
{
    public:
        T100SymbolFileWriter(T100STRING);
        virtual ~T100SymbolFileWriter();

        T100BOOL            write_head();
        T100BOOL            write_variables();
        T100BOOL            write_labels();
        T100BOOL            write_procedures();

    protected:

    private:
};

}

#endif // T100SYMBOLFILEWRITER_H
