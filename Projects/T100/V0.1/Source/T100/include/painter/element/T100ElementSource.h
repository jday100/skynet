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

        T100WORD        getType();

    protected:

    private:
        T100WORD        m_type          = 0;

};

}

#endif // T100ELEMENTSOURCE_H
