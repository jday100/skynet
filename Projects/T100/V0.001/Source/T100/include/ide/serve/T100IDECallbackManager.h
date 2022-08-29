#ifndef T100IDECALLBACKMANAGER_H
#define T100IDECALLBACKMANAGER_H

#include "T100IDECallback.h"


class T100IDECallbackManager : public T100IDECallback
{
    public:
        T100IDECallbackManager();
        virtual ~T100IDECallbackManager();

        static T100BOOL             init(T100IDEStore*, T100IDEServe*, T100IDEView*);

    protected:

    private:

};

#endif // T100IDECALLBACKMANAGER_H
