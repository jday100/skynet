#ifndef T100DIAGRAMTRANSDUCERSOURCE_H
#define T100DIAGRAMTRANSDUCERSOURCE_H

#include "T100TransducerSource.h"

class T100DiagramTransducerTarget;

class T100DiagramTransducerSource : public T100TransducerSource
{
    public:
        T100DiagramTransducerSource();
        virtual ~T100DiagramTransducerSource();

        T100VOID            SetTarget(T100TransducerTarget*);

    protected:
        T100DiagramTransducerTarget*        m_target        = T100NULL;

    private:
};

#endif // T100DIAGRAMTRANSDUCERSOURCE_H
