#ifndef T100CPPTHISAPP_H
#define T100CPPTHISAPP_H

#include "T100Common.h"
#include "T100CPPState.h"

class T100CPPThisApp
{
    public:
        T100CPPThisApp();
        virtual ~T100CPPThisApp();

        T100BOOL            run(T100CPPState&);

    protected:

    private:
};

#endif // T100CPPTHISAPP_H
