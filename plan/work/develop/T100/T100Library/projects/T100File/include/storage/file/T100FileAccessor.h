#ifndef T100FILEACCESSOR_H
#define T100FILEACCESSOR_H

#include <fstream>
#include "storage/T100Accessor.h"

namespace T100LIBRARY{

class T100FileAccessor : public T100Accessor
{
    public:
        T100FileAccessor();
        virtual ~T100FileAccessor();

    protected:

    private:
};

}

#endif // T100FILEACCESSOR_H
