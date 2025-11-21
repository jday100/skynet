#ifndef T100DIAGRAMVIEW_H
#define T100DIAGRAMVIEW_H

#include "T100Common.h"
#include <wx/aui/aui.h>
#include "T100MainMenu.h"
#include "T100DiagramManagerPanel.h"
#include "T100DiagramPropertyPanel.h"
#include "T100Canvas.h"

class T100ElementBase;
class T100DiagramInfo;
class T100DiagramFrame;

class T100DiagramView
{
    public:
        T100DiagramView();
        virtual ~T100DiagramView();

        virtual T100VOID            Create(T100DiagramFrame*);
        virtual T100VOID            Destroy();


        T100VOID                    Position(T100ElementBase*);
        T100VOID                    Edit(T100ElementBase*);
        T100VOID                    Select(T100ElementBase*);

        T100VOID                    Tie(T100ElementBase*);
        T100VOID                    TieStart(T100ElementBase*);
        T100VOID                    TieEnd(T100ElementBase*);

        T100BOOL                    Create();
        T100BOOL                    Open(T100DiagramInfo*);
        T100BOOL                    Append();
        T100BOOL                    Save();

        T100BOOL                    Remove();

        T100BOOL                    Close();

        T100VOID                    Quit();

        T100VOID                    Dirty();

        T100VOID                    CanvasState(T100STRING&);
        T100VOID                    CanvasPosition(T100STRING&);

        T100VOID                    ShowViewManager(T100BOOL);
        T100VOID                    ShowViewProperty(T100BOOL);

        T100BOOL                    ShowOpenFileDialog(T100WSTRING&);
        T100BOOL                    ShowSaveFileDialog(T100WSTRING&);

        T100BOOL                    ShowSourceImportDialog();

        T100VOID                    UpdateTitle(T100BOOL = T100FALSE);

        T100VOID                    Update();

    protected:
        T100WSTRING                 m_projectTitle      = L"T100Diagram";

        wxAuiManager*               m_manager           = T100NULL;
        T100DiagramFrame*           m_frame             = T100NULL;
        T100MainMenu*               m_mainMenu          = T100NULL;
        T100DiagramManagerPanel*    m_managerPanel      = T100NULL;
        T100DiagramPropertyPanel*   m_propertyPanel     = T100NULL;
        T100Canvas*                 m_canvas            = T100NULL;

    private:
};

#endif // T100DIAGRAMVIEW_H
