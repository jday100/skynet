#ifndef T100ELEMENTBASE_H
#define T100ELEMENTBASE_H

#include <wx/listctrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/dc.h>
#include "T100Common.h"
#include "T100String.h"
#include "T100PainterCanvas.h"

namespace T100Painter{

class T100ElementBase
{
    friend class T100ElementSource;
    public:
        T100ElementBase();
        virtual ~T100ElementBase();

        T100VOID                    setLabel(T100STRING);
        T100STRING                  getName();
        T100STRING                  getLabel();
        T100STRING                  getKey();
        T100STRING                  getPanel();
        T100WORD                    getType();


        virtual T100BOOL            Append(wxListView*);
        virtual T100BOOL            Update(wxPropertyGrid*);
        virtual T100BOOL            Update(wxPropertyGridEvent&);
        virtual T100VOID            Clear() = 0;

        virtual T100BOOL            draw(wxDC&) = 0;
        virtual T100ElementBase*    Clone() = 0;
        virtual T100BOOL            Hit(T100INT, T100INT) = 0;

        virtual T100BOOL            MouseLeftDown(T100INT, T100INT);
        virtual T100BOOL            MouseLeftUp(T100INT, T100INT);
        virtual T100BOOL            MouseMove(T100INT, T100INT);

        virtual T100BOOL            Move(T100INT, T100INT);

    protected:
        T100STRING                  m_name;
        T100STRING                  m_label;
        T100STRING                  m_key;
        T100STRING                  m_panel;

        T100WORD                    m_type          = 0;

    private:
        T100WORD                    m_starting_x    = 0;
        T100WORD                    m_starting_y    = 0;
        T100WORD                    m_ending_x      = 0;
        T100WORD                    m_ending_y      = 0;

};

}

#endif // T100ELEMENTBASE_H
