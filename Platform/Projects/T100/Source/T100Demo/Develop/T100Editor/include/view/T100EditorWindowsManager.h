#ifndef T100EDITORWINDOWSMANAGER_H
#define T100EDITORWINDOWSMANAGER_H

#include <vector>
#include "T100Common.h"
#include "T100MainPanel.h"
#include "T100EditorCtrl.h"

#define     T100EDITOR_CTRL_VECTOR          std::vector<T100EditorCtrl*>

class T100EditorWindowsManager
{
    public:
        T100EditorWindowsManager(T100MainPanel*);
        virtual ~T100EditorWindowsManager();

        T100BOOL                    renew();
        T100EditorCtrl*             getCurrent();

        T100BOOL                    quit();

    protected:

    private:
        T100MainPanel*              m_parent            = T100NULL;
        T100EDITOR_CTRL_VECTOR      m_windows;
        T100EditorCtrl*             m_current           = T100NULL;
};

#endif // T100EDITORWINDOWSMANAGER_H
