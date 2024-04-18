#ifndef T100DIAGRAMTRANSDUCERSOURCE_H
#define T100DIAGRAMTRANSDUCERSOURCE_H

#include "T100Common.h"
#include "T100DiagramCommon.h"
class T100DiagramTransducerTarget;

class T100DiagramTransducerSource
{
    public:
        T100DiagramTransducerSource();
        virtual ~T100DiagramTransducerSource();

        virtual T100VOID                    setTarget(T100DiagramTransducerTarget*);

        virtual T100BOOL                    serialize();
        virtual T100BOOL                    deserialize();

    protected:
        T100DiagramTransducerTarget*        m_target            = T100NULL;

    private:
};

#endif // T100DIAGRAMTRANSDUCERSOURCE_H
