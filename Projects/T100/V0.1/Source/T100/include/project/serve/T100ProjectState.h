#ifndef T100PROJECTSTATE_H
#define T100PROJECTSTATE_H

#include "T100State.h"

namespace T100PROJECT{

class T100ProjectState : public T100Component::T100State
{
    public:
        T100ProjectState();
        virtual ~T100ProjectState();

        virtual T100BOOL                        Create() = 0;

        virtual T100VOID                        SetMenu() = 0;
        virtual T100VOID                        ResetMenu() = 0;

    protected:

    private:
};

}

#endif // T100PROJECTSTATE_H
