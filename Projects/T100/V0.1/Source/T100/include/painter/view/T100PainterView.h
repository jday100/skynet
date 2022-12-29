#ifndef T100PAINTERVIEW_H
#define T100PAINTERVIEW_H

#include <wx/window.h>
#include "T100String.h"
#include "T100PainterCommon.h"
#include "T100PaintCtrl.h"

namespace T100Painter{
class T100PainterFrame;


class T100PainterView
{
    public:
        T100PainterView();
        virtual ~T100PainterView();

        T100BOOL                NewFile();
        T100BOOL                OpenFile(T100STRING&);
        T100BOOL                LoadFile(T100PAINTER_ELEMENT_VECTOR*);
        T100BOOL                SaveFile();
        T100BOOL                SaveAsFile();
        T100BOOL                CloseFile();

    public:
        T100VOID                setParent(wxWindow*);

        T100BOOL                create();

        T100VOID                show();

    protected:
        T100VOID                destroy();

    private:
        wxWindow*               m_parent            = T100NULL;
        T100PainterFrame*       m_frame             = T100NULL;
        T100WxWidgets::T100PaintCtrl*       m_paint             = T100NULL;

};

}

#endif // T100PAINTERVIEW_H
