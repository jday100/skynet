#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100Common.h"
#include "main.h"

class T100MainFrame;
class T100EditorPanel;

class DLL_EXPORT T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100VOID                Init(T100MainFrame*);
        T100VOID                Uninit();

        T100BOOL                Create();

    protected:
        T100MainFrame*          m_frame         = T100NULL;
        T100EditorPanel*        m_panel         = T100NULL;

    private:
        T100VOID                MainMenu();
};

#endif // T100EDITOR_H
