#ifndef T100ELEMENTSOURCE_H
#define T100ELEMENTSOURCE_H

#include "T100ElementSourceBase.h"

namespace T100Painter{

class T100ElementSource : public T100ElementSourceBase
{
    public:
        T100ElementSource();
        virtual ~T100ElementSource();

        T100BOOL        serialize();
        T100BOOL        deserialize();

    protected:

    private:
};

}

#endif // T100ELEMENTSOURCE_H
