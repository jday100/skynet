#ifndef T100DEBUGFILEREADER_H
#define T100DEBUGFILEREADER_H

#include "T100FileReader.h"


class T100DebugFileReader : public T100FileReader
{
    public:
        T100DebugFileReader(T100String);
        virtual ~T100DebugFileReader();

    protected:

    private:
};

#endif // T100DEBUGFILEREADER_H
