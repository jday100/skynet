#ifndef T100PROJECTSTATEALONE_H
#define T100PROJECTSTATEALONE_H

#include "T100ProjectState.h"

namespace T100PROJECT{

class T100ProjectStateAlone : public T100ProjectState
{
    public:
        T100ProjectStateAlone();
        virtual ~T100ProjectStateAlone();

        T100BOOL                        Create();

        T100VOID                        SetMenu();
        T100VOID                        ResetMenu();

    protected:

    private:
};

}

#endif // T100PROJECTSTATEALONE_H
