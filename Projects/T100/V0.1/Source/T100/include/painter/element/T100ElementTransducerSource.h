#ifndef T100ELEMENTTRANSDUCERSOURCE_H
#define T100ELEMENTTRANSDUCERSOURCE_H

#include "T100DiagramTransducerSource.h"
#include "T100ElementBase.h"

namespace T100Painter{
class T100ElementTransducerTarget;

class T100ElementTransducerSource : public T100DiagramTransducerSource
{
    public:
        T100ElementTransducerSource();
        virtual ~T100ElementTransducerSource();

        T100VOID        setTarget(T100Library::T100TransducerTarget*);

    protected:
        T100ElementTransducerTarget*        m_target            = T100NULL;

    private:
};

}

#endif // T100ELEMENTTRANSDUCERSOURCE_H
