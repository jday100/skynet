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

        T100WORD            getSign();
        T100WORD            getType();
        T100WORD            getVersion();

    protected:

    private:
        T100WORD            m_sign          = 0;
        T100WORD            m_type          = 0;
        T100WORD            m_version       = 0;

};

}

#endif // T100DIAGRAMSOURCE_H
