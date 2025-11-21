#ifndef T1003DEDITORSETTINGSSHADERREFERENCEPANEL_H
#define T1003DEDITORSETTINGSSHADERREFERENCEPANEL_H

#include <atomic>
#include <vector>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"

class T1003DEditorSettingsShaderReferencePanel : public wxPanel
{
    public:
        T1003DEditorSettingsShaderReferencePanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorSettingsShaderReferencePanel();

    protected:
        wxPropertyGrid*                     m_gridPtr           = T100NULL;
        wxButton*                           m_buttonSave        = T100NULL;
        wxButton*                           m_buttonAppend      = T100NULL;
        wxButton*                           m_buttonRemove      = T100NULL;

    protected:
        static const long ID_BUTTON_SAVE;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_REMOVE;

        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonRemoveClick(wxCommandEvent& event);
        void OnButtonSaveClick(wxCommandEvent& event);

    private:
        std::atomic_int                     m_count;
        T100STRING                          m_name      = "./config/shader.json";

        T100VOID                            init();
        T100VOID                            uninit();

        T100VOID                            Load();
        T100VOID                            Save();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSETTINGSSHADERREFERENCEPANEL_H
