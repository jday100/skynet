#ifndef T100FONTVIEW_H
#define T100FONTVIEW_H

#include "IView.h"
#include "T100FontFrame.h"


class T100FontView : public IView
{
    public:
        T100FontView();
        virtual ~T100FontView();

        T100VOID            create();

        T100VOID            setFrame(T100FontFrame*);
        T100FontFrame*      getFrame();

        T100BOOL            show();

        T100BOOL            start();

    protected:
        T100VOID            destroy();

    private:
        T100FontFrame*      m_frame         = T100NULL;
};

#endif // T100FONTVIEW_H
