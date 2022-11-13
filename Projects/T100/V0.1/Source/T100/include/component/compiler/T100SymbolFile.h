#ifndef T100SYMBOLFILE_H
#define T100SYMBOLFILE_H

#include "T100File.h"
#include "T100SymbolFileReader.h"
#include "T100SymbolFileWriter.h"

namespace T100Component{

class T100SymbolFile : public T100Library::T100File
{
    public:
        T100SymbolFile(T100STRING);
        virtual ~T100SymbolFile();

        T100SymbolFileReader*           getReader();
        T100SymbolFileWriter*           getWriter();

    protected:

    private:
};

}

#endif // T100SYMBOLFILE_H
