#ifndef T100DIAGRAMSOURCE_H
#define T100DIAGRAMSOURCE_H

#include "T100DiagramInfo.h"
#include "T100DiagramSourceBase.h"

class T100DiagramSource : public T100DiagramSourceBase
{
    public:
        T100DiagramSource();
        virtual ~T100DiagramSource();

        T100UINT            GetSign();
        T100UINT            GetType();
        T100UINT            GetVersion();

        T100UINT            GetWidth();
        T100UINT            GetHeight();

        T100BOOL            Serialize();
        T100BOOL            Deserialize();

    protected:

    private:
        T100UINT            m_sign          = 0;
        T100UINT            m_type          = 0;
        T100UINT            m_version       = 0;

        T100UINT            m_width         = 0;
        T100UINT            m_height        = 0;
};

#endif // T100DIAGRAMSOURCE_H
