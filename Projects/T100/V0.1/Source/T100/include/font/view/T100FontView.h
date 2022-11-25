#ifndef T100FONTVIEW_H
#define T100FONTVIEW_H

#include "T100Common.h"

namespace T100FontBuilder{
class T100FontFrame;

class T100FontView
{
    public:
        T100FontView();
        virtual ~T100FontView();

        T100BOOL            init();
        T100BOOL            show();
        T100BOOL            quit();

        T100FontFrame*      getFrame();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100FontFrame*      m_frame             = T100NULL;

};

}

#endif // T100FONTVIEW_H
