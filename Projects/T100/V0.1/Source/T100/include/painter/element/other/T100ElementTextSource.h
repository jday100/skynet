#ifndef T100ELEMENTTEXTSOURCE_H
#define T100ELEMENTTEXTSOURCE_H

#include "T100ElementSourceBase.h"
#include "T100ElementText.h"

namespace T100Painter{

class T100ElementTextSource : public T100ElementSourceBase
{
    public:
        T100ElementTextSource(T100ElementText*);
        virtual ~T100ElementTextSource();

        T100BOOL                serialize();
        T100BOOL                deserialize();

    protected:

    private:
        T100ElementText*        m_element           = T100NULL;

};

}

#endif // T100ELEMENTTEXTSOURCE_H
