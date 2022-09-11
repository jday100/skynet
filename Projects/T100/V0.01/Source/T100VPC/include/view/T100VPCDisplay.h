#ifndef T100VPCDISPLAY_H
#define T100VPCDISPLAY_H

#include <wx/frame.h>
#include "T100Display.h"


class T100VPCDisplay : public T100Display
{
    public:
        T100VPCDisplay(T100QU32*, wxFrame*);
        virtual ~T100VPCDisplay();

        T100BOOL            create();

    protected:
        T100BOOL            OnCreate(void* = T100NULL);

    private:
        wxFrame*            m_parent            = T100NULL;

};

#endif // T100VPCDISPLAY_H
