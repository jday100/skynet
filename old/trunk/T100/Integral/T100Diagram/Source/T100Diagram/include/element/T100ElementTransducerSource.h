#ifndef T100ELEMENTTRANSDUCERSOURCE_H
#define T100ELEMENTTRANSDUCERSOURCE_H

#include "T100ElementBase.h"
#include "T100DiagramTransducerSource.h"

class T100ElementTransducerTarget;

class T100ElementTransducerSource : public T100DiagramTransducerSource
{
    public:
        T100ElementTransducerSource();
        virtual ~T100ElementTransducerSource();

        T100VOID            SetTarget(T100TransducerTarget*);

    protected:
        T100ElementTransducerTarget*        m_target        = T100NULL;

    private:
};

#endif // T100ELEMENTTRANSDUCERSOURCE_H
