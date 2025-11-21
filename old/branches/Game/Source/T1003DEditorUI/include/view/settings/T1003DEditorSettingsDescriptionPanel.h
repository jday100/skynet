#ifndef T1003DEDITORSETTINGSDESCRIPTIONPANEL_H
#define T1003DEDITORSETTINGSDESCRIPTIONPANEL_H

#include <atomic>
#include <vector>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"
#include "T1003DEditorDescriptionFile.h"

typedef struct{
    wxPropertyCategory*     Category;
    wxStringProperty*       Name;
    wxUIntProperty*         Index;
    wxEnumProperty*         Format;
    wxUIntProperty*         Slot;
    wxUIntProperty*         Offset;
    wxEnumProperty*         InputClass;
    wxUIntProperty*         Rate;
}T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION;

#define     T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_VECTOR           std::vector<T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*>

class T1003DEditorSettingsDescriptionPanel : public wxPanel
{
    public:
        T1003DEditorSettingsDescriptionPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorSettingsDescriptionPanel();

    protected:
        wxPropertyGrid*                     m_gridPtr           = T100NULL;
        wxButton*                           m_buttonSave        = T100NULL;
        wxButton*                           m_buttonAppend      = T100NULL;
        wxButton*                           m_buttonRemove      = T100NULL;

        T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_VECTOR       m_descs;

    protected:
        static const long ID_BUTTON_SAVE;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_REMOVE;

        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonRemoveClick(wxCommandEvent& event);
        void OnButtonSaveClick(wxCommandEvent& event);

    private:
        std::atomic_int                     m_count;

        T100VOID                            init();
        T100VOID                            uninit();

        T100VOID                            SetClientData(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*);
        T100VOID                            Remove(wxClientData*);
        T100VOID                            RemoveDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*);


        T100VOID                            Load();
        T100VOID                            Save();

        T100VOID                            Encode(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);
        T100VOID                            EncodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*, T100D3D12_INPUT_ELEMENT_DESC*);

        T100VOID                            Decode(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);
        T100VOID                            DecodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION*, T100D3D12_INPUT_ELEMENT_DESC*);

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSETTINGSDESCRIPTIONPANEL_H
