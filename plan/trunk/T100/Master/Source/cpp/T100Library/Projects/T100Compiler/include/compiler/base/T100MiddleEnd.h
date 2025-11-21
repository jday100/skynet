#ifndef T100MIDDLEEND_H
#define T100MIDDLEEND_H

#include "compiler/data/T100FrontInfo.h"
#include "compiler/data/T100MiddleInfo.h"
#include "compiler/data/T100BackInfo.h"

namespace T100LIBRARY{

class T100MiddleEnd : public T100Class
{
    public:
        T100MiddleEnd();
        virtual ~T100MiddleEnd();

        virtual T100BOOL            Execute(const T100FrontInfo&, T100BackInfo&);

    protected:

    private:
};

}

#endif // T100MIDDLEEND_H
