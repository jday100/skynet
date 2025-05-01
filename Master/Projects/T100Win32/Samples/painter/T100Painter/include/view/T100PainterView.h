#ifndef T100PAINTERVIEW_H
#define T100PAINTERVIEW_H

#include "T100Common.h"
#include "T100PainterFrame.h"
#include "T100PainterCanvas.h"
#include "T100PainterMainMenu.h"
#include "T100PainterEntityPanel.h"
#include "gui/dock/T100DockManager.h"

class T100PainterView
{
    public:
        T100PainterView();
        virtual ~T100PainterView();

        T100VOID                    Create();
        T100VOID                    Destroy();

        T100PainterFrame&           GetFrame();
        T100DockManager&            GetDockManager();

    protected:
        T100DockManager             m_dockManager;
        T100PainterFrame            m_frame;
        T100PainterMainMenu         m_mainMenu;

        T100PainterEntityPanel      m_entityPanel;
        T100PainterCanvas           m_canvas;

    private:
};

#endif // T100PAINTERVIEW_H
