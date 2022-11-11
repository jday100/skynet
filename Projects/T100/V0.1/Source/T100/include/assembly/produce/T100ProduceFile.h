#ifndef T100PRODUCEFILE_H
#define T100PRODUCEFILE_H

#include "T100AssemblyCommon.h"
#include "T100File.h"

namespace T100Assembly{

class T100ProduceFile : public T100File
{
    public:
        T100ProduceFile(T100STRINT);
        virtual ~T100ProduceFile();

    protected:

    private:
};

}

#endif // T100PRODUCEFILE_H
