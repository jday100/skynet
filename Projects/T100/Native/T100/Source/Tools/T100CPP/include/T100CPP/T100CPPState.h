#ifndef T100CPPSTATE_H
#define T100CPPSTATE_H

#include "T100AppState.h"

class T100CPPState : public T100AppState
{
    public:
        T100CPPState();
        virtual ~T100CPPState();

        T100BOOL            TEST            = T100FALSE;

    protected:

    private:
};

#endif // T100CPPSTATE_H
