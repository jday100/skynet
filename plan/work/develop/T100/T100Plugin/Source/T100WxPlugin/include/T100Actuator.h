#ifndef T100ACTUATOR_H
#define T100ACTUATOR_H

#include <wx/event.h>

#include "T100Editor.h"

class wxFrame;

class T100Actuator : public wxEvtHandler
{
    public:
        T100Actuator();
        virtual ~T100Actuator();

        void            Create(wxFrame*);

        void            OnFileNew(wxCommandEvent&);

    protected:
        T100Editor      m_editor;

    private:
};

#endif // T100ACTUATOR_H
