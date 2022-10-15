#ifndef T100EXECUTABLEFILEREADER_H
#define T100EXECUTABLEFILEREADER_H

#include "T100Common.h"
#include "T100FileReader.h"
#include "T100ExecutableInfo.h"


class T100ExecutableFileReader : public T100FileReader
{
    public:
        T100ExecutableFileReader(T100STRING);
        virtual ~T100ExecutableFileReader();

        T100BOOL            load(T100ExecutableInfo&);

    protected:

    private:
};

#endif // T100EXECUTABLEFILEREADER_H
