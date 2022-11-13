#ifndef T100SYMBOLFILEREADER_H
#define T100SYMBOLFILEREADER_H

#include "T100Common.h"
#include "T100String.h"
#include "T100FileReader.h"

namespace T100Component{

class T100SymbolFileReader : public T100Library::T100FileReader
{
    public:
        T100SymbolFileReader(T100STRING);
        virtual ~T100SymbolFileReader();

    protected:

    private:
};

}

#endif // T100SYMBOLFILEREADER_H
