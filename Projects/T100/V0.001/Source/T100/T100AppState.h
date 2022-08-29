#ifndef T100APPSTATE_H
#define T100APPSTATE_H

#include <wx/cmdline.h>
#include "T100Common.h"


class T100AppState
{
    public:
        T100AppState();
        virtual ~T100AppState();

        T100BOOL            FLAG        = T100FALSE;
        T100BOOL            TEST        = T100FALSE;
        T100BOOL            HELP        = T100FALSE;
        T100BOOL            VPC         = T100FALSE;
        T100BOOL            VDISK       = T100FALSE;
        T100BOOL            VDM         = T100FALSE;
        T100BOOL            FONT        = T100FALSE;
        T100BOOL            IDE         = T100FALSE;
        T100BOOL            ASSEMBLY    = T100FALSE;
        T100BOOL            LOG         = T100FALSE;
        T100BOOL            ERR         = T100FALSE;
        //
        T100BOOL            QUIT        = T100FALSE;
        T100BOOL            LIST        = T100FALSE;
        wxString            INPUT;
        wxString            OUTPUT;
        wxString            FILE;
        wxArrayString       IMPORTS;
        wxString            UNITS;
        wxString            OFFSET;


    protected:

    private:
};

#endif // T100APPSTATE_H
