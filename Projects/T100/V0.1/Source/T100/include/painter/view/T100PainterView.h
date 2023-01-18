#ifndef T100PAINTERVIEW_H
#define T100PAINTERVIEW_H

#include <wx/window.h>
#include <wx/aui/aui.h>
#include "T100String.h"
#include "T100WxApp.h"
#include "T100PainterCommon.h"
#include "T100PaintCtrl.h"

#include "T100ElementManager.h"

#include "T100PainterElementsPanel.h"
#include "T100PainterPropertiesPanel.h"

#include "T100DiagramInfo.h"

namespace T100Painter{
class T100PainterFrame;


class T100PainterView
{
    public:
        T100PainterView();
        virtual ~T100PainterView();

        T100VOID        setCallback(wxFrame*, T100WxWidgets::T100FRAME_CALLBACK);

        T100BOOL                create_alone();

        T100BOOL                create_embed();

        T100BOOL                OpenFile(T100STRING&);

        T100BOOL                CloseFile();

        T100BOOL                LoadFile(T100DiagramInfo*);

        T100BOOL                Save();

        T100BOOL                SaveAsFile(T100STRING&);

        T100BOOL                Quit();

        T100BOOL                UpdateMenu();

        T100BOOL                ShowElements();
        T100BOOL                ShowProperties();

        T100BOOL                Append(wxString, T100ElementBase*);

        T100ElementManager*     getElementManager();

        T100WxWidgets::T100PaintCtrl*       getPaintCtrl();

        T100VOID                            setElementsPanel(T100PainterElementsPanel*);
        T100PainterElementsPanel*           getElementsPanel();

        T100VOID                            setPropertiesPanel(T100PainterPropertiesPanel*);
        T100PainterPropertiesPanel*         getPropertiesPanel();

    public:
        T100VOID                setParent(wxWindow*);
        T100VOID                setRootFrame(wxFrame*);

        T100VOID                setMenu(wxFrame*);

        T100VOID                setManager(wxAuiManager*);


        T100BOOL                create();

        T100VOID                show();

    protected:
        T100VOID                destroy();

    private:
        wxWindow*               m_parent            = T100NULL;
        wxAuiManager*           m_manager           = T100NULL;
        T100ElementManager*     m_elements          = T100NULL;
        T100PainterFrame*       m_frame             = T100NULL;
        wxFrame*                m_root              = T100NULL;

        T100WxWidgets::T100PaintCtrl*       m_paint                 = T100NULL;

        T100PainterElementsPanel*           m_elements_panel        = T100NULL;
        T100PainterPropertiesPanel*         m_properties_panel      = T100NULL;

        wxFrame*                            m_callback_frame        = T100NULL;
        T100WxWidgets::T100FRAME_CALLBACK   m_callback              = T100NULL;

};

}

#endif // T100PAINTERVIEW_H
