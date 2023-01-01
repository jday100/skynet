#ifndef T100DIAGRAMSOURCE_H
#define T100DIAGRAMSOURCE_H

#include "T100DiagramInfo.h"
#include "T100DiagramSourceBase.h"

namespace T100Painter{

class T100DiagramSource : public T100DiagramSourceBase
{
    public:
        T100DiagramSource();
        virtual ~T100DiagramSource();

        T100BOOL            serialize();
        T100BOOL            deserialize();

    protected:

    private:
};

}

#endif // T100DIAGRAMSOURCE_H
