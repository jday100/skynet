#ifndef T100FONTCALLBACK_H
#define T100FONTCALLBACK_H

#include "T100Common.h"

namespace T100FontBuilder{
class T100FontServe;
class T100FontView;


class T100FontCallback
{
    public:
        T100FontCallback();
        virtual ~T100FontCallback();

        static T100VOID             init(T100FontServe*, T100FontView*);

    public:
        static T100BOOL             panel_click(T100VOID* = T100NULL);

    protected:

    private:
        static T100FontServe*       m_serve;
        static T100FontView*        m_view;

};

}

#endif // T100FONTCALLBACK_H
