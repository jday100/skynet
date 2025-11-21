#ifndef T100LEAFSTATE_H
#define T100LEAFSTATE_H

#include "base/T100State.h"

namespace T100LIBRARY{

class T100LeafState : public T100State
{
    public:
        T100LeafState();
        virtual ~T100LeafState();

        T100BOOL            Eof         = T100FALSE;
        T100BOOL            Error       = T100FALSE;

    protected:

    private:
};

}

#endif // T100LEAFSTATE_H
