#ifndef T100DIAGRAMFILESOURCE_H
#define T100DIAGRAMFILESOURCE_H

#include "T100DiagramTransducerSource.h"


class T100DiagramFileSource : public T100DiagramTransducerSource
{
    public:
        T100DiagramFileSource();
        virtual ~T100DiagramFileSource();

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

#endif // T100DIAGRAMFILESOURCE_H
