#ifndef T100BUILDER_H
#define T100BUILDER_H

#include "compiler/data/T100BackInfo.h"

namespace T100LIBRARY{

class T100Builder : public T100Class
{
    public:
        T100Builder();
        virtual ~T100Builder();

        virtual T100BOOL            Build(const T100BackInfo&);

    protected:

    private:
};

}

#endif // T100BUILDER_H
