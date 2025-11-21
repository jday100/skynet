#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100EditorPanel.h"

class wxFrame;

class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        void                Create(wxFrame* frame);

        void                Open();

    protected:
        wxFrame*            m_frame         = nullptr;
        T100EditorPanel*    m_panel         = nullptr;

    private:
};

#endif // T100EDITOR_H
