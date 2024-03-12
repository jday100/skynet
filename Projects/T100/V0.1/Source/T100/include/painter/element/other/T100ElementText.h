#ifndef T100ELEMENTTEXT_H
#define T100ELEMENTTEXT_H

#include <wx/window.h>
#include <wx/caret.h>
#include <wx/propgrid/propgrid.h>
#include "T100ElementBase.h"

namespace T100Painter{

class T100ElementText : public T100ElementBase
{
    friend class T100ElementTextSource;
    public:
        T100ElementText();
        virtual ~T100ElementText();

        T100VOID            Clear();
        T100BOOL            draw(wxDC&);
        T100ElementText*    Clone();

        T100BOOL            Hit(T100INT, T100INT);
        T100BOOL            Edit();

        T100BOOL            Update(wxPropertyGrid*);
        T100BOOL            Update(wxPropertyGridEvent&);

        T100VOID            Resize(wxDC&);

        T100BOOL            SetPaintStarting(T100INT, T100INT);

        T100BOOL            PaintMove(T100INT, T100INT);
        T100BOOL            SelectedMove(T100INT, T100INT);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        wxCaret*                    m_caret             = T100NULL;
        wxLongStringProperty*       m_pg_name           = T100NULL;

};

}

#endif // T100ELEMENTTEXT_H
