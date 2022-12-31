#ifndef T100TRANSDUCERBASE_H
#define T100TRANSDUCERBASE_H

#include "T100Common.h"
#include "T100TransducerSource.h"
#include "T100TransducerTarget.h"

namespace T100Library{

class T100TransducerBase
{
    public:
        T100TransducerBase();
        virtual ~T100TransducerBase();

        virtual T100BOOL            serialize(T100TransducerSource&, T100TransducerTarget&);

        virtual T100BOOL            deserialize(T100TransducerSource&, T100TransducerTarget&);

    protected:

    private:
};

}

#endif // T100TRANSDUCERBASE_H
