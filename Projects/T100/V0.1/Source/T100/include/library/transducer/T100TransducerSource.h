#ifndef T100TRANSDUCERSOURCE_H
#define T100TRANSDUCERSOURCE_H

#include "T100Common.h"

namespace T100Library{
class T100TransducerTarget;

class T100TransducerSource
{
    public:
        T100TransducerSource();
        virtual ~T100TransducerSource();

        virtual T100VOID            setTarget(T100TransducerTarget*);

        virtual T100BOOL            serialize();
        virtual T100BOOL            deserialize();

    protected:
        T100TransducerTarget*       m_target            = T100NULL;

    private:

};

}

#endif // T100TRANSDUCERSOURCE_H
