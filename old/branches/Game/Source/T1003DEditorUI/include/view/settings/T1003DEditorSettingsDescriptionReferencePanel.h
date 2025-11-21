#ifndef T1003DEDITORSETTINGSDESCRIPTIONREFERENCEPANEL_H
#define T1003DEDITORSETTINGSDESCRIPTIONREFERENCEPANEL_H

#include <atomic>
#include <vector>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"
#include "T1003DEditorDescriptionReferenceData.h"

typedef struct{
    wxPropertyCategory*     Category;
    wxStringProperty*       Name;
    wxUIntProperty*         Amount;
}T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE;

#define     T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE_VECTOR            std::vector<T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE*>

class T1003DEditorSettingsDescriptionReferencePanel : public wxPanel
{
    public:
        T1003DEditorSettingsDescriptionReferencePanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorSettingsDescriptionReferencePanel();

    protected:
        wxPropertyGrid*                     m_gridPtr           = T100NULL;
        wxButton*                           m_buttonSave        = T100NULL;
        wxButton*                           m_buttonAppend      = T100NULL;
        wxButton*                           m_buttonRemove      = T100NULL;

        T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE_VECTOR        m_descriptionReferences;

    protected:
        static const long ID_BUTTON_SAVE;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_REMOVE;

        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonRemoveClick(wxCommandEvent& event);
        void OnButtonSaveClick(wxCommandEvent& event);

        void OnPGChanged(wxPropertyGridEvent& event);

    private:
        std::atomic_int                     m_count;

        T100VOID                            init();
        T100VOID                            uninit();

        T100VOID                            Remove(wxClientData*);

        T100VOID                            Load();
        T100VOID                            Save();

        T100VOID                            Encode(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);
        T100VOID                            Decode(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);
        T100VOID                            DecodeDesc(T1003DEDITOR_SETTINGS_GRID_DATA_DESCRIPTION_REFERENCE*, T1003DEditorDescriptionReferenceData*);

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORSETTINGSDESCRIPTIONREFERENCEPANEL_H
