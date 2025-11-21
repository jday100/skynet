#ifndef T100FONTPANEL_H
#define T100FONTPANEL_H

#include "gui/T100Panel.h"

using namespace T100WINDOWS;

class T100FontPanel : public T100Panel
{
    public:
        T100FontPanel();
        virtual ~T100FontPanel();

        virtual T100VOID            Create(T100Window*, T100PanelStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100FONTPANEL_H
