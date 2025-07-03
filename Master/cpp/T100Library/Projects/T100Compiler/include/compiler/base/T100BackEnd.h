#ifndef T100BACKEND_H
#define T100BACKEND_H

#include "compiler/data/T100BackInfo.h"

namespace T100LIBRARY{

class T100BackEnd : public T100Class
{
    public:
        T100BackEnd();
        virtual ~T100BackEnd();

        virtual T100BOOL            Build(const T100BackInfo&);

    protected:

    private:
};

}

#endif // T100BACKEND_H
