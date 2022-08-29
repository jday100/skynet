#ifndef T100IDETEXTDOCUMENT_H
#define T100IDETEXTDOCUMENT_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100EditCtrl.h"


class T100IDETextDocument : public wxDocument
{
    public:
        T100IDETextDocument();
        virtual ~T100IDETextDocument();

        T100BOOL            OnCreate(const wxString& path, long flags);

        T100EditCtrl*       GetEdit() const;

        T100BOOL            IsModified() const;
        T100VOID            Modify(T100BOOL mod);

    protected:
        T100BOOL            DoSaveDocument(const wxString& filename);
        T100BOOL            DoOpenDocument(const wxString& filename);

        T100VOID            OnTextChange(wxCommandEvent& event);

    private:
        wxDECLARE_NO_COPY_CLASS(T100IDETextDocument);
        wxDECLARE_DYNAMIC_CLASS(T100IDETextDocument);
};

#endif // T100IDETEXTDOCUMENT_H
