#ifndef T100ELEMENTSOURCE_H
#define T100ELEMENTSOURCE_H

#include "T100ElementBase.h"
#include "T100DiagramInfo.h"
#include "T100DiagramTransducerSource.h"

class T100ElementSource : public T100DiagramTransducerSource
{
    public:
        T100ElementSource(T100DiagramInfo*);
        virtual ~T100ElementSource();

        T100BOOL                    serialize();
        T100BOOL                    deserialize();

    protected:

    private:
        T100DiagramInfo*            m_diagram           = T100NULL;
};

#endif // T100ELEMENTSOURCE_H
