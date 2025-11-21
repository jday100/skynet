#ifndef T100TRANSDUCERBASE_H
#define T100TRANSDUCERBASE_H

#include "T100TransducerSource.h"
#include "T100TransducerTarget.h"

class T100TransducerBase
{
    public:
        T100TransducerBase();
        virtual ~T100TransducerBase();

        virtual T100BOOL            Serialize(T100TransducerSource&, T100TransducerTarget&);
        virtual T100BOOL            Deserialize(T100TransducerSource&, T100TransducerTarget&);

    protected:

    private:
};

#endif // T100TRANSDUCERBASE_H
