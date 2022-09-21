#ifndef T100VPCDEBUGFRAME_H
#define T100VPCDEBUGFRAME_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/scrolbar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include "T100Common.h"
class T100QU32;
class T100Port32;
class T100Memory32;


class T100VPCDebugFrame : public wxFrame
{
    friend class T100VPCCallback;
    public:
        T100VPCDebugFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCDebugFrame();

        T100BOOL            load(T100QU32*);
        T100BOOL            save();

    public:
        T100BOOL            OnRegisterUpdate(T100WORD, T100WORD);
        T100BOOL            OnMemoryUpdate(T100WORD, T100WORD);
        T100BOOL            OnPortUpdate(T100WORD, T100WORD);

    protected:
        wxButton*           CallButton;
		wxButton*           NextButton;
		wxButton*           PauseButton;
		wxButton*           CommentButton;
		wxButton*           ReturnButton;
		wxButton*           RunButton;
		wxButton*           StepButton;
		wxComboBox*         AARComboBox;
		wxComboBox*         ABRComboBox;
		wxComboBox*         ACFComboBox;
		wxComboBox*         ACRComboBox;
		wxComboBox*         ADRComboBox;
		wxComboBox*         AMFComboBox;
		wxComboBox*         AOFComboBox;
		wxComboBox*         CBRComboBox;
		wxComboBox*         CCRComboBox;
		wxComboBox*         CORComboBox;
		wxComboBox*         ComboBox12;
		wxComboBox*         ComboBox14;
		wxComboBox*         MemoryOffsetComboBox;
		wxComboBox*         PortOffsetComboBox;
		wxListView*         MemoryListView;
		wxListView*         PortListView;
		wxScrollBar*        MemoryScrollBar;
		wxScrollBar*        PortScrollBar;
		wxStaticText*       StaticText10;
		wxStaticText*       StaticText1;
		wxStaticText*       StaticText2;
		wxStaticText*       StaticText3;
		wxStaticText*       StaticText4;
		wxStaticText*       StaticText5;
		wxStaticText*       StaticText6;
		wxStaticText*       StaticText7;
		wxStaticText*       StaticText8;
		wxStaticText*       StaticText9;

    private:
        static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_COR;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_CBR;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_CCR;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX_AAR;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX_ACF;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX_ABR;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX_AMF;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX_ACR;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX_AOF;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX_ADR;
		static const long ID_COMBOBOX_MEMORY_OFFSET;
		static const long ID_COMBOBOX12;
		static const long ID_LISTVIEW_MEMORY;
		static const long ID_SCROLLBAR_MEMORY;
		static const long ID_COMBOBOX_PORT_OFFSET;
		static const long ID_COMBOBOX14;
		static const long ID_LISTVIEW_PORT;
		static const long ID_SCROLLBAR_PORT;
		static const long ID_BUTTON_RUN;
		static const long ID_BUTTON_STEP;
		static const long ID_BUTTON_NEXT;
		static const long ID_BUTTON_COMMENT;
		static const long ID_BUTTON_CALL;
		static const long ID_BUTTON_RETURN;
		static const long ID_BUTTON_PAUSE;


		void OnCORComboBoxSelected(wxCommandEvent& event);
		void OnCORComboBoxTextUpdated(wxCommandEvent& event);
		void OnCORComboBoxTextEnter(wxCommandEvent& event);
		void OnCBRComboBoxSelected(wxCommandEvent& event);
		void OnCBRComboBoxTextUpdated(wxCommandEvent& event);
		void OnCBRComboBoxTextEnter(wxCommandEvent& event);
		void OnCCRComboBoxSelected(wxCommandEvent& event);
		void OnCCRComboBoxTextUpdated(wxCommandEvent& event);
		void OnCCRComboBoxTextEnter(wxCommandEvent& event);
		void OnAARComboBoxSelected(wxCommandEvent& event);
		void OnAARComboBoxTextUpdated(wxCommandEvent& event);
		void OnAARComboBoxTextEnter(wxCommandEvent& event);
		void OnABRComboBoxSelected(wxCommandEvent& event);
		void OnABRComboBoxTextUpdated(wxCommandEvent& event);
		void OnABRComboBoxTextEnter(wxCommandEvent& event);
		void OnACRComboBoxSelected(wxCommandEvent& event);
		void OnACRComboBoxTextUpdated(wxCommandEvent& event);
		void OnACRComboBoxTextEnter(wxCommandEvent& event);
		void OnADRComboBoxSelected(wxCommandEvent& event);
		void OnADRComboBoxTextUpdated(wxCommandEvent& event);
		void OnADRComboBoxTextEnter(wxCommandEvent& event);
		void OnACFComboBoxSelected(wxCommandEvent& event);
		void OnACFComboBoxTextUpdated(wxCommandEvent& event);
		void OnACFComboBoxTextEnter(wxCommandEvent& event);
		void OnAMFComboBoxSelected(wxCommandEvent& event);
		void OnAMFComboBoxTextUpdated(wxCommandEvent& event);
		void OnAMFComboBoxTextEnter(wxCommandEvent& event);
		void OnAOFComboBoxSelected(wxCommandEvent& event);
		void OnAOFComboBoxTextUpdated(wxCommandEvent& event);
		void OnAOFComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxSelected(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxTextUpdated(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryScrollBarScrollLineDown(wxScrollEvent& event);
		void OnMemoryScrollBarScrollPageUp(wxScrollEvent& event);
		void OnMemoryScrollBarScrollPageDown(wxScrollEvent& event);
		void OnMemoryScrollBarScrollChanged(wxScrollEvent& event);
		void OnPortOffsetComboBoxSelected(wxCommandEvent& event);
		void OnPortOffsetComboBoxTextUpdated(wxCommandEvent& event);
		void OnPortOffsetComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryScrollBarScrollLineUp(wxScrollEvent& event);
		void OnMemoryScrollBarScroll(wxScrollEvent& event);
		void OnMemoryScrollBarScrollTop(wxScrollEvent& event);
		void OnMemoryScrollBarScrollBottom(wxScrollEvent& event);
		void OnPortScrollBarScroll(wxScrollEvent& event);
		void OnPortScrollBarScrollTop(wxScrollEvent& event);
		void OnPortScrollBarScrollBottom(wxScrollEvent& event);
		void OnPortScrollBarScrollLineUp(wxScrollEvent& event);
		void OnPortScrollBarScrollLineDown(wxScrollEvent& event);
		void OnPortScrollBarScrollPageUp(wxScrollEvent& event);
		void OnPortScrollBarScrollPageDown(wxScrollEvent& event);
		void OnPortScrollBarScrollChanged(wxScrollEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnPauseButtonClick(wxCommandEvent& event);
		void OnStepButtonClick(wxCommandEvent& event);
		void OnNextButtonClick(wxCommandEvent& event);
		void OnCommentButtonClick(wxCommandEvent& event);
		void OnCallButtonClick(wxCommandEvent& event);
		void OnReturnButtonClick(wxCommandEvent& event);

    private:
        T100BOOL            init();

        T100BOOL            initMemory();
        T100BOOL            updateMemory(T100Memory32*);
        T100BOOL            updateMemory(T100WORD, T100WORD);

        T100BOOL            initPort();
        T100BOOL            updatePort(T100Port32*);
        T100BOOL            updatePort(T100WORD, T100WORD);



        T100BOOL            init(wxListView*, T100WORD);
        T100BOOL            update(wxListView*, T100WORD, T100WORD);

        T100BOOL            find(wxComboBox*);

    private:
		T100VOID            create();
		T100VOID            destroy();

        T100BOOL            initList();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100VPCDEBUGFRAME_H
