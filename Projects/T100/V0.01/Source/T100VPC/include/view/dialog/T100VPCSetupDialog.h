#ifndef T100VPCSETUPDIALOG_H
#define T100VPCSETUPDIALOG_H

#include <wx/dialog.h>
#include <wx/sizer.h>
#include "T100Common.h"


class T100VPCSetupDialog : public wxDialog
{
    public:
        T100VPCSetupDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCSetupDialog();

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            load();
        T100BOOL            save();


    protected:
		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCSETUPDIALOG_H
