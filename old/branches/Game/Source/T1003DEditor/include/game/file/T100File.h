#ifndef T100FILE_H
#define T100FILE_H

#include <vector>
#include "T100Common.h"

typedef struct T100FILE_DATA{
    T100BYTE*       Data        = T100NULL;
    T100INT32       Length      = -1;
}T100FILE_DATA;

#define     T100BYTE_VECTOR         std::vector<T100BYTE>

class T100File
{
    public:
        T100File();
        virtual ~T100File();

    protected:

    private:
};

#endif // T100FILE_H
