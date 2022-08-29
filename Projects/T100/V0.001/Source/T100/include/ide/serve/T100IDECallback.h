#ifndef T100IDECALLBACK_H
#define T100IDECALLBACK_H

#include "T100IDECommon.h"
class T100IDEStore;
class T100IDEServe;
class T100IDEView;


class T100IDECallback
{
    public:
        T100IDECallback();
        virtual ~T100IDECallback();

        static T100BOOL             init(T100IDEStore*, T100IDEServe*, T100IDEView*);

    protected:
        static T100IDEStore*        m_store;
        static T100IDEServe*        m_serve;
        static T100IDEView*         m_view;

    private:

};

#endif // T100IDECALLBACK_H
