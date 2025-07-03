#ifndef T100LOADER_H
#define T100LOADER_H

#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Loader : public T100Class
{
    public:
        T100Loader();
        virtual ~T100Loader();

        virtual T100BOOL            Load(const T100WSTRING&);

    protected:

    private:
};

}

#endif // T100LOADER_H
