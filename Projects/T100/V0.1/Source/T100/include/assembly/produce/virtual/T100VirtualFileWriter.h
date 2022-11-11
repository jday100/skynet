#ifndef T100VIRTUALFILEWRITER_H
#define T100VIRTUALFILEWRITER_H

#include "T100Common.h"
#include "T100VirtualInfo.h"
#include "T100ExecutableFileWriter.h"

namespace T100Assembly{

class T100VirtualFileWriter : public T100ExecutableFileWriter
{
    public:
        T100VirtualFileWriter(T100STRING);
        virtual ~T100VirtualFileWriter();

        T100BOOL            save(T100VirtualInfo&);

    protected:

    private:
};

}

#endif // T100VIRTUALFILEWRITER_H
