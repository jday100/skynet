#ifndef T100VIRTUALFILEREADER_H
#define T100VIRTUALFILEREADER_H

#include "T100ExecutableFileReader.h"


class T100VirtualFileReader : public T100ExecutableFileReader
{
    public:
        T100VirtualFileReader(T100STRING);
        virtual ~T100VirtualFileReader();

    protected:

    private:
};

#endif // T100VIRTUALFILEREADER_H
