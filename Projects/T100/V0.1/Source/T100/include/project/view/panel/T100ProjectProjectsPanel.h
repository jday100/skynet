#ifndef T100PROJECTPROJECTSPANEL_H
#define T100PROJECTPROJECTSPANEL_H

//(*Headers(T100ProjectProjectsPanel)
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/treectrl.h>
//*)

#include "T100Common.h"


class T100ProjectProjectsPanel: public wxPanel
{
	public:

		T100ProjectProjectsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100ProjectProjectsPanel();

		//(*Declarations(T100ProjectProjectsPanel)
		wxTreeCtrl* TreeCtrlProjects;
		//*)

		T100BOOL            create();

	protected:
        T100VOID            destroy();

		//(*Identifiers(T100ProjectProjectsPanel)
		static const long ID_TREECTRL_PROJECTS;
		//*)

    public:
		static const long ID_TREECTRL_MENUITEM_PROJECT_CREATE;

	private:

		//(*Handlers(T100ProjectProjectsPanel)
		void OnTreeCtrlProjectsBeginDrag(wxTreeEvent& event);
		void OnTreeCtrlProjectsBeginRDrag(wxTreeEvent& event);
		void OnTreeCtrlProjectsEndDrag(wxTreeEvent& event);
		void OnTreeCtrlProjectsBeginLabelEdit(wxTreeEvent& event);
		void OnTreeCtrlProjectsEndLabelEdit(wxTreeEvent& event);
		void OnTreeCtrlProjectsDeleteItem(wxTreeEvent& event);
		void OnTreeCtrlProjectsItemCollapsed(wxTreeEvent& event);
		void OnTreeCtrlProjectsItemCollapsing(wxTreeEvent& event);
		void OnTreeCtrlProjectsItem_bExpanded(wxTreeEvent& event);
		void OnTreeCtrlProjectsItem_bExpanding(wxTreeEvent& event);
		void OnTreeCtrlProjectsItemRightClick(wxTreeEvent& event);
		void OnTreeCtrlProjectsItemMiddleClick(wxTreeEvent& event);
		void OnTreeCtrlProjectsItemMenu(wxTreeEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
