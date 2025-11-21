#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100Common.h"
#include "T100EditorPanel.h"

class wxFrame;

class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100VOID                SetFrame(wxFrame*);

        T100BOOL                Create();

    protected:
        wxFrame*                m_frame         = T100NULL;
        T100EditorPanel*        m_panel         = T100NULL;

    private:
};

#endif // T100EDITOR_H
